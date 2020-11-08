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
      height:601px;
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

  $_SESSION['ostroslup_check'] = 1;

  if(isset($_SESSION['prostopadloscian_check']) || isset($_SESSION['szescian_check']) || isset($_SESSION['walec_check'])){
    if($_SESSION['prostopadloscian_check'] == 1 || $_SESSION['szescian_check'] == 1 || $_SESSION['walec_check'] == 1 ){
    $_SESSION['prostopadloscian_check'] = 0;
    $_SESSION['szescian_check'] = 0;
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
    $_SESSION['pole_podstawy'] = $_GET['pole_podstawy'];
    $_SESSION['suma_pol_scian_bocznych_ostroslupa'] = $_GET['suma_pol_scian_bocznych_ostroslupa'];
    $_SESSION['wysokosc'] = $_GET['wysokosc'];

    $_SESSION['pole'] = round($_SESSION['pole_podstawy'] + $_SESSION['suma_pol_scian_bocznych_ostroslupa'], 2);
    $_SESSION['objetosc'] = round(0.33 * $_SESSION['pole_podstawy'] * $_SESSION['wysokosc'], 2);
  }

  function if_zero($a, $b, $c){
    if($a <= 0 || $b <= 0 || $c <= 0) return 0;
    return 1;
  }

?>
  <div id="title">Ostrosłup:</div>
  <div id="kalkulator">
  <img src="../img/ostroslup.png"></img>
  <form action="ostroslup.php" method="GET">
      <input autocomplete="off" type="number" name="pole_podstawy" placeholder="Pole podstawy ostrosłupa" value="<?php echo $_SESSION['pole_podstawy']; ?>" step="0.1" required><br><br>
      <input autocomplete="off" type="number" name="suma_pol_scian_bocznych_ostroslupa" placeholder="Suma pól ścian bocznych ostrosłupa" value="<?php echo $_SESSION['suma_pol_scian_bocznych_ostroslupa']; ?>" step="0.1" required><br><br>
      <input autocomplete="off" type="number" name="wysokosc" placeholder="Wysokość ostrosłupa" value="<?php echo $_SESSION['wysokosc']; ?>" step="0.1" required><br><br>
      <button type="submit" name="calculate" value="submit">=</button><br><br>

      <?php
      if(isset($_SESSION['pole_podstawy']) || isset($_SESSION['suma_pol_scian_bocznych_ostroslupa']) || isset($_SESSION['wysokosc'])){
        if(if_zero($_SESSION['pole_podstawy'], $_SESSION['suma_pol_scian_bocznych_ostroslupa'], $_SESSION['wysokosc'])==1){
          echo'<input style="width:300px" type="text" name="pole" value="';if(isset($_SESSION['pole'])){echo "Pole:  ".number_format($_SESSION['pole'], 2, ",", "")."cm&#178;";} echo'" disabled><br><br>';
          echo'<input style="width:300px" type="text" name="objetosc" value="';if(isset($_SESSION['objetosc'])){echo "Objętość:  ".number_format($_SESSION['objetosc'], 2, ",", "")."cm&#xb3";} echo'" disabled>';
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
