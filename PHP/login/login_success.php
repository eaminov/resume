<?php
session_start();

if(!isset($_SESSION['name'])) {
    header("location:main_login.php");
}
echo "<h1>Welcome ".  $_SESSION['name'] . "!</h1>";
?>

<!--
<html>
<body>
Login Successful
</body>
</html>
//-->