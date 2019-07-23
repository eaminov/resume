<?php
mysql_connect("studenttask-db.my.phpcloud.com","studenttask","qwerty321") or die(mysql_error());
mysql_select_db("studenttask") or die(mysql_error());

$UID = (int)$_GET['course_id'];
$query = mysql_query("SELECT * FROM courses WHERE course_id = '$UID'") or die(mysql_error());

if(mysql_num_rows($query)>=1){
    while($row = mysql_fetch_array($query)) {
        $course_id = $row['course_id'];
        $course_name = $row['course_name'];
        $course_day = $row['course_day'];
        $course_start_time = $row['course_start_time'];
        $course_end_time = $row['course_end_time'];
        $course_semester = $row['course_semester'];
        $course_credit = $row['course_credit'];
        $course_user = $row['course_user'];
    }
    ?>
    <form action="update_course.php" method="post">
        <input type="hidden" name="ID" value="<?=$UID;?>">
        <input type="hidden" name="course_id" value="<?=$course_id;?>"><br>
        course_name: <input type="text" name="course_name" value="<?=$course_name;?>"><br>
        course_day: <select name="course_day">
            <option<?= $course_day == "Sunday" ? ' selected="selected"' : ''?>>Sunday</option>
            <option<?= $course_day == "Monday" ? ' selected="selected"' : ''?>>Monday</option>
            <option<?= $course_day == "Tuesday" ? ' selected="selected"' : ''?>>Tuesday</option>
            <option<?= $course_day == "Wednesday" ? ' selected="selected"' : ''?>>Wednesday</option>
            <option<?= $course_day == "Thursday" ? ' selected="selected"' : ''?>>Thursday</option>
            <option<?= $course_day == "Friday" ? ' selected="selected"' : ''?>>Friday</option>
        </select><br>
        course_start_time: <input type="time" name="course_start_time" value="<?=$course_start_time;?>"><br>
        course_end_time: <input type="time" name="course_end_time" value="<?=$course_end_time;?>"><br>
        course_semester: <select name="course_semester">
            <option<?= $course_semester == "A" ? ' selected="selected"' : ''?>>A</option>
            <option<?= $course_semester == "B" ? ' selected="selected"' : ''?>>B</option>
            <option<?= $course_semester == "C" ? ' selected="selected"' : ''?>>C</option>
        </select><br>
        course_credit: <select name="course_credit">
            <option<?= $course_credit == "1" ? ' selected="selected"' : ''?>>1</option>
            <option<?= $course_credit == "2" ? ' selected="selected"' : ''?>>2</option>
            <option<?= $course_credit == "3" ? ' selected="selected"' : ''?>>3</option>
            <option<?= $course_credit == "4" ? ' selected="selected"' : ''?>>4</option>
            <option<?= $course_credit == "5" ? ' selected="selected"' : ''?>>5</option>
            <option<?= $course_credit == "6" ? ' selected="selected"' : ''?>>6</option>
        </select><br>
        <input type="hidden" name="course_user" value="<?=$course_user;?>"><br>
        <input type="Submit">
    </form>
<?php
}else{
    echo 'No entry found. <a href="javascript:history.back()">Go back</a>';
}
?>

