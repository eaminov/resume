<?php
if(isset($_POST['registration']))
{
    require "connection.php";
    $username = strip_tags($_POST['username']);
    $password = strip_tags($_POST['password']);
    $first_name = strip_tags($_POST['first_name']);
    $last_name = strip_tags($_POST['last_name']);

    mysql_query("INSERT INTO users(username,password,first_name,last_name)
    VALUES ('$username','$password','$first_name','$last_name')")
        or  die("".mysql_error());

    echo "Successful Registration!";
}
?>