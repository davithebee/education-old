<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Formularz</title>

    <style media="screen">
    table,td{
      border: 3px solid black;
      border-collapse: collapse;
      padding: 10px;
    }
    </style>

  </head>
    <body>
        <script type="text/javascript">
          function showhide(id) {
            var a = document.getElementById(id);
            a.style.display = (e.style.display == 'block') ? 'none' : 'block';
          }
        </script>
        <div class="wrapper">
          <?php
          require_once './function.php';

          if(isset($_POST['send']))
          {
            $name = $_POST['name'];
            $surname = $_POST['surname'];
            $a = $_POST['a'];
            $b = $_POST['b'];

            echo ucwords($name)."_".ucwords($surname)."_gr_1 <br><br>";
          }
          ?>
            <table>
                <tr>
                  <td colspan="2">
                    <?php
                    echo 'Dzień tygodnia: ' . date_polish(date('D'))."<br>";
                    echo 'Miesiąc: ' . date_polish(date('M'))."<br>";
                    echo 'Rok: ' . date('Y')."<br>";
                    echo 'Godzina: ' . date('h:i:s A')."<br>";
                    ?>
                  </td>
                </tr>
                <tr>
                  <td>Klasa: 3B3T gr_1</td>
                  <td>
                    <a href="javascript:showhide('wynik')">
    		            Click to show/hide.
    	              </a>
                  </td>
                </tr>
                <tr>
            </table>
            <?php
              echo "<br><br><div id='wynik' style='display:none;'>".wzor($a,$b)."</div>";
            ?>
        </div>
    </body>
</html>
