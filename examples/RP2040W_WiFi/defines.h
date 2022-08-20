/****************************************************************************************************************************
  defines.h
  For RP2040W boards using built-in

  WiFiManager_RP2040W_Lite is a library for the RP2040W boards 
  (https://github.com/khoih-prog/WiFiManager_RP2040W_Lite) to enable store Credentials in LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiManager_RP2040W_Lite
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT     Serial
#define WIFI_GENERIC_DEBUG_OUTPUT     Serial

#define _WIFI_GENERIC_LOGLEVEL_       1

#define DRD_GENERIC_DEBUG             true

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) )
  #if (_WIFI_GENERIC_LOGLEVEL_ > 3)
    #warning Use ARDUINO_RASPBERRY_PI_PICO_W and LittleFS
  #endif
#else
  #error This code is intended to run on the ARDUINO_RASPBERRY_PI_PICO_W platform! Please check your Tools->Board setting. 
#endif

/////////////////////////////////////////////

// You have to select true for the first time for any board
#define FORCE_REFORMAT            false

/////////////////////////////////////////////

// To use the default WiFi library here
#define USE_WIFI_NINA         false
#define USE_WIFI_CUSTOM       false
  
/////////////////////////////////////////////

// Add customs headers
#define USING_CUSTOMS_STYLE           true
#define USING_CUSTOMS_HEAD_ELEMENT    true
#define USING_CORS_FEATURE            true

/////////////////////////////////////////////

#define SHIELD_TYPE           "RP2040W WiFi"

#if (_WIFI_GENERIC_LOGLEVEL_ > 3)
  #warning Using WiFi.h Library defined in arduino-pico core.
#endif
  
/////////////////////////////////////////////

// Permit running CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET times before reset hardware
// to permit user another chance to config. Only if Config Data is valid.
// If Config Data is invalid, this has no effect as Config Portal will persist
#define RESET_IF_CONFIG_TIMEOUT                   true

// Permitted range of user-defined RETRY_TIMES_RECONNECT_WIFI between 2-5 times
#define RETRY_TIMES_RECONNECT_WIFI                3

// Permitted range of user-defined CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET between 2-100
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

// Config Timeout 120s (default 60s). Applicable only if Config Data is Valid
#define CONFIG_TIMEOUT                            120000L

/////////////////////////////////////////////

// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW                   false

// Max times to try WiFi per loop() iteration. To avoid blocking issue in loop()
// Default 1 if not defined, and minimum 1.
//#define MAX_NUM_WIFI_RECON_TRIES_PER_LOOP       2

// Default no interval between recon WiFi if lost
// Max permitted interval will be 10mins
// Uncomment to use. Be careful, WiFi reconnect will be delayed if using this method
// Only use whenever urgent tasks in loop() can't be delayed. But if so, it's better you have to rewrite your code, e.g. using higher priority tasks.
#define WIFI_RECON_INTERVAL                       30000

/////////////////////////////////////////////

#define USE_DYNAMIC_PARAMETERS                    true

/////////////////////////////////////////////

#define SCAN_WIFI_NETWORKS                        true

// To be able to manually input SSID, not from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED                 true

/////////////////////////////////////////////

// From 2-15
#define MAX_SSID_IN_LIST                          8

/////////////////////////////////////////////

#define USE_WIFI_RP2040W                          true

#include <WiFiManager_RP2040W_Lite.h>

#define HOST_NAME   "RP2040W-WiFi"

#if defined(LED_BUILTIN)
  #define LED_PIN     LED_BUILTIN
#else
  #define LED_PIN     13
#endif

#endif      //defines_h
