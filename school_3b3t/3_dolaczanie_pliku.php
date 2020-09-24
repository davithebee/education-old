<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
  </head>
  <body>
    Początek Pliku<hr>
    <?php
    echo 'Include: <br>';
    include './3_1_file.php'; //jeżeli include nie znajdzie pliku to zwraca zwykły error (reszta strony wyświetla się normalnie).
    include_once './3_1_file.php'; //jeżeli plik był już dołączony, nie dołączaj go. W przeciwnym przypadku - dołącz.
    echo 'Require: <br>';
    require './3_1_file.php'; //jeżeli require nie znajdzie pliku to zwraca fatal error (reszta strony przestaje być wczytywana).
    require_once './3_1_file.php'; //jeżeli plik był już dołączony, nie dołączaj go. W przeciwnym przypadku - dołącz.
    echo 'PHP<br>';
     ?>
    <hr>Koniec Pliku
  </body>
</html>
