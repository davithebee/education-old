<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <h4>Dane użytkownika</h4>
    <!-- <form action="./form_dane.php" method="post" novalidate -->
    <form action="./form_dane.php" method="post">
      <input type="text" name="surname" placeholder="Nazwisko" autofocus autocomplete="off" required pattern="[a-z]{2,5}">
      <br><br>

      <input type="submit" value="Wyślij Dane">
    </form>
  </body>
</html>
