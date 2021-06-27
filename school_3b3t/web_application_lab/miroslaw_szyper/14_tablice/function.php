<?php
function changeAndView($colors)
{
  $colors[0] = 'aqua';
  $colors[1] = 'magenta';
  $colors[2] = 'cyan';
  for($i=0; $i<count($colors); $i++)
  {
    echo ($i+1).' kolor'.': '.$colors[$i].'<br>';
  }
}
?>
