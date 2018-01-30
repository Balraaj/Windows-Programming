<?php
require init.php

$id = $_POST["id"];
$name = $_POST["name"];
$age = $_POST["age"];

$sql = "insert into Employee values('$id','$name','$age');";

if(mysql_query($sql,$con))
{
    echo "<h3>One row is inserted</h3>"
}
else
{
    echo "Error in insertion".mysql_error($con);
}

?>