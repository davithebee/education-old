<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Lista klientów</title>
  </head>
  <body>
    <h3>Lista klientów</h3>
    <hr>
    <?php
    //połączenie z bazą danych
    //$connect = mysqli_connect("localhost", "root", "", "zsl_3b3g1");

    //@ - operator ignorowania błędów
    $connect = @new mysqli("localhost", "root", "", "zsl_3b3g1");
    //print_r($connect);

    //sprawdzenie poprawności połączenia z bazą danych (0 - ok)
      //echo $connect->connect_error;
      //echo $connect->connect_errno;
      /*
        2002 - server error
        1045 - user error
        1045 - password error
        1049 - table error
      */

      $sql = "SELECT * FROM `customers`";
      $result = $connect->query($sql);

      while ($row = $result->fetch_assoc()){
        echo <<<SHOW
          Imię i nazwisko: $row[name] $row[surname],
          data urodzenia: $row[birthday],
          wzrost: $row[height]
          <br>
SHOW;
    }

    $connect->close();
    ?>
  </body>
</html>
