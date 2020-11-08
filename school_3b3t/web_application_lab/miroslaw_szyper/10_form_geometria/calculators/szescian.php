<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Kalkulator</title>
    <style>
    body{
      background-color:white;
      margin:0px;
      text-align:center;
    }
    #kalkulator{
      margin:auto;
      display:block;
      background-color: #ffffff;
      width:500px;
      height:541px;
      text-align:center;
      border:3px solid black;
      border-radius:10px;
      padding-top:40px;
    }
    #title{
      font-size:30px;
      font-family:sans-serif;
      font-weight:bold;
      margin-top:20px;
      margin-bottom:20px;
    }
    </style>
</head>
<body>
<?php
  session_start();

  $_SESSION['szescian_check'] = 1;

  if(isset($_SESSION['prostopadloscian_check']) || isset($_SESSION['ostroslup_check']) || isset($_SESSION['walec_check'])){
    if($_SESSION['prostopadloscian_check'] == 1 || $_SESSION['ostroslup_check'] == 1 || $_SESSION['walec_check'] == 1 ){
    $_SESSION['prostopadloscian_check'] = 0;
    $_SESSION['ostroslup_check'] = 0;
    $_SESSION['walec_check'] = 0;
    unset($_SESSION['a']);
    unset($_SESSION['b']);
    unset($_SESSION['c']);
    unset($_SESSION['pole']);
    unset($_SESSION['objetosc']);
    unset($_SESSION['przekatna']);
    unset($_SESSION['kula_opisana_w']);
    unset($_SESSION['kula_opisana_na']);
    unset($_SESSION['pole_podstawy']);
    unset($_SESSION['suma_pol_scian_bocznych_ostroslupa']);
    unset($_SESSION['wysokosc']);
    unset($_SESSION['promien']);
    unset($_SESSION['pole_powierzchni_bocznej']);
    }
  }

  if(isset($_GET['calculate'])){
    $_SESSION['a'] = $_GET['a'];

    $_SESSION['pole'] = round(6 * $_SESSION['a'] * $_SESSION['a'], 2);
    $_SESSION['objetosc'] = round($_SESSION['a'] * $_SESSION['a'] * $_SESSION['a'], 2);
    $_SESSION['przekatna'] = round($_SESSION['a'] * sqrt(3), 2);
    $_SESSION['kula_opisana_w'] = round(0.5 * $_SESSION['a'], 2);
    $_SESSION['kula_opisana_na'] = round(0.5 * $_SESSION['a'] * sqrt(3), 2);
  }

  function if_zero($a){
    if($a <= 0 ) return 0;
    return 1;
  }

?>
  <div id="title">Sześcian:</div>
  <div id="kalkulator">
  <img src="../img/szescian.png"></img>
  <form action="szescian.php" method="GET">
      <input autocomplete="off" type="number" name="a" placeholder="a" value="<?php echo $_SESSION['a']; ?>" step="0.1" required><br><br>
      <button type="submit" name="calculate" value="submit">=</button><br><br>

      <?php
      if(isset($_SESSION['a'])){
        if(if_zero($_SESSION['a'])==1){
          echo'<input style="width:300px" type="text" name="pole" value="';if(isset($_SESSION['pole'])){echo "Pole:  ".number_format($_SESSION['pole'], 2, ",", "")."cm&#178;";} echo'" disabled><br><br>';
          echo'<input style="width:300px" type="text" name="objetosc" value="';if(isset($_SESSION['objetosc'])){echo "Objętość:  ".number_format($_SESSION['objetosc'], 2, ",", "")."cm&#xb3";} echo'" disabled><br><br>';
          echo'<input style="width:300px" type="text" name="przekatna" value="';if(isset($_SESSION['przekatna'])){echo "Przekątna:  ".number_format($_SESSION['przekatna'], 2, ",", "")."cm";} echo'" disabled><br><br>';
          echo'<input style="width:300px" type="text" name="objetosc" value="';if(isset($_SESSION['kula_opisana_w'])){echo "Promień kuli opisanej w sześcian:  ".number_format($_SESSION['objetosc'], 2, ",", "")."cm&#xb3";} echo'" disabled><br><br>';
          echo'<input style="width:300px" type="text" name="objetosc" value="';if(isset($_SESSION['kula_opisana_na'])){echo "Promień kuli opisanej na sześcianie:  ".number_format($_SESSION['objetosc'], 2, ",", "")."cm&#xb3";} echo'" disabled>';
        } else {
          echo'<strong>Dane w formularzu muszą być poprawnymi długościami!</strong>';
        }
      } else {
        echo'<strong>Wpisz wartości!</strong>';
      }
      ?>

  </form>
  <br>
  <a href="../1_formularze_geometria.html">Powrót do strony głównej</a>
  </div>
</body>
</html>
