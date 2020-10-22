<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Dane</title>
  </head>
  <body>
    <h3>Dane użytkownika</h3>
    <?php
      $acctype = $_POST['acctype'];
      $frstname = $_POST['frstname'];
      $lastname = $_POST['lastname'];
      $country_region = $_POST['country_region'];
      $strtadd = $_POST['strtadd'];
      $strtadd2 = $_POST['strtadd2'];
      $state_province = $_POST['state_province'];
      $postalcode = $_POST['postalcode'];
      $phonenmbr = $_POST['phonenmbr'];

      if(empty($acctype))

      switch ($acctype) {
        case 'pa':
          $acctype = "Personal Account";
          break;
        case 'ba':
          $acctype = "Business Account";
          break;
      }

      switch ($country_region) {
        case 'pl':
          $country_region = "Poland";
          break;
        case 'us':
          $country_region = "United States of America";
          break;
        case 'gr':
          $country_region = "Greece";
          break;
      }

      switch ($state_province) {
        case 'wp':
          $state_province = "Wielkopolskie";
          break;
        case 'zp':
          $state_province = "Zachodniopomorskie";
          break;
        case 'mp':
          $state_province = "Małopolskie";
          break;
      }

      if(empty($strtadd2)) $strtadd2 = "-----";

      echo <<<DATA
      Account Type: $acctype<br>
      First Name: $frstname<br>
      Last Name: $lastname<br>
      Country/Region: $country_region<br>
      Street Address: $strtadd<br>
      Street Address 2: $strtadd2<br>
      State/Province: $state_province<br>
      ZIP/Postal Code: $postalcode<br>
      Phone Number: $phonenmbr
DATA;
    ?>
  </body>
</html>
