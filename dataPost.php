<!--
-->
<?php
  include_once('dataAccess.php');
 
   $val1 = $val2 =   "";
 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
      
      $val1 = test_input($_POST["val1"]);
      $val2 = test_input($_POST["val2"]);
 
      $result = insertReading( $val1, $val2 );    
  }
  else {
    echo "No data posted with HTTP POST.";
  }
  function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }
 
