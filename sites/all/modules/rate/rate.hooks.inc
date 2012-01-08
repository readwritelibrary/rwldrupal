<?php
// $Id: rate.hooks.inc,v 1.2.2.3 2011/01/21 16:19:51 mauritsl Exp $

/**
 * @file
 * Defines module hooks.
 */

/**
 * Define templates for rate widgets.
 *
 * @return array
 */
function hook_rate_templates() {
  $templates = array();

  $templates['thumbs_up'] = new stdClass();
  $templates['thumbs_up']->value_type = 'points';
  $templates['thumbs_up']->options = array(
    array(1, 'up'),
  );

  $templates['thumbs_up_down'] = new stdClass();
  $templates['thumbs_up_down']->value_type = 'points';
  $templates['thumbs_up_down']->options = array(
    array(1, 'up'),
    array(-1, 'down'),
  );

  $templates['fivestar'] = new stdClass();
  $templates['fivestar']->value_type = 'percent';
  $templates['fivestar']->options = array(
    array(0, '*'),
    array(25, '**'),
    array(50, '***'),
    array(75, '****'),
    array(100, '*****'),
  );

  return $templates;
}

/**
 * Alter the rate widget before display.
 *
 * @param object $widget Widget object
 * @param array $context
 *   array(
 *     'content_type' => $content_type,
 *     'content_id' => $content_id,
 *   );
 */
function hook_rate_widget_alter(&$widget, $context) {
  
}

/**
 * Take actions before saving rate widget to the database.
 *
 * @param object $widget Widget object
 * @param array $values Values from $form_state['values']
 */
function hook_rate_widget_insert(&$widget, $values) {

}

/**
 * Take actions before updating rate widget.
 *
 * @param object $widget Widget object
 * @param array $values Values from $form_state['values']
 */
function hook_rate_widget_update(&$widget, $values) {
  
}

/**
 * Take action after deleting rate widget.
 *
 * @param object $widget Widget object
 */
function hook_rate_widget_delete(&$widget) {
  
}

/**
 * Alter the vote before it is saved.
 * 
 * @param array $vote
 *   array(
 *     'entity_type' => $content_type,
 *     'entity_id' => $content_id,
 *     'value_type' => $widget->value_type,
 *     'value' => $value,
 *     'tag' => $widget->tag,
 *   );
 * @param array $context
 *   array(
 *     'redirect' => &$redirect, // Path. Alter to redirect the user.
 *     'save' => &$save, // Boolean indicating whether the vote must be saved.
 *     'widget' => $widget, // Widget object, unalterable.
 *   );
 */
function hook_rate_vote_alter($vote, $context) {
  // Redirect users to the feedback page when they click on thumbs down.
  if ($context['widget']->name == 'thumbs_up_down' && $vote['value'] == -1) {
    $context['redirect'] = 'feedback';
  }
}