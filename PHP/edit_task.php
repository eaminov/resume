<html>
<head>
    <title>Edit Task</title>
    <script>
        function enableElements()
        {
            document.getElementsByName("reminder_date")[0].disabled=false;
            document.getElementsByName("reminder_time")[0].disabled=false;
        }

        function disableElements()
        {
            document.getElementsByName("reminder_date")[0].disabled=true;
            document.getElementsByName("reminder_time")[0].disabled=true;
        }
    </script>
</head>
</html>
<?php
session_start();
mysql_connect("studenttask-db.my.phpcloud.com","studenttask","qwerty321") or die(mysql_error());
mysql_select_db("studenttask") or die(mysql_error());

$UID = (int)$_GET['task_id'];
$query = mysql_query("SELECT * FROM tasks WHERE task_id = '$UID'") or die(mysql_error());

if(mysql_num_rows($query)>=1){
    while($row = mysql_fetch_array($query)) {
        $task_id = $row['task_id'];
        $course_name = $row['course_name'];
        $task_description = $row['task_description'];
        $receive_date = $row['receive_date'];
        $submission_date = $row['submission_date'];
        $submission_time = $row['submission_time'];
        $is_reminder = $row['is_reminder'];
        $reminder_date = $row['reminder_date'];
        $reminder_time = $row['reminder_time'];
        $task_user = $row['task_user'];
    }
    ?>
    <form action="update_task.php" method="post"><br>
        <input type="hidden" name="ID" value="<?=$UID;?>">
        <input type="hidden" name="task_id" value="<?=$task_id;?>"><br>
        course_name:
        <?php
        session_start();
        # here database details
        mysql_connect('studenttask-db.my.phpcloud.com:3306', 'studenttask', 'qwerty321');
        mysql_select_db('studenttask');

        $sql = "SELECT course_name FROM tasks WHERE course_user='".$_SESSION['name']."'";
        $result = mysql_query($sql);

        echo "<select name='course_name'>";
        while ($row = mysql_fetch_array($result)) {
            echo "<option value='" . $row['course_name'] ."'>" . $row['course_name'] ."</option>";
        }
        echo "</select>";

        # here username is the column of my table(userregistration)
        # it works perfectly
        ?>
        <br>
        task_description: <input type="text" name="task_description" value="<?=$task_description;?>"><br>
        receive_date: <input type="date" name="receive_date" value="<?=$receive_date;?>"><br>
        submission_date: <input type="date" name="submission_date" value="<?=$submission_date;?>"><br>
        submission_time: <input type="time" name="submission_time" value="<?=$submission_time;?>"><br>
        is_reminder: <input type="radio" name="is_reminder" value="1" onclick="enableElements()" <?= $is_reminder == "1" ? ' checked="checked"' : ''?>>Yes
        <input type="radio" name="is_reminder" value="0" onclick="disableElements()" <?= $is_reminder == "0" ? ' checked="checked"' : ''?>>No<br>
        reminder_date: <input type="date" name="reminder_date" value="<?=$reminder_date;?>"><br>
        reminder_time: <input type="time" name="reminder_time" value="<?=$reminder_time;?>"><br>
        <input type="hidden" name="task_user" value="<?=$_SESSION['name'];?>"><br>
        <input type="submit">
    </form>
<?php
}else{
    echo 'No entry found. <a href="javascript:history.back()">Go back</a>';
}
?>

