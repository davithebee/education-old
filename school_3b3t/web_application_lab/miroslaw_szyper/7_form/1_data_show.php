<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <h3>Dane użytkownika</h3>
    <?php
      $name = $_GET['name'];
      $sex = $_GET['sex'];
      $eyecolor = $_GET['eyecolor'];
      $checkheight = $_GET['checkheight'];
      $checkweight = $_GET['checkweight'];
      $ability = $_GET['ability'];

      switch ($sex) {
        case 'M':
          $sex = "Male";
          break;
        case 'F':
          $sex = "Female";
          break;
        default:
          $sex = "Not inputted";
          break;
      }

      switch ($eyecolor) {
        case 'br':
          $eyecolor = "Brown";
          break;
        case 'gr':
          $eyecolor = "Green";
          break;
        case 'bl':
          $eyecolor = "Blue";
          break;
        default:
          $eyecolor = "Not inputted";
          break;
      }

      if($checkheight="height6ft" && $checkweight="weight200lb") $check="Is over 6 feet high and weighs over 200lb";
      else if($checkheight="height6ft") $check="Is over 6 feet high";
      else if($checkheight="weight200lb") $check="Weighs over 200lb";

      //echo '<pre>',print_r($_GET),'</pre>';

      echo <<<DATA
      Name: $name<br>
      Sex: $sex<br>
      Eye color: $eyecolor<br>
      $checkbox<br>
      Athletic ability description:<br>

DATA;
    ?>
  </body>
</html>
