<?php
// $Id: thumbs-up-down.tpl.php,v 1.3.2.1 2011/01/12 23:05:22 mauritsl Exp $

/**
 * @file
 * Rate widget theme
 */

?>
<div class="rate-thumbs-up-down-rating-up"><?php print $results['up_percent'] . '%'; ?></div>
<?php
print theme('rate_button', array('text' => $links[0]['text'], 'href' => $links[0]['href'], 'class' => 'rate-thumbs-up-down-btn-up'));
print theme('rate_button', array('text' => $links[1]['text'], 'href' => $links[1]['href'], 'class' => 'rate-thumbs-up-down-btn-down'));
?>
<div class="rate-thumbs-up-down-rating-down"><?php print $results['down_percent'] . '%'; ?></div>
<?php

if ($mode == RATE_FULL || $mode == RATE_CLOSED) {
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if (isset($results['user_vote'])) {
    $info[] = t('You voted \'@option\'.', array('@option' => $results['user_vote'] == 1 ? $links[0]['text'] : $links[1]['text']));
  }
  if ($info) {
    print '<div class="rate-info">' . implode(' ', $info) . '</div>';
  }
}

?>