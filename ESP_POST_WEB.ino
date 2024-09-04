/**********************************************************
7 Aug 2024
Simple Framework to test data sent from ESP32 to Cloud Web  page.
Led is introduced for debugging purpose

 **************************************************************/
// Import required libraries

#include <WiFi.h>
#include <HTTPClient.h>

//************************************************

#define WiFi_timeout 10000  // 10sec Wifi connection timeout
//*****************************************

float val1 = 11.22;  // random values for test purpose
float val2 = 33.44;  // random values for test purpose
const int LED_BUILTIN = 4;
//********************************************************************
  
//---------------------------------------------------------
// Domain_name with URL_path or IP address with path
//const char* serverName = "http://yourWebSite/dataPost.php";
const char* serverName = "http://xxx.xxx.xxx.xxx/dataPost.php";

//************************************************************

WiFiClient client;
HTTPClient http;

const char* ssid  = "xxxxxxxx";  // Your network SSID
const char* password  = "xxxx";  // Your network password
//----------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

pinMode(LED_BUILTIN, OUTPUT);    
digitalWrite(LED_BUILTIN, LOW);      // Visual indicator
digitalWrite(LED_BUILTIN, HIGH);
delay(100);
 
//*******************************************************************
WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi 1..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
Serial.print(" Local IP:      ");
Serial.println(WiFi.localIP());
Serial.println("Title: ESP > POST > WEB ");
 
WiFi.mode(WIFI_STA);   
 
 // server Connecting
 //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);

      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  //     String httpRequestData = "&temp=31.31&humi=88.88"; Sample formats 
  //     Will be explained in future Post

String httpRequestData =      
                        "&val1=" + String(val1) +
                        "&val2=" + String(val2) + "";

      // Send HTTP POST request
       int httpResponseCode = http.POST(httpRequestData);


      Serial.print("httpRequestData: ");
      Serial.println(httpRequestData);
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
      
    }

  digitalWrite(LED_BUILTIN, LOW);
   
     
  delay(500) ;
  Serial.println("-----------Setup End------------------");
  Serial.flush(); 
   
 
}


//******************************************************************

//---------------------------------------------------
//*****************************************************************

void loop() {

 vTaskDelay(portMAX_DELAY); // wait as much as posible ...
}
