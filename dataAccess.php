 <!--
  
 -->
<?php
    
   $serverName = "localhost";
   $userName = "root";
   $passWord = "";
   $dbName = "xx_db";

//--------------------------------------------------
function getReadings(){
  global $serverName, $userName, $passWord, $dbName ;
  // Create connection
$vCon= new mysqli($serverName, $userName, $passWord, $dbName);
// Check connection
if ($vCon->connect_error) {
  die("Connection failed: " . $vCon->connect_error);
}

$sql = "SELECT id, val1,val2 FROM  xx_tbl order by id DESC limit 1" ;
if ($result = $vCon->query($sql)) {
  return $result->fetch_assoc();
}
else {
  return false;
}


$vCon->close();
}

//----------------------------------------------------------
function insertReading(  $val1, $val2) {
  global $serverName, $userName, $passWord, $dbName;

  // Create connection
  $vCon= new mysqli($serverName, $userName, $passWord, $dbName);
  // Check connection
  if ($vCon->connect_error) {
    die("Connection failed: " . $vCon->connect_error);
  }

  $sql = "INSERT INTO xx_tbl (val1, val2)
  VALUES ( '" . $val1 . "', '" . $val2 . "')";

  if ($vCon->query($sql) === TRUE) {
    return "New record created successfully";
  }
  else {
    return "Error: " . $sql . "<br>" . $vCon->error;
  }
  $vCon->close();
}

//-------------------------------------------------------------
?>
