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
      margin: auto;
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
    <span style="font-size:30px; font-family:sans-serif; font-weight:bold;">Kalkulator</span>
    <div id="kalkulator">
    <form method="GET">
        <input type="text" name="x">
        <select required name="Country">
            <option value="add">+</option>
            <option value="substract">-</option>
            <option value="multiply">*</option>
            <option value="divide">/</option>
        </select>
        <input type="text" name="y">
        <button name="calculate">=</button>
        <input type="text" name="result" disabled>
    </form>
    </div>
</body>
</html>
