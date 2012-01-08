<?php

function views_oai_pmh_views_default_views() {

  $view = new view;
  $view->name = 'oai_biblio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biblio OAI-PMH';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'dc:title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Biblio: Authors */
  $handler->display->display_options['fields']['biblio_authors']['id'] = 'biblio_authors';
  $handler->display->display_options['fields']['biblio_authors']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_authors']['field'] = 'biblio_authors';
  $handler->display->display_options['fields']['biblio_authors']['label'] = 'dc:creator';
  $handler->display->display_options['fields']['biblio_authors']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_authors']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_authors']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_authors']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_authors']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_authors']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['biblio_label'] = 0;
  $handler->display->display_options['fields']['biblio_authors']['auth_category'] = '0';
  $handler->display->display_options['fields']['biblio_authors']['auth_links'] = 0;
  /* Field: Biblio: Corporate Authors */
  $handler->display->display_options['fields']['biblio_corp_authors']['id'] = 'biblio_corp_authors';
  $handler->display->display_options['fields']['biblio_corp_authors']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_corp_authors']['field'] = 'biblio_corp_authors';
  $handler->display->display_options['fields']['biblio_corp_authors']['label'] = 'dc:creator';
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_corp_authors']['biblio_label'] = 1;
  $handler->display->display_options['fields']['biblio_corp_authors']['auth_category'] = '5';
  /* Field: Biblio: DOI */
  $handler->display->display_options['fields']['biblio_doi']['id'] = 'biblio_doi';
  $handler->display->display_options['fields']['biblio_doi']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_doi']['field'] = 'biblio_doi';
  $handler->display->display_options['fields']['biblio_doi']['label'] = 'dc:identifier';
  $handler->display->display_options['fields']['biblio_doi']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_doi']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_doi']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_doi']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_doi']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_doi']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_doi']['biblio_label'] = 1;
  /* Field: Biblio: ISBN Number */
  $handler->display->display_options['fields']['biblio_isbn']['id'] = 'biblio_isbn';
  $handler->display->display_options['fields']['biblio_isbn']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_isbn']['field'] = 'biblio_isbn';
  $handler->display->display_options['fields']['biblio_isbn']['label'] = 'dc:identifier';
  $handler->display->display_options['fields']['biblio_isbn']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_isbn']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_isbn']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_isbn']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_isbn']['biblio_label'] = 1;
  /* Field: Biblio: Publisher */
  $handler->display->display_options['fields']['biblio_publisher']['id'] = 'biblio_publisher';
  $handler->display->display_options['fields']['biblio_publisher']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_publisher']['field'] = 'biblio_publisher';
  $handler->display->display_options['fields']['biblio_publisher']['label'] = 'dc:publisher';
  $handler->display->display_options['fields']['biblio_publisher']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_publisher']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_publisher']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_publisher']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_publisher']['biblio_label'] = 1;
  /* Field: Biblio: Secondary Title */
  $handler->display->display_options['fields']['biblio_secondary_title']['id'] = 'biblio_secondary_title';
  $handler->display->display_options['fields']['biblio_secondary_title']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_secondary_title']['field'] = 'biblio_secondary_title';
  $handler->display->display_options['fields']['biblio_secondary_title']['label'] = 'dc:source';
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_secondary_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_secondary_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_secondary_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_secondary_title']['biblio_label'] = 0;
  /* Field: Biblio: URL */
  $handler->display->display_options['fields']['biblio_url']['id'] = 'biblio_url';
  $handler->display->display_options['fields']['biblio_url']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_url']['field'] = 'biblio_url';
  $handler->display->display_options['fields']['biblio_url']['label'] = 'dc:identifier';
  $handler->display->display_options['fields']['biblio_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_url']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_url']['biblio_label'] = 1;
  /* Field: Biblio: Year of Publication */
  $handler->display->display_options['fields']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['label'] = 'dc:date';
  $handler->display->display_options['fields']['biblio_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['biblio_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_year']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_year']['biblio_label'] = 0;
  /* Field: Biblio: Abstract */
  $handler->display->display_options['fields']['biblio_abst_e']['id'] = 'biblio_abst_e';
  $handler->display->display_options['fields']['biblio_abst_e']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_abst_e']['field'] = 'biblio_abst_e';
  $handler->display->display_options['fields']['biblio_abst_e']['label'] = 'dc:description';
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_abst_e']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_abst_e']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_abst_e']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_abst_e']['biblio_label'] = 0;
  /* Field: Biblio: Publication Language */
  $handler->display->display_options['fields']['biblio_lang']['id'] = 'biblio_lang';
  $handler->display->display_options['fields']['biblio_lang']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_lang']['field'] = 'biblio_lang';
  $handler->display->display_options['fields']['biblio_lang']['label'] = 'dc:language';
  $handler->display->display_options['fields']['biblio_lang']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['external'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_lang']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_lang']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_lang']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['biblio_lang']['hide_empty'] = 1;
  $handler->display->display_options['fields']['biblio_lang']['empty_zero'] = 0;
  $handler->display->display_options['fields']['biblio_lang']['biblio_label'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: OAI-PMH 2 */
  $handler = $view->new_display('views_oai_pmh', 'OAI-PMH', 'views_oai_pmh_biblio');
  $handler->display->display_options['style_plugin'] = 'views_oai_pmh_dc';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dc';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'oai';
  $translatables['oai_biblio'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('dc:title'),
  t('dc:creator'),
  t('dc:identifier'),
  t('dc:publisher'),
  t('dc:source'),
  t('dc:date'),
  t('dc:description'),
  t('dc:language'),
  t('OAI-PMH 2'),
  );

  return array('oai_biblio' => $view);

}