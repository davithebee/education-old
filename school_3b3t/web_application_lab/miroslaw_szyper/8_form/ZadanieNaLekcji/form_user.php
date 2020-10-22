<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Forma</title>
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
    #ability{
    width: 300px;
    height: 50px;
    }
    </style>
  </head>
  <body>
    <form action="./form_user_data.php" method="post">
      <table>
        <tbody>
          <tr>
            <td>( <span style="color:red">*</span> ) - required fields
          </tr>
          <tr>
            <td>Account Type <span style="color:red">*</span></td>
            <td><input type="radio" name="acctype" value="pa" checked required>Personal Account<input type="radio" name="acctype" value="ba" required>Business Account</td>
          </tr>
          <tr>
            <td>First Name <span style="color:red">*</span></td>
            <td>
              <input type="text" name="frstname" required pattern="[A-Z][a-z-]{1,9}">
            </td>
          </tr>
          <tr>
            <td>Last Name <span style="color:red">*</span></td>
            <td>
              <input type="text" name="lastname" required pattern="[A-Z][a-z]{1,19}">
            </td>
          </tr>
          <tr>
            <td>Country/Region <span style="color:red">*</span></td>
            <td>
              <select name="country_region" required>
                <option value="pl">Poland</option>
                <option value="us">United States</option>
                <option value="gr">Greece</option>
              </select>
            </td>
          </tr>
          <tr>
            <td>Street Address <span style="color:red">*</span></td>
            <td>
              <input type="text" name="strtadd" required>
            </td>
          </tr>
          <tr>
            <td>Street Address 2</td>
            <td>
              <input type="text" name="strtadd2">
            </td>
          </tr>
          <tr>
            <td>State/Province <span style="color:red">*</span></td>
            <td>
              <select name="state_province" required>
                <option disabled hidden selected>Select State or Province</option>
                <option value="wp">Wielkopolskie</option>
                <option value="zp">Zachodniopomorskie</option>
                <option value="mp">Małopolskie</option>
              </select>
            </td>
          </tr>
          <tr>
            <td>ZIP/Postal Code <span style="color:red">*</span></td>
            <td>
              <input type="text" name="postalcode" required patter="[0-9]{5}">
            </td>
          </tr>
          <tr>
            <td>Phone Number <span style="color:red">*</span></td>
            <td>
              <input type="text" name="phonenmbr" required pattern="[0-9][0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9]">
            </td>
          </tr>
          <tr>
            <td colspan="2" style="text-align:center"><input type="submit" value="Enter my information"></td>
          </tr>
        </tbody>
      </table>
      </form>

  </body>
</html>
