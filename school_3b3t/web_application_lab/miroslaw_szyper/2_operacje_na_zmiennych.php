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

  echo "Czy a jest mniejsza lub równa się b? => ";
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


  echo "<hr>";

  $x = 1;
  $y = 1.0;

  //porównanie czy jest równe
  if ($x == $y){
    echo "$x jest równe $y";
  }else{
    echo "$x nie jest równe $y";
  }

  echo "<br>";

  //porównanie czy jest identyczne
  if ($x === $y){
    echo "$x jest identyczne $y";
  }else{
    echo "$x nie jest identyczne $y";
  }

  echo "<br>";
  echo gettype($x); echo "<br>"; //integer
  echo gettype($y); echo "<br>"; //double
  echo "<hr>";
  /*
  preinkrementacja ++$i
  predekrementacja --$i
  postinkrementacja $i++
  postdekrementacja $i--
  */

  $x=5;
  $x=$x++; /*5*/
  echo $x; echo"<br>";
  $x=++$x; /*7*/
  echo $x; echo"<br>";
  $y=$x++;
  echo $x; /*7*/ echo"<br>";
  echo $y; /*6*/ echo"<br>";
  $y=++$x*2-1;
  echo $x; /*8*/ echo"<br>";
  echo $y; /*15*/ echo"<br>";

  //operatory rzutowania
  //bool, int, float, string, array, object, unset

  $test1 = '123abc45';
  echo "<hr> $test1";
  echo '<br>Typ danych $test1: ',gettype($test1),'<br>';

  $test1 = (int)$test1;
  echo "<hr> $test1"; //po dojściu do stringa (w tym przypadku litery a) kończy rzutować
  echo '<br>Typ danych $test1: ',gettype($test1),'<br>';

  $test2 = 0;
  echo "<hr> $test2";
  echo '<br>Typ danych $test2: ',gettype($test2),'<br>';

  $test2 = (bool)$test2;
  echo "<hr> $test2";
  echo '<br>Typ danych $test2: ',gettype($test2),'<br>';

  $test3 = 20.5;
  echo "<hr> $test3";
  echo '<br>Typ danych $test3: ',gettype($test3),'<br>';

  $test3 = (unset)$test3;
  echo "<hr> $test3";
  echo '<br>Typ danych $test3: ',gettype($test3),'<hr>';

  //rozmiar typu integer
  echo PHP_INT_SIZE; //8
 ?>

