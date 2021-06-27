<?php

function loadIntoTable(){

$serverName = "localhost";
$dBUName = "root";
$dBPassword = "";
$dBName = "egzamin";
$conn = mysqli_connect($serverName, $dBUName, $dBPassword, $dBName);

if(!$conn){
  die("Connection failed: " . mysqli_connect_error());
}

$query = "SELECT * FROM odloty";
$result = mysqli_query($conn, $query);
while($row = mysqli_fetch_array($result)) {
  echo "<tr><td>" . $row["id"]. "</td><td>" . $row["nr_rejsu"] . "</td><td>" . $row["czas"] . "</td><td>" . $row["kierunek"] . "</td><td>" . $row["status_lotu"] . "</td><tr>";
  }
}

function cookies(){

$name = "1_hour_cookie";
$value = 1;
$time = time()+60*60;
$path = "";
$domain = "";
$secure = false;
$httponly = false;

if(!isset($_COOKIE['1_hour_cookie']))
{
  echo '<div id="footer-m"><p>Dzień dobry! Sprawdź regulamin naszej strony</p></div>';
  setcookie($name, $value, $time, $path, $secure, $httponly);
}

if(isset($_COOKIE['1_hour_cookie']))
{
  echo '<div id="footer-m"><p>Miło nam, że nas znowu odwiedziłeś</p></div>';
}

}

?>

<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Odloty Samolotów</title>
    <link href="styl6.css" rel="stylesheet" type="text/css" />
  </head>
  <body>
  <div id="wrapper">
    <div id="header">
      <div id="header-l">
        <h2>Odloty z lotniska</h2>
      </div>
      <div id="header-r">
        <img height="150px" src="samolot.png" alt="logotyp">
      </div>
    </div>
    <div id="content">
      <h4>tabela odlotów</h4>
      <table>
        <thead>
          <tr>
            <th>LP.</th>
            <th>NUMER REJSU</th>
            <th>CZAS</th>
            <th>KIERUNEK</th>
            <th>STATUS</th>
          </tr>
        </thead>
        <?php
        loadIntoTable();
        ?>
      </table>
    </div>
    <div id="footer">
      <div id="footer-l"><a href="">Pobierz obraz</a></div>
      <?php
      echo cookies();
      ?>
      <div id="footer-r">Autor: Dawid Liberski</div>
    </div>
  </div>
  </body>
</html>
