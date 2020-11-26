<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Formularz</title>
  </head>
  <body>
    <?php
      if(isset($_SESSION)) session_destroy();
    ?>
    <h4>Ilość członków rodziny</h4>
    <form action="./data.php" method="post">
      <input type="number" name="family" value="">
      <br><br>
      <button type="submit" name="number_send">Wyślij</button>
    </form>

  </body>
</html>
