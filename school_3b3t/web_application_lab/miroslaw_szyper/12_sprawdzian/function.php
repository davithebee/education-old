<?php
function date_polish($string)
{
 $string = str_replace('Mon', 'Poniedziałek', $string);
 $string = str_replace('Tue', 'Wtorek', $string);
 $string = str_replace('Wed', 'Środa', $string);
 $string = str_replace('Thu', 'Czwartek', $string);
 $string = str_replace('Fri', 'Piątek', $string);
 $string = str_replace('Sat', 'Sobota', $string);
 $string = str_replace('Sun', 'Niedziela', $string);
 $string = str_replace('Jan', 'Styczeń', $string);
 $string = str_replace('Feb', 'Luty', $string);
 $string = str_replace('Mar', 'Marzec', $string);
 $string = str_replace('Apr', 'Kwiecień', $string);
 $string = str_replace('May', 'Maj', $string);
 $string = str_replace('Jun', 'Czerwiec', $string);
 $string = str_replace('Jul', 'Lipiec', $string);
 $string = str_replace('Aug', 'Sierpień', $string);
 $string = str_replace('Sep', 'Wrzesień', $string);
 $string = str_replace('Oct', 'Październik', $string);
 $string = str_replace('Nov', 'Listopad', $string);
 $string = str_replace('Dec', 'Grudzień', $string);

 return $string;
}

function wzor()
{
  $a = $_POST['a'];
  $b = $_POST['b'];

  $wynik = (($a * (-1)) + (sqrt( $b * $b ) - ( 8 * $a ))) / ( 2 * $a );

  return $wynik;
}
