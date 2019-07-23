<?php
mysql_connect("studenttask-db.my.phpcloud.com","studenttask","qwerty321") or die(mysql_error());
mysql_select_db("studenttask") or die(mysql_error());

$ID = (int)$_POST["course_id"];

$course_id = mysql_real_escape_string($_POST["course_id"]);
$course_name = mysql_real_escape_string($_POST["course_name"]);
$course_day = mysql_real_escape_string($_POST["course_day"]);
$course_start_time = mysql_real_escape_string($_POST["course_start_time"]);
$course_end_time = mysql_real_escape_string($_POST["course_end_time"]);
$course_semester = mysql_real_escape_string($_POST["course_semester"]);
$course_credit = mysql_real_escape_string($_POST["course_credit"]);
$course_user = mysql_real_escape_string($_POST["course_user"]);


$query="UPDATE courses
            SET course_name = '$course_name', course_day = '$course_day',
            course_start_time = '$course_start_time', course_end_time = '$course_end_time', course_semester = '$course_semester',
            course_credit = '$course_credit', course_user = '$course_user'
            WHERE course_id='$ID'";


mysql_query($query)or die(mysql_error());
if(mysql_affected_rows()>=1){
    echo "<p>($ID) Record Updated<p>";
}else{
    echo "<p>($ID) Not Updated<p>";
}
?>
