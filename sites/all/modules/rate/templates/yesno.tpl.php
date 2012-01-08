<?php
// $Id: yesno.tpl.php,v 1.1.2.1 2011/01/12 23:05:22 mauritsl Exp $
/**
 * @file
 * Rate widget theme
 */
?>

<?php foreach ($links as $link): ?>
  <?php print theme('rate_button', array('text' => $link['text'], 'href' => $link['href'], 'class' => 'rate-yesno-btn')); ?>
<?php endforeach; ?>

<?php

if ($mode == RATE_FULL || $mode == RATE_CLOSED) {
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if (isset($results['user_vote'])) {
    $info[] = t('You voted \'@option\'.', array('@option' => $results['user_vote']));
  }
  $info[] = format_plural($results['count'], '@count user has voted.', '@count users have voted.');
  print '<div class="rate-info">' . implode(' ', $info) . '</div>';
}

?>