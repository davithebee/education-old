<?php
$conn = mysqli_connect("localhost", "root", "", "wedkowanie2");
?>
<form method="post">
    <p><input type="text" name="nazwa"></p>
    <p><input type="text" name="wystepowanie"></p>
    <p><input type="number" name="styl_zycia"></p>
    <p><input type="submit"></p>
</form>
<?php
if(isset($_POST['nazwa'],$_POST['wystepowanie'],$_POST['styl_zycia'])){
    
$nazwa = $_POST['nazwa'];
$wystepowanie = $_POST['wystepowanie'];
$styl_zycia = $_POST['styl_zycia'];

echo 'Wstawiono: '.$nazwa.',<br>';
echo 'o wystepowaniu: '.$wystepowanie.',<br>';
echo 'i stylu zycia: '.$styl_zycia;

$SQL = "INSERT INTO `ryby`(`id`, `nazwa`, `wystepowanie`, `styl_zycia`) VALUES ('','$nazwa','$wystepowanie','$styl_zycia')";
mysqli_query($conn, $SQL);

}

?>