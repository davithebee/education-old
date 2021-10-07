<head>
    <title>Galeria</title>
    <link rel="stylesheet" href="styl.css">
</head>
<body>
<?php
//--------------BAZA DANYCH-------------//
//-----------EE.09-01-20.06-SG----------//
//-----NA EGZAMIN-EE09.BLOGSPOT.COM-----//

//-----Połączenie z bazą danych-----//
$servername = "localhost";
$username = "root";
$password = "";
$db = "egzamin6";
$conn = mysqli_connect($servername, $username, $password, $db);
mysqli_query($conn, "SET NAMES utf8");


//-----Zapytanie mysqli-----//
$sql1 = 
"SELECT `dataZadania`, `miesiac`, `wpis`
FROM `zadania`
WHERE `miesiac` = 'sierpien';";

$result1 = mysqli_query($conn, $sql1);

//-----Pole edycyjne-----//
echo "<form method='POST'>";
echo "<input type='text' name='zadanie'><br>";
echo "<input type='submit'><br>";
echo "</form>";

@$zadanie = $_POST['zadanie'];

$sqlupdate =
"UPDATE `zadania`
SET `wpis` = '$zadanie'
WHERE `dataZadania` = '2020-08-27'";

mysqli_query($conn, $sqlupdate);

//-----Wypisanie dat-----//
while($row = mysqli_fetch_assoc($result1)){
    echo $row['dataZadania']." ".$row['miesiac']." ".$row['wpis']."<br>";
}

//-----Przerwa między skryptem 1 i 2----//
echo "<br><br><hr><br>";

//-----Zapytanie mysqli-----//
$sql2 = 
"SELECT `miesiac`, `rok`
FROM `zadania`
WHERE `dataZadania` = '2020-08-01'";

$result2 = mysqli_query($conn, $sql2);

//-----Wypisanie daty na stronie-----//
while($row = mysqli_fetch_assoc($result2)){
    echo "<h1>".$row['miesiac']." ".$row['rok']."</h1>";
}

mysqli_close($conn);
?>
</body>