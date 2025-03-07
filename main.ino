#include "my_library.h"

#include "wifi_read.h"

// int abc = 10;   // Global Variable
// int def = 20;


//WiFi 全局变量
#include "WiFiEsp.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "wifi_name";   // your network SSID (name) 
char pass[] = "wifi_password";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiEspClient  client;


// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(19, 18); // RX, TX
#define ESP_BAUDRATE  19200
#else
#define ESP_BAUDRATE  115200
#endif

// Weather station channel details
unsigned long weatherStationChannelNumber = 12397;
unsigned int temperatureFieldNumber = 4;

// Counting channel details
unsigned long counterChannelNumber = 298725;
const char * myCounterReadAPIKey = "SODG0O2UZVGKWAWG";
unsigned int counterFieldNumber = 1; 



void setup() {
  // Serial.begin(9600);
  // int result = addTwoInts();
  // Serial.println(result);
  //WiFi void SetUp()
   //Initialize serial and wait for port to open
   Serial.begin(115200);  
   while(!Serial){
     ; // wait for serial port to connect. Needed for Leonardo native USB port only
   }
   
   // initialize serial for ESP module  
   setEspBaudRate(ESP_BAUDRATE);
 
   while (!Serial) {
     ; // wait for serial port to connect. Needed for Leonardo native USB port only
   }
 
   Serial.print("Searching for ESP8266..."); 
   // initialize ESP module
   WiFi.init(&Serial1);
 
   // check for the presence of the shield
   if (WiFi.status() == WL_NO_SHIELD) {
     Serial.println("WiFi shield not present");
     // don't continue
     while (true);
   }
   Serial.println("found it!");
     
   ThingSpeak.begin(client);  // Initialize ThingSpeak
 
}

void loop() {
  WiFi_Read();
}
