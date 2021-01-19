<!DOCTYPE html>
<html lang="pl" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Sklep</title>

    <style>
    body{
      text-align: center;
    }
    a{
      text-decoration: none;
      color: blue;
    }
    table{
      margin-left: auto;
      margin-right: auto;
    }
    table,td{
      border: 3px solid black;
      padding: 16px;
      border-collapse: collapse;
    }
    button, input, select{
      width: 170px;
    }
    </style>
  </head>
  <body>
    <?php
    $products = [];

    if(isset($_GET['amount']) && !is_numeric($_GET['amount']))
    {
      header("location: index.php?error=notnumeric");
    }

    if(isset($_GET['console']))
    {
      if(!empty($_GET['products']))
      {
        $products = explode(',',$_GET['products']);
      }
      $products[] = $_GET['console'];
    }

    $product_amount = [];

    if(isset($_GET['amount']))
    {
      if(!empty($_GET['product_amount']))
      {
        $product_amount = explode(',',$_GET['product_amount']);
      }
      $product_amount[] = $_GET['amount'];
    }
     ?>

    <h1 style="color:orange; font-size: 56px; margin: 10px;">AleDrogo</h1>
    <table>
      <tr>
        <td colspan="2"><form action="./index.php" method="get">
          <select name="console">
            <option disable hidden selected>Wybierz konsolę</option>
            <option value="ns">Nintendo Switch</option>
            <option value="ps5">PS5</option>
            <option value="ps4">PS4</option>
            <option value="xbox_x">Xbox Series X</option>
            <option value="xbox_one">Xbox One</option>
          </select>
          <input type="hidden" name="product_amount" value="<?=implode(',',$product_amount) ?>">
          <input type="hidden" name="products" value="<?=implode(',',$products) ?>">
          <br><br>
          <input type="number" name="amount" placeholder="Ilość" autocomplete="off">
          <br><br>
          <input type="submit" value="Dodaj do Koszyka">
        </form></td>
      </tr>
      <tr>
        <td colspan="2">
          <a href="<?php echo "./store.php?products=".implode(',',$products)."&product_amount=".implode(',',$product_amount) ?>"><button>Kup</button></a>
          <br><br>
          <a href="<?php echo "./index.php" ?>"><button>Wyczyść Koszyk</button></a>
        </td>
      </tr>
      <tr>
        <th colspan="2">CENNIK</th>
      </tr>
      <tr>
        <td>Nintendo Switch</td><td>1500zł</td>
      </tr>
      <tr>
        <td>PlayStation 5</td><td>2300zł</td>
      </tr>
      <tr>
        <td>PlayStation 4</td><td>1400zł</td>
      </tr>
      <tr>
        <td>Xbox Series X</td><td>2300zł</td>
      </tr>
      <tr>
        <td>Xbox One</td><td>1200zł</td>
      </tr>
    </table>
  </body>
</html>
