<?php
$db_host = "127.0.0.1";
$db_username = "mhalaouie";
$db_pass = "fsxtp4cx";
$db_name = "mhalaouie";


$dbc = mysqli_connect( $db_host, $db_username, $db_pass, $db_name );

$mysqli = new mysqli($db_host, $db_username, $db_pass, $db_name);
// Check connection
if ($mysqli->connect_error) {
    die("Connection failed: " . $mysqli->connect_error);
}