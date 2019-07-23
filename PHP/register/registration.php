<html>
<head>
    <title>Registration form</title>
</head>
<body>
<form method="post" action="check.php" enctype="multipart/form-data">
    <table width="300" border="0">
        <tr>
            <td>Username:</td>
            <td><input type="text" name="username"></td>
        </tr>
        <tr>
            <td>Password:</td>
            <td><input type="password" name="password"></td>
        </tr>
        <tr>
            <td>First Name:</td>
            <td><input type="text" name="first_name"></td>
        </tr>
        <tr>
            <td>Last Name:</td>
            <td><input type="text" name="last_name"></td>
        </tr>
        <span style="size:10%;color:#FF0000"><?php if(isset($_GET["pass"])) { echo $_GET["pass"]; } ?></span>
        <tr>
            <td>&nbsp;</td>
            <td><input type="submit" value="Sign up" name="registration" /></td>
        </tr>
    </table>
</form>

</body>
</html>