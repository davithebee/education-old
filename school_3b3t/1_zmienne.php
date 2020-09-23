<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Zmienne</title>
  </head>
  <body>
    <?php
    $name='Anna';
    echo 'Imię: $name<br>';
    // konkatenacja .
    echo "Imię: $name"."<hr>";

    // typy danych
    // boolean

    $prawda = true;
    $fałsz = false;

    echo $prawda; // 1
    echo "$fałsz<hr>";  // brak wyświetlenia

    // integer
    $calkowita = 10; // 10
    $hex = 0xB; // dodajemy 0x na początku | 11
    $oct = 010; // dodajemy 0 na początku | 8
    $bin = 0b1011; //dodajemy 0b na początku | 11

    echo "$calkowita<br>";
    echo "$hex<br>";
    echo "$oct<br>";
    echo "$bin<hr>";

    // składnia heredoc
    $name = 'Janusz';
    $text =<<< ETYKIETA
    Imię w heredoc: $name<br>
    Druga linia heredoc<hr>
ETYKIETA;

    echo $text;

    echo <<< E
      Heredoc V2<hr>
E;

// składnia nowdoc
    $city = 'Poznań';

    echo <<< 'E'
    Miasto: $city<hr>
E;

    echo "Nazwa zmiennej: \$city, wartość: \$city";

     ?>
  </body>
</html>
