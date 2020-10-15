<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <h3>Dane użytkownika</h3>
    <?php

      $pass = $_GET['password'];
      $color = $_GET['color'];

      switch ($color) {
        case 'r':
          $color = "czerwony";
          break;
        case 'g':
          $color = "zielony";
          break;
        case 'b':
          $color = "niebieski";
          break;
      }

      //echo '<pre>',print_r($_GET),'</pre>';

      echo <<<DATA
      Login: $_GET[login]<br>
      Hasło: {$_GET['password']}<br>
      Hasło: $pass<br>
      Ulubiony Kolor: $color
DATA;
    ?>
  </body>
</html>
