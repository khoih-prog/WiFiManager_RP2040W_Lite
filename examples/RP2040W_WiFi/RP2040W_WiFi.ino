/****************************************************************************************************************************
  RP2040W_WiFi.ino
  
  For RP2040W boards using built-in

  WiFiManager_RP2040W_Lite is a library for the RP2040W boards 
  (https://github.com/khoih-prog/WiFiManager_RP2040W_Lite) to enable store Credentials in LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiManager_RP2040W_Lite
  Licensed under MIT license
  *****************************************************************************************************************************/

#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

WiFiManager_RP2040W_Lite* WiFiManager_RP2040W;

void heartBeatPrint()
{
  static int num = 1;

  // Must use with WiFiConnected() to fix WiFi.status() bug in the cyw43 library or arduino-pico core
  if ( (WiFi.status() == WL_CONNECTED) )
  //if ( WiFiManager_RP2040W->WiFiConnected() )
    Serial.print("H");        // H means connected to WiFi
  else
    Serial.print("F");        // F means not connected to WiFi

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(" ");
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

  //KH
#define HEARTBEAT_INTERVAL    20000L
  // Print hearbeat every HEARTBEAT_INTERVAL (20) seconds.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    heartBeatPrint();
    checkstatus_timeout = millis() + HEARTBEAT_INTERVAL;
  }
}

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  delay(1000);

  Serial.print("\nStart RP2040W_WiFi on "); Serial.print(BOARD_NAME);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(WIFIMULTI_GENERIC_VERSION);
  Serial.println(WIFI_MANAGER_RP2040W_LITE_VERSION);

  WiFiManager_RP2040W = new WiFiManager_RP2040W_Lite();

  // RP2040W AP IP is fixed @ 192.168.42.1
  // Channel is also fixed
  // Optional to change default AP IP(192.168.4.1) and channel(10)
  //WiFiManager_RP2040W->setConfigPortalIP(IPAddress(192, 168, 120, 1));
  //WiFiManager_RP2040W->setConfigPortalChannel(0);

#if USING_CUSTOMS_STYLE
  WiFiManager_RP2040W->setCustomsStyle(NewCustomsStyle);
#endif

#if USING_CUSTOMS_HEAD_ELEMENT
  WiFiManager_RP2040W->setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
#endif

#if USING_CORS_FEATURE  
  WiFiManager_RP2040W->setCORSHeader("Your Access-Control-Allow-Origin");
#endif

  // Set customized DHCP HostName
  WiFiManager_RP2040W->begin(HOST_NAME);
  //Or use default Hostname "RP2040W_WiFi"
  //WiFiManager_RP2040W->begin();
}

#if USE_DYNAMIC_PARAMETERS
void displayCredentials()
{
  Serial.println("\nYour stored Credentials :");

  for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.print(myMenuItems[i].displayName);
    Serial.print(" = ");
    Serial.println(myMenuItems[i].pdata);
  }
}

void displayCredentialsInLoop()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
}

#endif

void loop()
{
  WiFiManager_RP2040W->run();
  check_status();

#if USE_DYNAMIC_PARAMETERS
  displayCredentialsInLoop();
#endif  
}
