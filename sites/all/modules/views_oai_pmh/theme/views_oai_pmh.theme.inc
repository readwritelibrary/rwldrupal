<?php

/**
 * @file
 * Theme related functions for processing our output style plugins.
 *
 * Views bug: http://drupal.org/node/593336
 */

function theme_views_oai_pmh_row_dc_fields(&$vars) {
  $view = $vars['view'];

  // Loop through the fields for this view.
  $previous_inline = FALSE;
  $vars['fields'] = array(); // ensure it's at least an empty array.
  $row_index = $view->row_index;
  foreach ($view->field as $id => $field) {
    // render this even if set to exclude so it can be used elsewhere.
    $field_output = $view->style_plugin->get_field($row_index, $id);
    $empty = $field_output !== 0 && empty($field_output);
    if (empty($field->options['exclude']) && (!$empty || (empty($field->options['hide_empty']) && empty($vars['options']['hide_empty'])))) {
      $key = check_plain(_views_oai_pmh_xml_tag_clean($view->field[$id]->label()));
      if (isset($field->multiple)) {
        $separator = $field->options['separator'];
        foreach (explode($separator, $field_output) as $value) {
          $item['key'] = $key;
          $item['value'] = $value;
          $items[] = $item;
        }
      }
      else {
        $item['key'] = $key;
        $item['value'] = $field_output;
        $items[] = $item;
      }
    }
  }
 return format_xml_elements($items);

}

function template_preprocess_views_oai_pmh_response(&$vars) {
  global $base_url;

  $vars['oai_response_date'] = format_xml_elements(array('responseDate' => $vars['oai_args']['response_date']));
  $request = array('key' => 'request',
        					 'value' => $base_url);
  $request += !empty($vars['oai_args']['verb']) ?
                array('attributes' => array('verb' => $vars['oai_args']['verb'])): array();
  $vars['oai_request'] = format_xml_elements(array($request));
  $vars['oai_verb'] = !empty($vars['oai_args']['verb']) ? $vars['oai_args']['verb']: '';
  $vars['oai_base_url'] = $base_url;
  $vars['oai_errors'] = format_xml_elements($vars['oai_args']['errors']);

  $vars['oai_content'] = $vars['oai_content'];
  if (!empty($vars['oai_content'])) {
    $vars['oai_resumption_token'] = $vars['resumption_token'];
  }
}

function theme_views_oai_pmh_identify_body(&$vars) {
  global $base_url;
  $view = $vars['view'];
  $path = $view->display_handler->get_path();
  $datestamp = db_query("SELECT min(changed) FROM {node} ")->fetchField();

  $ident = array(
  	'repositoryName' => variable_get('site_name', 'Views OAI'),
    'baseURL' => $base_url . '/' . $path,
    'protocolVersion' => '2.0',
    'adminEmail' => variable_get('site_mail', ini_get('sendmail_from')),
    'earliestDatestamp' => gmstrftime('%Y-%m-%dT%H:%M:%SZ', $datestamp),
    'deletedRecord' => 'no',
    'granularity' => 'YYYY-MM-DDThh:mm:ssZ',
    'compression' => 'yes',
  );

  return format_xml_elements($ident);
}

function theme_views_oai_pmh_metadataformats_body(&$vars) {
  $formats = '';
  $formats .= format_xml_elements(array ('metadataFormat' => array(
  	'metadataPrefix' => 'oai_dc',
    'schema' => 'http://www.openarchives.org/OAI/2.0/oai_dc.xsd',
    'metadataNamespace' => 'http://www.openarchives.org/OAI/2.0/oai_dc/',
  )));
  return $formats;
}

function theme_views_oai_pmh_record_header($vars) {
  global $base_url;
  static $parts = array();
  if (empty($parts)) {
    $parts = parse_url($base_url);
  }
  $nid = $vars['nid'];
  $datestamp = $vars['node_changed'];

  $info['header']['identifier'] = 'oai:' . $parts['host'] . ':' . $nid;
  $info['header']['datestamp'] = gmstrftime('%Y-%m-%dT%H:%M:%SZ', $datestamp);
//  $info['header']['setSpec'] = '';

  return format_xml_elements($info);
}

function theme_views_oai_pmh_dc_record(&$vars) {
  $nid = $vars['nid'];
  $datestamp = $vars['node_changed'];
  $header = theme('views_oai_pmh_record_header', array('nid' => $nid, 'node_changed' => $datestamp));

  return '<record>' .
    $header .
    '<metadata>
      <oai_dc:dc  xmlns:oai_dc="http://www.openarchives.org/OAI/2.0/oai_dc/"
                      xmlns:dc="http://purl.org/dc/elements/1.1/"
                      xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                      xsi:schemaLocation="http://www.openarchives.org/OAI/2.0/oai_dc/  http://www.openarchives.org/OAI/2.0/oai_dc.xsd">' .
      $vars['fields'] .
      '</oai_dc:dc>
    </metadata>
   </record>';
}


/**
 * Returns a valid XML tag formed from the given input.
 *
 * @param $tag The string that should be made into a valid XML tag.
 * @return The valid XML tag or an empty string if the string contained no valid
 * XML tag characters.
 */
function _views_oai_pmh_xml_tag_clean($tag) {

  // This regex matches characters that are not valid in XML tags, and the
  // unicode ones that are. We don't bother with unicode, because it would so
  // the preg_replace down a lot.
  static $invalid_tag_chars_regex = '#[^\:A-Za-z_\-.0-9]+#';

  // These characters are not valid at the start of an XML tag:
  static $invalid_start_chars = '-.0123456789';

  // Convert invalid chars to '-':
  $tag = preg_replace($invalid_tag_chars_regex, '-', $tag);

  // Need to trim invalid characters from the start of the string:
  $tag = ltrim($tag, $invalid_start_chars);

  return $tag;
}

function theme_oai_field_mapper_form($variables) {
  $form = $variables['form'];
  foreach (element_children($form) as $key ) {
      $rows[] = array(
        drupal_render($form[$key]['drupal_label']),
        drupal_render($form[$key])
      );
  }
  $header = array(
    t('Drupal field label'),
    t('Dublin Core element name')
  );
  $output = theme('table', array('header' => $header, 'rows' => $rows));

  $output .= drupal_render_children($form);
  return $output;

}