<head>
    <title>Galeria</title>
    <link rel="stylesheet" href="styl.css">
</head>
<body>
<?php
//--------------BAZA DANYCH-------------//
//-----------EE.09-02-20.06-SG----------//
//-----NA EGZAMIN-EE09.BLOGSPOT.COM-----//

//-----Połączenie z bazą danych-----//
$servername = "localhost";
$username = "root";
$password = "";
$db = "egzamin3";
$conn = mysqli_connect($servername, $username, $password, $db);
mysqli_query($conn, "SET NAMES utf8");


//-----Zapytanie mysqli-----//
$sql1 = 
"SELECT `nazwaPliku`, `podpis`
FROM `zdjecia`
ORDER BY `podpis` ASC;";

$result1 = mysqli_query($conn, $sql1);

//-----Wypisanie zdjęć na stronie-----//
$brFlag = 0;

while($row = mysqli_fetch_assoc($result1)){
    echo "<img src='".$row['nazwaPliku']."' title='".$row['podpis']."'>";
    $brFlag++;
    if($brFlag % 3 == 0){
        echo "<br>";
    }
}

//-----Przerwa między skryptem 1 i 2----//
echo "<br><br><hr><br>";

//-----Zapytanie mysqli-----//
$sql2 = 
"SELECT `id`,`dataWyjazdu`, `cel`, `cena`
FROM `wycieczki`
WHERE `dostepna` = 1";

$result2 = mysqli_query($conn, $sql2);

//-----Wypisanie wierszy na stronie-----//

echo "<ol>";

while($row = mysqli_fetch_assoc($result2)){
    echo $row['id'].". ".$row['dataWyjazdu'].", ".$row['cel'].", cena: ".$row['cena']."<br>";
}

echo "</ol>";

mysqli_close($conn);
?>
</body>