<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Data</title>
  </head>
  <body>
    <?php
    session_start();

    if(isset($_POST['button']))
    {
      echo "<h4>Członkowie rodziny</h4>";
      for($i = 1; $i <= $_SESSION['family']; $i++)
      {
        if(!empty($_POST["person$i"]))
        {
          echo "Osoba nr. $i: ".$_POST["person$i"]."<br><br>";
        }
      }
    }

    if(!empty($_POST['family']))
    {
      $_SESSION['family'] = $_POST['family'];
      $family = $_SESSION['family'];
      echo "<h4>Członkowie rodziny = $family</h4>";

      echo "<form method='post'>";

      for($i = 1; $i <= $family; $i++)
      {
        echo  "<input type='text' name='person$i' value='' placeholder='Członek rodziny nr. $i'> <br><br>";
      }
      echo  "<button type='submit' value='submit' name='button'>Wyślij</button>";
      echo "</form>";
    }else{
      header("./data.php");
    }
    ?>
  </body>
</html>
