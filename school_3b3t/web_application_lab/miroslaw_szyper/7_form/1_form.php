<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <style>
    table {
    border-collapse: collapse;
    margin: 25px 0;
    font-size: 0.9em;
    font-family: sans-serif;
    min-width: 400px;
    box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);
    }
    thead tr {
    background-color: #009879;
    color: #ffffff;
    text-align: left;
    }
    th, td {
    padding: 12px 15px;
    }
    tbody tr {
    border-bottom: 1px solid #dddddd;
    }
    tbody tr:nth-of-type(even) {
    background-color: #f3f3f3;
    }
    tbody tr:last-of-type {
    border-bottom: 4px solid #009879;
    }
    #ability{
    width: 300px;
    height: 50px;
    }
    </style>
  </head>
  <body>
    <form action="./1_data_show.php" method="get">
      <table>
        <thead>
          <td>Name</td><td>Value</td>
        </thead>
        <tbody>
          <tr>
            <td>Name</td>
            <td><input type="text" name="name"></td>
          </tr>
          <tr>
            <td>Sex</td>
            <td>
              <input type="radio" name="sex" value="M">Male<br>
              <input type="radio" name="sex" value="F">Female
            </td>
          </tr>
          <tr>
            <td>Eye color</td>
            <td>
              <select name="eyecolor">
                <option value="br">Brązowe</option>
                <option value="gr">Zielone</option>
                <option value="bl">Niebieskie</option>
              </select>
            </td>
          </tr>
          <tr>
            <td>Check all that apply</td>
            <td>
              <input type="checkbox" name="checkheight" value="height6ft">Over 6 feet tall<br>
              <input type="checkbox" name="checkweight" value="weight200lb">Over 200 pounds
            </td>
          </tr>
          <tr>
            <td colspan="2">Describe your athletic ability:<br><input type="text" name="ability" id="ability"></td>
          </tr>
          <tr>
            <td colspan="2" style="text-align:center"><input type="submit" value="Enter my information"></td>
          </tr>
        </tbody>
      </table>
      </form>

  </body>
</html>
