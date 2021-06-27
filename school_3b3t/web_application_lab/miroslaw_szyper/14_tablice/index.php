<?php
//tablice indeksowane
  $colors = array('biały','zielony','czerwony','aqua');

  echo 'Pierwszy element tablicy: ',$colors[0],'<br>';
  echo 'Rozmiar tablicy: ',count($colors),'<br>';
  echo 'Ostatni element tablicy: ',$colors[3],'<br>';
  echo 'Ostatni element tablicy: ',$colors[count($colors)-1],'<br> <br>';

  /*
    Kolor 1: biały
    Kolor 2: zielony
    ...
  */

  for($i=0; $i<count($colors); $i++)
  {
    echo 'Kolor '.($i+1).': '.$colors[$i].'<br>';
  }

  echo '<br>';

  /*
    Funkcja która wyświetla zawartość tablicy
    Do pierwszego elementu przypisuje kolor aqua,
    do drugiego magenta, a do trzeciego cyan
    Wyświetla kolory w formacie:
    1 kolor: aqua
    2 kolor: ...
  */

  require_once 'function.php';
  changeAndView($colors);

?>
