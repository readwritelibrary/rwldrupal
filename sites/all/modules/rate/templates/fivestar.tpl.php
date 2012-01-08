<?php
// $Id: fivestar.tpl.php,v 1.6.2.1 2011/01/12 23:05:22 mauritsl Exp $

/**
 * @file
 * Rate widget theme
 */

for ($i = 0; $i < 5; $i++) {
  if (round($results['rating'] / 25) >= $i && $results['count']) {
    $class = 'rate-fivestar-btn-filled';
  }
  else {
    $class = 'rate-fivestar-btn-empty';
  }
  print theme('rate_button', array('text' => $links[$i]['text'], 'href' => $links[$i]['href'], 'class' => $class));
}

if ($mode == RATE_FULL || $mode == RATE_CLOSED) {
  // Generate the info line.
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.') . ' ';
  }
  if (isset($results['user_vote'])) {
    $vote = round($results['user_vote'] / 25) + 1;
    $info[] = t('You voted !vote.', array('!vote' => $vote)) . ' ';
  }
  $info[] = t('Total votes: !count', array('!count' => $results['count']));
  print '<div class="rate-info">' . implode(' ', $info) . '</div>';
}

?>