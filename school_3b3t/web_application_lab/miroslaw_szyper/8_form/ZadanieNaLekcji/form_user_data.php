<!DOCTYPE html>
    <head>
    </head>
    <body>
        <?php
            session_start();
            $_SESSION['accType'] = $_POST['accType'];
            $_SESSION['firstName'] = $_POST['firstName'];
            $_SESSION['lastName'] = $_POST['lastName'];
            $_SESSION['country'] = $_POST['country'];
            $_SESSION['streetAddress'] = $_POST['streetAddress'];
            $_SESSION['altStreetAddress'] = $_POST['altStreetAddress'];
            $_SESSION['zipCode'] = $_POST['zipCode'];
            $_SESSION['city'] = $_POST['city'];
            $_SESSION['state'] = $_POST['state'];
            $_SESSION['phoneNumber'] = $_POST['phoneNumber'];

            if(empty($_POST["accType"]) or empty($_POST["firstName"]) or empty($_POST["lastName"]) or empty($_POST["country"]) or empty($_POST["streetAddress"]) 
            or empty($_POST["zipCode"]) or empty($_POST["city"]) or empty($_POST["state"]) or empty($_POST["phoneNumber"]))
            { 
                header("Location: ./form_user.php");
                die(); 
            }


            print('Konto: '.$_POST["accType"]. '</br>');
            print('Imię i Nazwisko: '.$_POST["firstName"].' '.$_POST["lastName"].'</br>');
            print('Kraj: '.$_POST["country"]. '</br>');
            print('Adres 1: '.$_POST["streetAddress"].'<br>');
            print('Adres 2: '.$_POST["altStreetAddress"].'<br>');
            print('Kod pocztowy i miasto: '.substr($_POST["zipCode"], 0,2).'-'.substr($_POST["zipCode"], 2,5).' '.$_POST["city"].'<br>');
            print('Województwo: '.$_POST["state"].'<br>');
            print('Numer Telefonu: '.$_POST["phoneNumber"].'<br>');
        ?>
    </body>
</html>
