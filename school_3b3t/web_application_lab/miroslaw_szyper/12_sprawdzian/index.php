<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Formularz</title>
  </head>
  <body>
    <h4>Ilość członków rodziny</h4>
    <form action="./nazwisko_imie.php" method="post">
      <input type="text" placeholder="Imię" name="name" required value="" pattern="^[A-ZĄĘŻŹŃŁÓŚ][a-ząężźńłóś]{1,9}">
      <br><br>
      <input type="text" placeholder="Nazwisko" name="surname" required value="" pattern="^[A-ZĄĘŻŹŃŁÓŚ][a-ząężźńłóś]{1,}">
      <br><br>
      <input type="number" placeholder="a" name="a" required value="">
      <br><br>
      <input type="number" placeholder="b" name="b" required value="">
      <br><br><br>
      <button type="submit" name="send">Wyślij</button>
    </form>

  </body>
</html>
