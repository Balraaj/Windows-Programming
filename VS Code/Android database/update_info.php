<?php

require "init.php";

$email = $_POST['email'];
$lat = $_POST['lat'];
$lng = $_POST['lng'];

$sql = "update Employee set Lat='$lat', Lng='$lng' where Email ='$email';";

if(mysqli_query($con,$sql))
{
    echo "One row is updated";
}
else
{
    echo "Error can not update data".mysqli_error($con);
}

?>