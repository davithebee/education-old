<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formularze</title>
  </head>
  <body>
    <form method="get">
      <input type="text" name="surname" autofocus><br><br>
      <input type="submit" value="Wyślij"><hr>
    </form>

      <?php
      if (isset($_GET['surname'])) {
        $surname = $_GET['surname'];
        echo $surname;
      }else{
        echo 'Wyślij formularz';
      }

      ?>
  </body>
</html>
