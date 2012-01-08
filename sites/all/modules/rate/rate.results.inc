<?php
// $Id: rate.results.inc,v 1.4.2.1 2011/01/12 23:05:21 mauritsl Exp $

/**
 * @file
 * Function to generate rate results page.
 */

/**
 * Generate the rate results page.
 *
 * @param object $node
 * @return string
 */
function rate_results_page($node) {
  $output = '';

  $widgets = rate_get_active_widgets('node', $node->type);
  foreach ($widgets as $widget) {
    $output .= '<h3>' . check_plain($widget->title) . '</h3>';
    $votingapi_results = votingapi_select_results(array(
      'entity_type' => 'node',
      'entity_id' => $node->nid,
      'tag' => $widget->tag,
      'value_type' => $widget->value_type,
    ));
    $count = 0;
    $average = 0;
    $sum = 0;
    foreach ($votingapi_results as $result) {
      ${$result['function']} = $result['value'];
    }
    $output .= '<p>';
    $output .= t('Vote count: @count', array('@count' => $count)) . ' ';
    if ($widget->value_type != 'option') {
      $output .= t('Average: @avg', array('@avg' => round($average, 2))) . ' ';
    }
    if ($widget->value_type == 'points') {
      $output .= t('Points: @points', array('@points' => $sum));
    }
    $output .= '</p>';

    // Display a table with vote counts per button.
    if (count($widget->options) > 1) {
      $rows = array();
      foreach ($widget->options as $option) {
        $query = db_select('votingapi_vote', 'vv')
          ->condition('vv.entity_type', 'node')
          ->condition('vv.entity_id', $node->nid)
          ->condition('vv.value_type', $widget->value_type)
          ->condition('vv.value', $option[0])
          ->condition('vv.tag', $widget->tag)
          ->condition('vv.timestamp', 0, '>');
        $field = $query->addExpression('COUNT(*)', 'vote_count');
        $total_count = $query->execute()->fetchField();
        
        $title = $widget->translate ? t($option[1]) : $option[1];
        $rows[] = array($title, $total_count);
      }
      $header = array(t('Button'), t('Votes'));
      $output .= '<h4>' . t('Total votes per button') . '</h4>';
      $output .= theme('table', array('header' => $header, 'rows' => $rows));
    }
  }

  return $output;
}