<?php

$host = "locato.000webhostapp.com";
$db = "id1168215_mydb";
$user = "id1168215_balraaj";
$password = "1234@me1";

$con = mysqli_connect($host,$user,$password,$db);

if(!$con)
{
    die("Error in connection".mysqli_connect_error());
}

else
{
   echo<h3>Connection is successful</h3> 


?>