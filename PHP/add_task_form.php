<html>
<head>
    <title>Add Task</title>
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

<body>

<form action="add_task_save.php" method="post"><br>
    course_name:
    <?php
    session_start();
    # here database details
    mysql_connect('studenttask-db.my.phpcloud.com:3306', 'studenttask', 'qwerty321');
    mysql_select_db('studenttask');

    $sql = "SELECT course_name FROM courses WHERE course_user='".$_SESSION['name']."'";
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
    task_description: <input type="text" name="task_description"><br>
    receive_date: <input type="date" name="receive_date"><br>
    submission_date: <input type="date" name="submission_date"><br>
    submission_time: <input type="time" name="submission_time"><br>
    is_reminder: <input type="radio" name="is_reminder" value="1" onclick="enableElements()">Yes
    <input type="radio" name="is_reminder" value="0" onclick="disableElements()">No<br>
    reminder_date: <input type="date" name="reminder_date"><br>
    reminder_time: <input type="time" name="reminder_time"><br>
    <input type="hidden" name="task_user" value="<?=$_SESSION['name'];?>"><br>
    <input type="submit">
</form>

</body>
</html>
