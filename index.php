   <!--      
  -->
  <?php
   include_once('dataAccess.php');      
      
      $reading = getReadings();       
      $reading_val1 = $reading["val1"];
      $reading_val2 = $reading["val2"];        
  ?>
  
  <!DOCTYPE html>
  <html>
      <head><meta http-equiv="Content-Type" content="text/html; charset=utf-8">
          
       <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
      </head>
      <header class="header">
          <h1> Data Display</h1>
           
      </header>
  <body>
             <p> Value 1 :<?php echo $reading_val1?></p>
             <p> Value 2 :<?php echo $reading_val2?></p>
   

  </body>
  </html>
 
