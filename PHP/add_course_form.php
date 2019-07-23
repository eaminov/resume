<html>
<head>
    <title>Add Course</title>
</head>
<body>
<?php
session_start()
?>
<form action="add_course_save.php" method="post"><br>

    course_name: <input type="text" name="course_name"><br>
    course_day: <select name="course_day">
    <option value="Sunday">Sunday</option>
    <option value="Monday">Monday</option>
    <option value="Tuesday">Tuesday</option>
    <option value="Wednesday">Wednesday</option>
    <option value="Thursday">Thursday</option>
    <option value="Friday">Friday</option>
    </select><br>
    course_start_time: <input type="time" name="course_start_time"><br>
    course_end_time: <input type="time" name="course_end_time"><br>
    course_semester: <select name="course_semester">
        <option value="A">A</option>
        <option value="B">B</option>
        <option value="C">C</option>
    </select><br>
    course_credit: <select name="course_credit">
        <option value="1">1</option>
        <option value="2">2</option>
        <option value="3">3</option>
        <option value="4">4</option>
        <option value="5">5</option>
        <option value="6">6</option>
    <input type="hidden" name="course_user" value="<?=$_SESSION['name'];?>"><br>
<input type="submit">
</form>
</body>
</html>