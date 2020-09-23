<?php
  //wersja PHP 7.4.9
  echo PHP_VERSION,"<hr>";
  //echo phpinfo();

  //echo 'a','b','c'; - szybsza, abc
  //echo 'a'.'b'.'c'; - wolniejsza, a+b+c->abc

  $potega = 2 ** 10;
  echo "$potega","<hr>"; //1024

  //operatory bitowe
  // and &, or |, not ~, xor ^, <<, >>

  $x = 0b1010;
  echo "$x<br>"; //10

  $x = $x << 1;
  echo "$x<br>"; // 10100 => 20

  $x = $x >> 3;
  echo "$x<hr>"; // 10 => 2

  //porównanie

  $a = 10;
  $b = 5;

  echo "a = 10, b = 5 <br><br>";

  echo "Czy a równa się b? => ";
  var_dump($a == $b);
  echo "<br>";

  echo "Czy a jest identyczna rodzajem i wartością do b? => ";
  var_dump($a === $b);
  echo "<br>";

  echo "Czy a różna od b? => ";
  var_dump($a != $b);
  echo "<br>";

  echo "Czy a nie jest identyczna rodzajem i wartością do b? => ";
  var_dump($a <> $b);
  echo "<br>";

  echo "Czy a jest mniejsza od b? => ";
  var_dump($a < $b);
  echo "<br>";

  echo "Czy a jest większa od b? => ";
  var_dump($a > $b);
  echo "<br>";

  echo "Czy a jest miejsza lub równa się b? => ";
  var_dump($a <= $b);
  echo "<br>";

  echo "Czy a jest większa lub równa się b? => ";
  var_dump($a >= $b);
  echo "<hr>";

  //porównanie v2

  $x = -10;
  $y = 1;
  echo $x <=> $y;
  echo "<br>";

  $result = $x <=> $y;
  echo $result;
  //jeżeli jest mniejsza, ma wartość -1
  //jeżeli jest równa, ma wartość 0
  //jeżeli jest większa, ma wartość 1

 ?>
