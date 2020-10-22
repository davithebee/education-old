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
      <input type="text" name="surname" placeholder="Nazwisko" autofocus autocomplete="off" required pattern="[a-ząęśżźćńłó]{2,5}">
      <br><br>
      <select name="sex">
        <option disable hidden selected>Wybierz opcję</option>
        <option value="m">Mężczyzna</option>
        <option value="f">Kobieta</option>
        <!-- <option value="f" selected>Kobieta</option> -->
      </select>
      <input type="submit" value="Wyślij Dane">
    </form>
  </body>
</html>
