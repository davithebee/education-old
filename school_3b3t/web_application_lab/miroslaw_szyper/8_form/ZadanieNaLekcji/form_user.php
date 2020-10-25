<!DOCTYPE html>
    <head>
        <link rel="stylesheet" href="./css.css"/>
    </head>
    <body>
    <?php 
        session_start();
        if (!isset($_SESSION['accType'])) $_SESSION['accType'] = '';
        if (!isset($_SESSION['firstName'])) $_SESSION['firstName'] = '';
        if (!isset($_SESSION['lastName'])) $_SESSION['lastName'] = '';
        if (!isset($_SESSION['country'])) $_SESSION['country'] = '';
        if (!isset($_SESSION['streetAddress'])) $_SESSION['streetAddress'] = '';
        if (!isset($_SESSION['altStreetAddress'])) $_SESSION['altStreetAddress'] = '';
        if (!isset($_SESSION['zipCode'])) $_SESSION['zipCode'] = '';
        if (!isset($_SESSION['city'])) $_SESSION['city'] = '';
        if (!isset($_SESSION['state'])) $_SESSION['state'] = '';
        if (!isset($_SESSION['phoneNumber'])) $_SESSION['phoneNumber'] = '';
    ?>
        <div class="wrapper">
        ( <span class="required">*</span> ) Required fields
        <form method="post" action="./form_user_data.php">
            <table>
                <tr>
                <td>Account Type<span class="required">*</span></td>
                <td><input type="radio" id="accType" name="accType" value="Personal Account" <?php if($_SESSION['accType'] != 'Business Account') {echo 'checked';}?>> Personal Account
                <input type="radio" id="accType" name="accType" value="Business Account" <?php if($_SESSION['accType'] == 'Business Account') {echo 'checked';}?>> Business Account <br></td>
                </tr>
                <tr>
                <td>First Name<span class="required">*</span></td>
                <td><input type="text" class="txtName" id="firstName" value="<?php echo $_SESSION['firstName']; ?>" name="firstName" required pattern="^[A-ZĄĘŻŹŃŁÓŚ][a-ząężźńłóś]{1,9}"> <br></td>
                </tr>
                <tr>
                <td>Last Name<span class="required">*</span></td>
                <td><input type="text" class="txtName" id="lastName" value="<?php echo $_SESSION['lastName']; ?>" name="lastName" required pattern="^[A-ZĄĘŻŹŃŁÓŚ][a-ząężźńłóś-]{1,19}"> <br></td>
                </tr>
                <tr>
                <td>Country/Region<span class="required">*</span></td>
                <td><select id="country" name="country" required>
                    <option value="Poland" <?php if($_SESSION['country'] == 'Poland') {echo 'selected';}?>>Polska</option>
                    <option value="USA" <?php if($_SESSION['country'] == 'USA') {echo 'selected';}?>>USA</option>
                    <option value="Greece" <?php if($_SESSION['country'] == 'Greece') {echo 'selected';}?>>Grecja</option>
                </select> <br></td>
                </tr>
                <tr>
                <td>Street Address<span class="required">*</span></td>
                <td><input type="text" class="txtName" value="<?php echo $_SESSION['streetAddress']; ?>" id="streetAddress" name="streetAddress" required> <br></td>
                </tr>
                <tr>
                <td>Street Address 2</td>
                <td><input type="text" class="txtName" value="<?php echo $_SESSION['altStreetAddress']; ?>" id="altStreetAddress" name="altStreetAddress"> <br></td>
                </tr>
                <tr>
                <td>City<span class="required">*</span></td>
                <td><input type="text" class="txtName" value="<?php echo $_SESSION['city']; ?>" id="city" name="city" required> <br></td>
                </tr>
                <tr>
                <td>State/Province<span class="required" required>*</span></td>
                <td><select id="state" name="state">
                    <option value="Wielkopolskie" <?php if($_SESSION['state'] == 'Wielkopolskie') {echo 'selected';}?>>Wielkopolskie</option>
                    <option value="Zachodniopomorskie" <?php if($_SESSION['state'] == 'Zachodniopomorskie') {echo 'selected';}?>>Zachodniopomorskie</option>
                    <option value="Malopolskie" <?php if($_SESSION['state'] == 'Malopolskie') {echo 'selected';}?>>Małopolskie</option>
                </select> <br></td>
                </tr>
                <tr>
                <td>ZIP/Postal Code<span class="required">*</span></td>
                <td><input type="text" id="zipCode" value="<?php echo $_SESSION['zipCode']; ?>" name="zipCode" required pattern="[0-9]{5}"> <br></td>
                </tr>
                <tr>
                    <td></td>
                    <td><span class="infoTxt">Only used for questions related to your order.</span></td>
                </tr>
                <tr>
                <td>Phone Number<span class="required">*</span></td>
                <td><input type="text" id="phoneNumber" value="<?php echo $_SESSION['phoneNumber']; ?>" name="phoneNumber" required pattern="[0-9]{9}"><br></td>
                </tr>
            </table>
            <input type="submit" value="Submit">
        </form>
        </div>
    </body>
</html>
