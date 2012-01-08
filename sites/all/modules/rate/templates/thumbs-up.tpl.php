<?php
// $Id: thumbs-up.tpl.php,v 1.3.2.1 2011/01/12 23:05:22 mauritsl Exp $

/**
 * @file
 * Rate widget theme
 */

print theme('rate_button', array('text' => $links[0]['text'], 'href' => $links[0]['href'], 'class' => 'rate-thumbs-up-btn-up'));

if ($mode == RATE_FULL || $mode == RATE_CLOSED || $mode == RATE_DISABLED) {
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if (isset($results['user_vote'])) {
    $info[] = format_plural($results['count'], 'Only you voted.', '@count users have voted, including you.');
  }
  else {
    $info[] = format_plural($results['count'], '@count user has voted.', '@count users have voted.');
  }
  print '<div class="rate-info">' . implode(' ', $info) . '</div>';
}

?>