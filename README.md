## WiFiManager_RP2040W_Lite (Light Weight Credentials / WiFi Manager for RP2040W built-in CYW43439 WiFi)

[![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiManager_RP2040W_Lite.svg?)](https://www.ardu-badge.com/WiFiManager_RP2040W_Lite)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiManager_RP2040W_Lite.svg)](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WiFiManager_RP2040W_Lite.svg)](http://github.com/khoih-prog/WiFiManager_RP2040W_Lite/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-WiFiManager_RP2040W_Lite/count.svg" title="WiFiManager_RP2040W_Lite Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-WiFiManager_RP2040W_Lite/count.svg" style="height: 30px;width: 200px;"></a>


---
---

## Table of Contents

* [Why do we need this WiFiManager_RP2040W_Lite library](#why-do-we-need-this-WiFiManager_RP2040W_Lite-library)
  * [Features](#features)
  * [WiFiMulti_Generic library usage](#WiFiMulti_Generic-library-usage)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#currently-supported-wifi-shieldsmodules)
* [Changelog](changelog.md) 
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [How It Works](#how-it-works)
* [How to use](#how-to-use)
  * [ 1. Basic usage](#1-basic-usage)
  * [ 2. Add custom parameters](#2-add-custom-parameters)
  * [ 3. Not using custom parameters](#3-not-using-custom-parameters)
  * [ 4. To open Config Portal](#4-to-open-config-portal)
  * [ 5. To use different AP WiFi Channel](#5-to-use-different-ap-wifi-channel)
  * [ 6. To use different static AP IP from default](#6-to-use-different-static-ap-ip-from-default)
  * [ 7. To use custom DHCP HostName](#7-to-use-custom-dhcp-hostname)
  * [ 8. To use custom HTML Style](#8-to-use-custom-html-style)
  * [ 9. To use custom Head Elements](#9-to-use-custom-head-elements)
  * [10. To use CORS Header](#10-to-use-cors-header)
  * [11. To use and input only one set of WiFi SSID and PWD](#11-to-use-and-input-only-one-set-of-wifi-ssid-and-pwd)
    * [11.1 If you need to use and input only one set of WiFi SSID/PWD](#111-if-you-need-to-use-and-input-only-one-set-of-wifi-ssidpwd)
    * [11.2 If you need to use both sets of WiFi SSID/PWD](#112-if-you-need-to-use-both-sets-of-wifi-ssidpwd)
  * [12. To enable auto-scan of WiFi networks for selection in Configuration Portal](#12-to-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal](#121-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.2 Disable manually input SSIDs](#122-disable-manually-input-ssids)
    * [12.3 Select maximum number of SSIDs in the list](#123-select-maximum-number-of-ssids-in-the-list)
  * [13. To avoid blocking in loop when WiFi is lost](#13-To-avoid-blocking-in-loop-when-wifi-is-lost)
    * [13.1 Max times to try WiFi per loop](#131-max-times-to-try-wifi-per-loop)
    * [13.2 Interval between reconnection WiFi if lost](#132-interval-between-reconnection-wifi-if-lost) 
* [Examples](#examples)
  * [ 1. RP2040W_WiFi](examples/RP2040W_WiFi)
  * [ 2. RP2040W_WiFi_MQTT](examples/RP2040W_WiFi_MQTT)
* [So, how it works?](#so-how-it-works)
  * [1. Without SCAN_WIFI_NETWORKS](#1-without-scan_wifi_networks)
  * [2. With SCAN_WIFI_NETWORKS](#2-with-scan_wifi_networks)
* [Important Notes](#important-notes)
* [How to use default Credentials and have them pre-loaded onto Config Portal](#how-to-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [1. To always load Default Credentials and override Config Portal data](#1-to-always-load-default-credentials-and-override-config-portal-data)
  * [2. To load Default Credentials when there is no valid Credentials](#2-to-load-default-credentials-when-there-is-no-valid-credentials)
  * [3. Example of Default Credentials](#3-example-of-default-credentials)
* [How to add dynamic parameters from sketch](#how-to-add-dynamic-parameters-from-sketch)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Example RP2040W_WiFi](#example-RP2040W_WiFi)
  * [1. File RP2040W_WiFi.ino](#1-file-RP2040W_WiFiino)
  * [2. File defines.h](#2-file-definesh)
  * [3. File Credentials.h](#3-file-credentialsh)
  * [4. File dynamicParams.h](#4-file-dynamicparamsh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. RP2040W_WiFi example on RP2040W](#1-RP2040W_wifi-example-on-RP2040W) 
    * [1.1 Open Config Portal](#11-open-config-portal)
    * [1.2 Got valid Credential from Config Portal, then connected to WiFi](#12-got-valid-credential-from-config-portal-then-connected-to-wifi)
  * [2. RP2040W_WiFi_MQTT on RP2040W](#2-RP2040W_wifi_mqtt-on-RP2040W) 
    * [2.1 Open Config Portal](#21-open-config-portal)
    * [2.2 Got valid Credential from Config Portal, then connected to WiFi and AIO MQTT](#22-got-valid-credential-from-config-portal-then-connected-to-wifi-and-aio-mqtt)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---


### Why do we need this [WiFiManager_RP2040W_Lite library](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite)

#### Features

If you have used the full-fledge WiFiManager such as :

1. [`Tzapu WiFiManager`](https://github.com/tzapu/WiFiManager)
2. [`Ken Taylor WiFiManager`](https://github.com/kentaylor/WiFiManager)
3. [`Khoi Hoang ESP_WiFiManager`](https://github.com/khoih-prog/ESP_WiFiManager)

and have to write **complicated callback functions** to save custom parameters in LittleFS, you'd appreciate the simplicity of this Light-Weight Credentials / WiFiManager.

This library is a Light Weight Credentials / WiFi Manager for **RP2040W** with built-in CYW43439 WiFi modules/shields.

This is a Credentials / WiFi Connection Manager, permitting the addition of custom parameters to be configured in Config Portal. The parameters then will be saved automatically, **without the complicated callback functions** to handle data saving / retrieving.

You can also specify DHCP HostName, static AP and STA IP. Use much less memory compared to full-fledge WiFiManager. Config Portal will be auto-adjusted to match the number of dynamic custom parameters. Credentials are saved in LittleFS, shared with [**DoubleResetDetector_Generic** library](https://github.com/khoih-prog/DoubleResetDetector_Generic).

The web configuration portal, served from the `Generic WiFi modules/shields` is operating as an access point (AP) with configurable static IP address or use default IP Address of **192.168.42.1**

New recent features:

- **MultiWiFi** feature for configuring/auto(re)connecting **Portenta WiFi** shields to the available MultiWiFi APs at runtime.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- **Powerful-yet-simple-to-use feature to enable adding dynamic custom parameters** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
- Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
- Dynamic custom parameters to be saved **automatically in non-volatile LittleeFS memory**.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are designed to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
- Control Config Portal from software or Virtual Switches
- To permit autoreset after configurable timeout if DRD/MRD or non-persistent forced-CP
- Use new RP2040W LittleFS features
- **Scan WiFi networks** for selection in Configuration Portal

---

#### WiFiMulti_Generic library usage

The usage the new [WiFiMulti_Generic](https://github.com/khoih-prog/WiFiMulti_Generic) library to help connect to the best of **multi-WiFi APs**, with **auto-checking / auto-reconnecting** features when WiFi connection is lost.



---

#### Currently supported Boards

This [**WiFiManager_RP2040W_Lite** library](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite) currently supports these following boards:

 1. **RASPBERRY_PI_PICO_W** boards, using CYW43439 WiFi with [`arduino-pico core v2.4.0+`](https://github.com/earlephilhower/arduino-pico)

---

#### Currently supported WiFi shields/modules

1. Built-in CYW43439 WiFi

---
---


## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
2. [`Earle Philhower's arduino-pico core v2.6.3+`](https://github.com/earlephilhower/arduino-pico) for **RASPBERRY_PI_PICO_W with CYW43439 WiFi**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
3. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
4. [`WiFiWebServer library v1.10.0+`](https://github.com/khoih-prog/WiFiWebServer). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
5. [`DoubleResetDetector_Generic v1.8.1+`](https://github.com/khoih-prog/DoubleResetDetector_Generic). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic)
6. [`WiFiMulti_Generic library v1.2.2+`](https://github.com/khoih-prog/WiFiMulti_Generic) to use WiFiMulti function. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiMulti_Generic.svg?)](https://www.ardu-badge.com/WiFiMulti_Generic).

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**WiFiManager_RP2040W_Lite**](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiManager_RP2040W_Lite.svg?)](https://www.ardu-badge.com/WiFiManager_RP2040W_Lite) for more detailed instructions.

### Manual Install

1. Navigate to [**WiFiManager_RP2040W_Lite**](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite) page.
2. Download the latest release `WiFiManager_RP2040W_Lite-main.zip`.
3. Extract the zip file to `WiFiManager_RP2040W_Lite-main` directory 
4. Copy the whole 
  - `WiFiManager_RP2040W_Lite-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WiFiManager_RP2040W_Lite** library](https://registry.platformio.org/libraries/khoih-prog/WiFiManager_RP2040W_Lite) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/WiFiManager_RP2040W_Lite/installation). Search for **WiFiManager_RP2040W_Lite** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


## How It Works

- The [**RP2040W_WiFi**](examples/RP2040W_WiFi) example shows how it works and should be used as the basis for a sketch that uses this library.
- The concept of [**RP2040W_WiFi**](examples/RP2040W_WiFi) is that a new `WiFi module/shield` will start a WiFi configuration portal when powered up, but has no valid stored Credentials or can't connect to WiFi APs after a pre-determined time.
- There are 6 more custom parameters added in the sketch which you can use in your program later. In the example, they are: 2 sets of Blynk Servers and Tokens, Blynk Port and MQTT Server.
- Using any WiFi enabled device with a browser (computer, phone, tablet) connect to the newly created AP and type in the configurable AP IP address (default `192.168.42.1`). The Config Portal AP channel **is not configurable** because of limitation of the cyc43 WiFi library.
- The Config Portal is **auto-adjusted** to fix the 4 static parameters (WiFi SSIDs/PWDs) as well as 6 more dynamic custom parameters.
- After the custom data entered, and **Save** button pressed, the configuration data will be saved in host's non-volatile memory, then the board reboots.
- If there is valid stored Credentials, it'll go directly to connect to one of the **MultiWiFi APs** without starting / using the Config Portal.
- `Generic WiFi module/shield` will try to connect. If successful, the dynamic DHCP and/or configured static IP address will be displayed in the configuration portal. 
- The `Generic WiFi module/shield` WiFi Config Portal network and Web Server will shutdown to return control to the sketch code.
- In the operation, if the current WiFi connection is lost because of any reason, the system will **auto(Re)connect** to the remaining WiFi AP.
- **If system can't connect to any of the 2 WiFi APs, the Config Portal will start**, after some pre-determined time, to permit user to update the Credentials.

---

### How to use

#### 1. Basic usage

- Include in your sketch

```cpp
#include <WiFiManager_RP2040W_Lite.h>

WiFiManager_RP2040W_Lite* WiFiManager_RP2040W;
```

#### 2. Add custom parameters

- To add custom parameters, just add

```cpp
#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defines.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_RP2040W_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_BLYNK_SERVER_LEN      34
#define MAX_BLYNK_TOKEN_LEN       34

char Blynk_Server1 [MAX_BLYNK_SERVER_LEN + 1]  = "account.duckdns.org";
char Blynk_Token1  [MAX_BLYNK_TOKEN_LEN + 1]   = "token1";

char Blynk_Server2 [MAX_BLYNK_SERVER_LEN + 1]  = "account.ddns.net";
char Blynk_Token2  [MAX_BLYNK_TOKEN_LEN + 1]   = "token2";

#define MAX_BLYNK_PORT_LEN        6
char Blynk_Port   [MAX_BLYNK_PORT_LEN + 1]  = "8080";

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "mqtt.duckdns.org";

MenuItem myMenuItems [] =
{
  { "sv1", "Blynk Server1", Blynk_Server1,  MAX_BLYNK_SERVER_LEN },
  { "tk1", "Token1",        Blynk_Token1,   MAX_BLYNK_TOKEN_LEN },
  { "sv2", "Blynk Server2", Blynk_Server2,  MAX_BLYNK_SERVER_LEN },
  { "tk2", "Token2",        Blynk_Token2,   MAX_BLYNK_TOKEN_LEN },
  { "prt", "Port",          Blynk_Port,     MAX_BLYNK_PORT_LEN },
  { "mqt", "MQTT Server",   MQTT_Server,    MAX_MQTT_SERVER_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

```

#### 3. Not using custom parameters

- If you don't need to add dynamic parameters, use the following in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS      false
```

#### 4. To open Config Portal

- When you want to open a config portal, just add

```cpp
WiFiManager_RP2040W = new WiFiManager_RP2040W_Lite();
WiFiManager_RP2040W->begin();
```

#### 5. To use different AP WiFi Channel

##### Not working now because cyw43 WiFi library limitation.

- To not use default AP WiFi Channel 10 to avoid conflict with other WiFi APs : 

```cpp
WiFiManager_RP2040W->setConfigPortalChannel(newChannel);
```

- To use random AP WiFi Channel to avoid conflict with other WiFi APs : 

```cpp
WiFiManager_RP2040W->setConfigPortalChannel(0);
```

#### 6. To use different static AP IP from default

##### Not working now because cyw43 WiFi library limitation. Fixed at 192.168.42.1

- To use different static AP IP (not use default `192.168.42.1`), call

```cpp
WiFiManager_RP2040W->setConfigPortalIP(IPAddress(xxx,xxx,xxx,xxx));
```

#### 7. To use custom DHCP HostName

- To set custom DHCP HostName :
 
```cpp
// Set customized DHCP HostName
WiFiManager_RP2040W->begin("SAMD_ABCDEF");
```
 
or just use the default Hostname, for example "SAMD_XXXXXX" for SAMD

```cpp
//Or use default Hostname "WIFI_GENERIC_XXXXXX"
//WiFiManager_RP2040W->begin();
```

#### 8. To use custom HTML Style

```cpp
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

WiFiManager_RP2040W->setCustomsStyle(NewCustomsStyle);
```

#### 9. To use custom Head Elements


```cpp
WiFiManager_RP2040W->setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 10. To use CORS Header

```cpp
WiFiManager_RP2040W->setCORSHeader("Your Access-Control-Allow-Origin");
```

While in AP mode, connect to it using its `SSID` (WIFI_GENERIC_XXXXXX) / `Password` ("MyWIFI_GENERIC_XXXXXX"), then open a browser to the Portal AP IP, default `192.168.42.1`, configure wifi then click **Save**. The Credentials / WiFi connection information will be saved in non-volatile memory. It will then autoconnect.


Once Credentials / WiFi network information is saved in the host non-volatile memory, it will try to autoconnect to WiFi every time it is started, without requiring any function calls in the sketch.


#### 11. To use and input only one set of WiFi SSID and PWD

#### 11.1 If you need to use and input only one set of WiFi SSID/PWD

```cpp
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       true
```
But it's always advisable to use and input both sets for reliability.
 
#### 11.2 If you need to use both sets of WiFi SSID/PWD

```cpp
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false
```

#### 12. To enable auto-scan of WiFi networks for selection in Configuration Portal

#### 12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal


```cpp
#define SCAN_WIFI_NETWORKS                  true
```

The manual input of SSIDs is default enabled, so that users can input arbitrary SSID, not only from the scanned list. This is for the sample use-cases in which users can input the known SSIDs of another place, then send the boards to that place. The boards can connect to WiFi without users entering Config Portal to re-configure.

#### 12.2 Disable manually input SSIDs

```cpp
// To disable manually input SSID, only from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           false
```

This is for normal use-cases in which users can only select an SSID from a scanned list of SSIDs to avoid typo mistakes and/or security.

#### 12.3 Select maximum number of SSIDs in the list

The maximum number of SSIDs in the list is selectable from 2 to 15 (for ESP8266/ESP32-AT shields, from 2-6). If invalid number of SSIDs is selected, the default number of 10 will be used.


```cpp
// From 2-15
#define MAX_SSID_IN_LIST                    8
```

#### 13. To avoid blocking in loop when WiFi is lost


#### 13.1 Max times to try WiFi per loop

To define max times to try WiFi per loop() iteration. To avoid blocking issue in loop()

Default is 1 if not defined, and minimum is forced to be 1.

To use, uncomment in `defines.h`. 

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issue-1094004380)

```cpp
#define MAX_NUM_WIFI_RECON_TRIES_PER_LOOP     2
```

#### 13.2 Interval between reconnection WiFi if lost

Default is no interval between reconnection WiFi times if lost WiFi. Max permitted interval will be 10mins.

Uncomment to use. Be careful, WiFi reconnection will be delayed if using this method.

Only use whenever urgent tasks in loop() can't be delayed. But if so, it's better you have to rewrite your code, e.g. using higher priority tasks.

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issuecomment-1006197561)

```cpp
#define WIFI_RECON_INTERVAL                   30000     // 30s
```



---
---

### Examples

 1. [RP2040W_WiFi](examples/RP2040W_WiFi)
 2. [RP2040W_WiFi_MQTT](examples/RP2040W_WiFi_MQTT)
 
---
---

## So, how it works?

In `Configuration Portal Mode`, it starts an AP called `RP2040W_XXXXXX`. Connect to it using the `configurable password` you can define in the code. For example, `MyRP2040W_XXXXXX` (see examples):

After you connected, please, go to http://192.168.3.1, you'll see this `Main` page:

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/Main.png">
</p>

Enter your credentials, 

### 1. Without SCAN_WIFI_NETWORKS

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/Input.png">
</p>

### 2. With SCAN_WIFI_NETWORKS


<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/Input_With_Scan.png">
</p>


then click `Save`. 

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/Save.png">
</p>

The WiFi Credentials will be saved and the board connect to the selected WiFi AP.

If you're already connected to a listed WiFi AP and don't want to change anything, just select `Exit` from the `Main` page to reboot the board and connect to the previously-stored AP. The WiFi Credentials are still intact.

---

### Important Notes

1. Now you can use special chars such as **~, !, @, #, $, %, ^, &, _, -, space,etc.** thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix in [**Blynk_WM**](https://github.com/khoih-prog/Blynk_WM) to permit input special chars such as **%** and **#** into data fields. See [Issue 3](https://github.com/khoih-prog/Blynk_WM/issues/3).
2. The SSIDs, Passwords must be input (or to make them different from **blank**). Otherwise, the Config Portal will re-open until those fields have been changed. If you don't need any field, just input anything or use duplicated data from similar field.
3. WiFi password max length now is 63 chars according to WPA2 standard.

---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To always load [Default Credentials](examples/RP2040W_WiFi/Credentials.h) and override Config Portal data

```cpp
// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To load [Default Credentials](examples/RP2040W_WiFi/Credentials.h) when there is no valid Credentials.

Config Portal data input will be override DEFAULT_CONFIG_DATA

```cpp
// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](examples/RP2040W_WiFi/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
#define SSID_MAX_LEN      32
//From v1.0.3, WPA2 passwords can be up to 63 characters long.
#define PASS_MAX_LEN      64

typedef struct
{
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
}  WiFi_Credentials;

#define NUM_WIFI_CREDENTIALS      2

// Configurable items besides fixed Header, just add board_name 
#define NUM_CONFIGURABLE_ITEMS    ( ( 2 * NUM_WIFI_CREDENTIALS ) + 1 )
////////////////

typedef struct Configuration
{
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  char board_name     [24];
  int  checkSum;
} WIFI_GENERIC_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      false

#if TO_LOAD_DEFAULT_CONFIG_DATA

// This feature is primarily used in development to force a known set of values as Config Data
// It will NOT force the Config Portal to activate. Use DRD or erase Config Data with Blynk.clearConfigData()

// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
//bool LOAD_DEFAULT_CONFIG_DATA = true;

// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;


WIFI_GENERIC_Configuration defaultConfig =
{
  //char header[16], dummy, not used
  "RP2040W_WIFI",
  // WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  // WiFi_Credentials.wifi_ssid and WiFi_Credentials.wifi_pw
  "SSID1",  "password1",
  "SSID2",  "password2",
  //char board_name     [24];
  "RP2040W-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

WIFI_GENERIC_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

### How to add dynamic parameters from sketch

Example of [Default dynamicParams](examples/RP2040W_WiFi/dynamicParams.h)

- To add custom parameters, just modify the example below

```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_RP2040W_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_BLYNK_SERVER_LEN      34
#define MAX_BLYNK_TOKEN_LEN       34

char Blynk_Server1 [MAX_BLYNK_SERVER_LEN + 1]  = "account.duckdns.org";
char Blynk_Token1  [MAX_BLYNK_TOKEN_LEN + 1]   = "token1";

char Blynk_Server2 [MAX_BLYNK_SERVER_LEN + 1]  = "account.ddns.net";
char Blynk_Token2  [MAX_BLYNK_TOKEN_LEN + 1]   = "token2";

#define MAX_BLYNK_PORT_LEN        6
char Blynk_Port   [MAX_BLYNK_PORT_LEN + 1]  = "8080";

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "mqtt.duckdns.org";

MenuItem myMenuItems [] =
{
  { "sv1", "Blynk Server1", Blynk_Server1,  MAX_BLYNK_SERVER_LEN },
  { "tk1", "Token1",        Blynk_Token1,   MAX_BLYNK_TOKEN_LEN },
  { "sv2", "Blynk Server2", Blynk_Server2,  MAX_BLYNK_SERVER_LEN },
  { "tk2", "Token2",        Blynk_Token2,   MAX_BLYNK_TOKEN_LEN },
  { "prt", "Port",          Blynk_Port,     MAX_BLYNK_PORT_LEN },
  { "mqt", "MQTT Server",   MQTT_Server,    MAX_MQTT_SERVER_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS


#endif      //dynamicParams_h

```
- If you don't need to add dynamic parameters, use the following in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS     false
```

or

```cpp
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```
---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"id"    for WiFi SSID
"pw"    for WiFi PW
"id1"   for WiFi1 SSID
"pw1"   for WiFi1 PW
"nm"    for Board Name
```
---
---

### Example [RP2040W_WiFi](examples/RP2040W_WiFi)

Please take a look at other examples, as well.

#### 1. File [RP2040W_WiFi.ino](examples/RP2040W_WiFi/RP2040W_WiFi.ino)

https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/1ed5de2a5882836f7acf85b264798cd645955563/examples/RP2040W_WiFi/RP2040W_WiFi.ino#L14-L145


---

#### 2. File [defines.h](examples/RP2040W_WiFi/defines.h)

https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/1ed5de2a5882836f7acf85b264798cd645955563/examples/RP2040W_WiFi/defines.h#L13-L120


---

#### 3. File [Credentials.h](examples/RP2040W_WiFi/Credentials.h)

https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/1ed5de2a5882836f7acf85b264798cd645955563/examples/RP2040W_WiFi/Credentials.h#L13-L89


---

#### 4. File [dynamicParams.h](examples/RP2040W_WiFi/dynamicParams.h)

https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/1ed5de2a5882836f7acf85b264798cd645955563/examples/RP2040W_WiFi/dynamicParams.h#L13-L74


---
---


### Debug Terminal output Samples

#### 1. RP2040W_WiFi example on RP2040W

This is the terminal output when running [**RP2040W_WiFi**](examples/RP2040W_WiFi) example on **RP2040W**:

#### 1.1 Open Config Portal

```
Start RP2040W_WiFi on RASPBERRY_PI_PICO_W with RP2040W WiFi
WiFiMulti_Generic v1.2.2
WiFiManager_RP2040W_Lite v1.6.0
[WG] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[WG] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[WG] Set CORS Header to : Your Access-Control-Allow-Origin
[WG] Hostname=RP2040W-WiFi
LittleFS Flag read = 0xd0d01234
Flag read = 0xd0d01234
doubleResetDetected
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
[WG] Double Reset Detected
[WG] config.dat loading
[WG] LoadCfgFile 
[WG] OK
[WG] ======= Start Stored Config Data =======
[WG] Hdr=RP2040W-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=RP2040W
[WG] i=0,id=sv1,data=account.duckdns.org
[WG] i=1,id=tk1,data=token1
[WG] i=2,id=sv2,data=account.ddns.net
[WG] i=3,id=tk2,data=token2
[WG] i=4,id=prt,data=8080
[WG] i=5,id=mqt,data=mqtt.duckdns.org
[WG] CCSum=0x10a1,RCSum=0x10a1
[WG] LoadCredFile 
[WG] CrR:pdata=new_blynk.duckdns.org,len=34
[WG] CrR:pdata=new_token1,len=34
[WG] CrR:pdata=new_blynk.ddns.net,len=34
[WG] CrR:pdata=new_token2,len=34
[WG] CrR:pdata=8080,len=6
[WG] CrR:pdata=new_mqtt.duckdns.org,len=34
[WG] OK
[WG] CrCCsum=0x2034,CrRCsum=0x2034
[WG] Valid Stored Dynamic Data
[WG] Hdr=RP2040W-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=RP2040W
[WG] i=0,id=sv1,data=new_blynk.duckdns.org
[WG] i=1,id=tk1,data=new_token1
[WG] i=2,id=sv2,data=new_blynk.ddns.net
[WG] i=3,id=tk2,data=new_token2
[WG] i=4,id=prt,data=8080
[WG] i=5,id=mqt,data=new_mqtt.duckdns.org
[WG] Check if isForcedCP
[WG] LoadCPFile 
[WG] OK
[WG] bg: isForcedConfigPortal = false
[WG] bg:Stay forever in CP:DRD/MRD
[WG] clearForcedCP
[WG] SaveCPFile 
[WG] OK
[WG] SaveBkUpCPFile 
[WG] OK
[WG] Scanning Network
[WG] scanWifiNetworks: Done, Scanned Networks n = 10
[WG] Sorting
[WG] Removing Dup
[WG] WiFi networks found:
[WG] 1: HueNet, -51dB
[WG] 2: HueNet1, -24dB
[WG] 3: HueNet2, -51dB
[WG] 4: HueNetTek, -39dB
[WG] 5: SmartRG-02a2, -88dB
[WG] 6: ESP151CD5, -86dB
[WG] 7: Guest5655, -75dB
[WG] 8: DECO-5655, -85dB
[WG] 9: , -82dB
[WG] 10: FishTank, -90dB
[WG] SSID=RP2040W_51F485,PW=MyRP2040W_51F485
[WG] IP=192.168.42.1
[WG] s:millis() = 6153, configTimeout = 126153
F
Your stored Credentials :
Blynk Server1 = new_blynk.duckdns.org
Token1 = new_token1
Blynk Server2 = new_blynk.ddns.net
Token2 = new_token2
Port = 8080
MQTT Server = new_mqtt.duckdns.org
F
FFFFF[WG] 
h:UpdLittleFS
[WG] h:Rst
```


#### 1.2 Got valid Credential from Config Portal, then connected to WiFi

```
Start RP2040W_WiFi on RASPBERRY_PI_PICO_W with RP2040W WiFi
WiFiMulti_Generic v1.2.2
WiFiManager_RP2040W_Lite v1.6.0
[WG] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[WG] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[WG] Set CORS Header to : Your Access-Control-Allow-Origin
[WG] Hostname=RP2040W-WiFi
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] LoadCfgFile 
[WG] OK
[WG] ======= Start Stored Config Data =======
[WG] Hdr=RP2040W-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=RP2040W
[WG] i=0,id=sv1,data=account.duckdns.org
[WG] i=1,id=tk1,data=token1
[WG] i=2,id=sv2,data=account.ddns.net
[WG] i=3,id=tk2,data=token2
[WG] i=4,id=prt,data=8080
[WG] i=5,id=mqt,data=mqtt.duckdns.org
[WG] CCSum=0x10a1,RCSum=0x10a1
[WG] LoadCredFile 
[WG] CrR:pdata=new_blynk.duckdns.org,len=34
[WG] CrR:pdata=new_token1,len=34
[WG] CrR:pdata=new_blynk.ddns.net,len=34
[WG] CrR:pdata=new_token2,len=34
[WG] CrR:pdata=8080,len=6
[WG] CrR:pdata=new_mqtt.duckdns.org,len=34
[WG] OK
[WG] CrCCsum=0x2034,CrRCsum=0x2034
[WG] Valid Stored Dynamic Data
[WG] Hdr=RP2040W-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=RP2040W
[WG] i=0,id=sv1,data=new_blynk.duckdns.org
[WG] i=1,id=tk1,data=new_token1
[WG] i=2,id=sv2,data=new_blynk.ddns.net
[WG] i=3,id=tk2,data=new_token2
[WG] i=4,id=prt,data=8080
[WG] i=5,id=mqt,data=new_mqtt.duckdns.org
[WG] Check if isForcedCP
[WG] LoadCPFile 
[WG] OK
[WG] No WiFi. Trying to scan and reconnect
[WG] WiFi connected after time: 1
[WG] SSID:HueNet1,IP address:192.168.2.180
[WG] b:WOK
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
H
Your stored Credentials :
Blynk Server1 = new_blynk.duckdns.org
Token1 = new_token1
Blynk Server2 = new_blynk.ddns.net
Token2 = new_token2
Port = 8080
MQTT Server = new_mqtt.duckdns.org
H[WG] r:Check&WLost                 <====== WiFi Lost, and auto-reconnected
[WG] r:WLost.ReconW
[WG] WiFi connected after time: 1
[WG] SSID:HueNet2,IP address:192.168.2.180
[WG] r:WOK
H
```


---

#### 2. RP2040W_WiFi_MQTT on RP2040W

This is the terminal output when running [**RP2040W_WiFi_MQTT**](examples/RP2040W_WiFi_MQTT) example on **RP2040W**:

#### 2.1 Open Config Portal

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/MQTT.png">
</p>


```
Start RP2040W_WiFi_MQTT on RASPBERRY_PI_PICO_W with RP2040W WiFi
WiFiMulti_Generic v1.2.2
WiFiManager_RP2040W_Lite v1.6.0
[WG] Hostname=RP2040W-MQTT
LittleFS Flag read = 0xd0d01234
Flag read = 0xd0d01234
doubleResetDetected
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
[WG] Double Reset Detected
[WG] Invalid Stored WiFi Config Data
[WG] bg: isForcedConfigPortal = false
[WG] bg:Stay forever in CP:DRD/MRD
[WG] clearForcedCP
[WG] SaveCPFile 
[WG] SSID=RP2040W_51F485,PW=MyRP2040W_51F485
[WG] IP=192.168.42.1
Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = private, AIO_KEY = private
Creating new MQTT_Pub_Topic,  Temperature = private/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = private/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = private/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = private/feeds/LED_Control
...
```

#### 2.2 Got valid Credential from Config Portal, then connected to WiFi and AIO MQTT

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/raw/main/pics/MQTT_Save.png">
</p>

```
Start RP2040W_WiFi_MQTT on RASPBERRY_PI_PICO_W with RP2040W WiFi
WiFiMulti_Generic v1.2.2
WiFiManager_RP2040W_Lite v1.6.0
[WG] Hostname=RP2040W-MQTT
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WG] CCSum=0x160c,RCSum=0x160c
[WG] CrCCsum=0x2236,CrRCsum=0x2236
[WG] Valid Stored Dynamic Data
[WG] ======= Start Stored Config Data =======
[WG] Hdr=RP2040W-WIFI,SSID=HueNet1,PW=12345678
[WG] SSID1=HueNet2,PW1=12345678
[WG] BName=RP2040W_MQTT
[WG] i=0,id=svr,data=io.adafruit.com
[WG] i=1,id=prt,data=1883
[WG] i=2,id=usr,data=user_name
[WG] i=3,id=key,data=aio_key
[WG] i=4,id=pub,data=/feeds/Temperature
[WG] i=5,id=sub,data=/feeds/LED_Control
[WG] con2WF:SSID=HueNet1,PW=12345678
[WG] con2WF:OK
[WG] IP=192.168.2.180
[WG] SSID=HueNet1,IP=192.168.2.180
[WG] b:WOK
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic,  Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
TWTWTWTW TWTWTW
```
  
---
---

#### Debug

Debug is enabled by default on Serial. To disable, add at the beginning of sketch

```cpp
/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT     Serial
#define WIFI_GENERIC_DEBUG_OUTPUT     Serial

#define _WIFI_GENERIC_LOGLEVEL_       4

#define DRD_GENERIC_DEBUG             true
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, or this library version.

Sometimes, the library will only work if you update the `WiFi module/shield` firmware to the newer or older version because some function compatibility.

---
---


### Issues

Submit issues to: [WiFiManager_RP2040W_Lite issues](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/issues)

---
---

### TO DO

1. Support more boards, shields and libraries
2. Bug Searching and Killing

---

### DONE

 1. Add support to **RP2040W** built-in CYW43439 WiFi using [`arduino-pico core`](https://github.com/earlephilhower/arduino-pico)
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (SSIDs, Passwords, etc.), entering config portal
 5. Add configurable Config Portal IP, SSID and Password
 6. Change Synch XMLHttpRequest to Async
 7. Add configurable Static IP, GW, Subnet Mask and 2 DNS Servers' IP Addresses.
 8. Add checksums
 9. Add MultiWiFi features with auto(re)connect
10. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
11. Permit to input special chars such as **%** and **#** into data fields.
12. Default Credentials and dynamic parameters
13. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
14. Configurable Config Portal Title
15. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dyamic Params quickly for each device.
16. Add Table of Contents and Version String
17. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
18. Add functions to control Config Portal from software or Virtual Switches.
19. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
20. Enforce WiFi Password minimum length of 8 chars
21. Enable **scan of WiFi networks** for selection in Configuration Portal
22. Add `LibraryPatches` for [**Adafruit_MQTT_Library**](https://github.com/adafruit/Adafruit_MQTT_Library) to fix compiler error for RP2040W, RP2040-based and many other boards.
23. Fix the blocking issue in loop() with configurable `WIFI_RECON_INTERVAL`
24. Workaround for core WiFi.status() bug, which does not detect WiFi lost.
25. Use [WiFiMulti_Generic](https://github.com/khoih-prog/WiFiMulti_Generic) library to connect to the best of **multi-WiFi APs**, with **auto-checking / auto-reconnecting** features when WiFi connection is lost
26. Add `lib_ldf_mode = chain+` in `platformio.ini`

---
---
 
### Contributions and Thanks

Please help contribute to this project and add your name here.

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/WiFiManager_RP2040W_Lite/blob/main/LICENSE)

---

### Copyright

Copyright 2022- Khoi Hoang


