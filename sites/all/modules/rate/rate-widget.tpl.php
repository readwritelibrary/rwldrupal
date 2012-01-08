<?php
// $Id: rate-widget.tpl.php,v 1.6.2.1 2011/01/12 23:05:21 mauritsl Exp $

/**
 * @file
 * Rate widget theme
 *
 * This is the default template for rate widgets. See section 3 of the README
 * file for information on theming widgets.
 */

$num = 0;
foreach ($links as $link) {
  ++$num;
  print theme('rate_button', array('text' => $link['text'], 'href' => $link['href'], 'class' => "rate-button-$num"));
}

print t('Total votes: !count', array('!count' => $results['count'])); ?>