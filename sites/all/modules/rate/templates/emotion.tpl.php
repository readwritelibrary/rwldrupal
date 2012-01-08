<?php
// $Id: emotion.tpl.php,v 1.4.2.1 2011/01/12 23:05:22 mauritsl Exp $

/**
 * @file
 * Rate widget theme
 */
?>

<?php foreach ($links as $link): ?>
  <?php print theme('rate_button', array('text' => $link['text'], 'href' => $link['href'], 'class' => 'rate-emotion-btn')); ?>
  <div class="rate-emotion-votes"><?php print $link['votes']; ?></div>
<?php endforeach; ?>

<?php

if ($mode == RATE_FULL || $mode == RATE_CLOSED) {
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if (isset($results['user_vote'])) {
    $info[] = t('You voted \'@option\'.', array('@option' => t($results['user_vote'])));
  }
  if ($info) {
    print '<div class="rate-info">' . implode(' ', $info) . '</div>';
  }
}

?>