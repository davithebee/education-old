<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Kalkulator</title>
    <style>
    body{
      background-color:#f2f2f2;
      margin:0px;
      text-align:center;
    }
    #kalkulator{
      margin:auto;
      display:block;
      background-color: #ffffff;
      width:700px;
      height:61px;
      text-align:center;
      border:5px solid black;
      border-radius:40px;
      padding-top:40px;
      box-shadow: 0 10px 20px 0 rgba(0, 0, 0, 0.5);
    }
    </style>
</head>
<body>
  <?php
    session_start();

    require_once './Kalkulator_Funkcje.php';

    if(isset($_GET['calculate'])){
      $_SESSION['x'] = $_GET['x'];
      $_SESSION['y'] = $_GET['y'];
      $_SESSION['select_option'] = $_GET['operator'];
      switch($_GET['operator']){
        case "add":
          $_SESSION['wynik'] = add($_SESSION['x'], $_SESSION['y']);
        break;
        case "substract":
          $_SESSION['wynik'] = substract($_SESSION['x'], $_SESSION['y']);
        break;
        case "multiply":
          $_SESSION['wynik'] = multiply($_SESSION['x'], $_SESSION['y']);
        break;
        case "divide":
          if($_SESSION['y'] != 0){
            $_SESSION['wynik'] = divide($_SESSION['x'], $_SESSION['y']);
            break;
          }
          $SESSION['wynik'] = 'ERROR';
        break;
      }
    }
  ?>
    <span style="font-size:30px; font-family:sans-serif; font-weight:bold;">Kalkulator</span>
    <div id="kalkulator">
    <form action="Kalkulator.php" method="GET">
        <input type="number" name="x" value="<?php echo $_SESSION['x']; ?>" required>
        <select required name="operator">
            <?php
            if(isset($_SESSION['select_option'])){
              $select_option = $_SESSION['select_option'];
            } else {
              $select_option = 'add';
            }
            echo '<option value="add"';if($select_option=='add') echo 'selected';echo '>+</option>';
            echo '<option value="substract"';if($select_option=='substract') echo 'selected';echo '>-</option>';
            echo '<option value="multiply"';if($select_option=='multiply') echo 'selected';echo '>*</option>';
            echo '<option value="divide"';if($select_option=='divide') echo 'selected';echo '>/</option>';
            ?>
        </select>
        <input type="number" name="y" value="<?php echo $_SESSION['y']; ?>" required>
        <button type="submit" name="calculate" value="submit">=</button>
        <input type="text" name="result" value="<?php echo $_SESSION['wynik']; ?>" disabled>
    </form>
    </div>
</body>
</html>
