/*********************************************************************************************************
  WebSocketsDebug_Generic.h - WebSockets Library for boards

  Based on and modified from WebSockets libarary https://github.com/Links2004/arduinoWebSockets
  to support other boards such as  SAMD21, SAMD51, Adafruit's nRF52, Teensy, STM32F, SAM DUE boards, etc.

  Built by Khoi Hoang https://github.com/khoih-prog/WS_Generic
  Licensed under MIT license

  Copyright (c) 2015 Markus Sattler. All rights reserved.
  This file is part of the WS for Arduino.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Version: 2.16.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  2.1.3   K Hoang      15/05/2020 Initial porting to support SAMD21, SAMD51, nRF52 boards, such as
                                  AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense,
                                  Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, etc.
  ...
  2.11.0  K Hoang      30/11/2021 Auto detect ESP32 core version. Fix bug in examples
  2.11.1  K Hoang      12/12/2021 Add option to use transport=websocket with sticky-session SIO server
  2.12.0  K Hoang      28/01/2022 Supporting SSL for ESP32-based WT32_ETH01 boards
  2.13.0  K Hoang      14/02/2022 Add support to ESP32_S3. Add PING and PONG SocketIO events
  2.14.0  K Hoang      17/02/2022 Suppress unnecessary warnings. Optimize code by passing references instead of value
  2.14.1  K Hoang      18/02/2022 Fix setInsecure() bug for WIO_Terminal. Update Packages_Patches for Seeeduino
  2.14.2  K Hoang      27/03/2022 Fix Async bug for ESP8266 when using NETWORK_ESP8266_ASYNC
  2.15.0  K Hoang      06/04/2022 Use Ethernet_Generic library as default. Sync with arduinoWebSockets v2.3.6
  2.16.0  K Hoang      13/10/2022 Add WS and WSS support to RP2040W using CYW43439 WiFi
  2.16.1  K Hoang      24/11/2022 Using new WiFi101_Generic library

**********************************************************************************************************/

#pragma once

#ifndef WEBSOCKETS_DEBUG_GENERIC_H_
#define WEBSOCKETS_DEBUG_GENERIC_H_

#include <stdio.h>

#ifdef WS_DEBUG_WEBSOCKETS_PORT
  #define WS_DEBUG_PORT      WS_DEBUG_WEBSOCKETS_PORT
#else
  #define WS_DEBUG_PORT      Serial
#endif

// Change WS_LOG_LEVEL to set tracing and logging verbosity
// 0: DISABLED: no logging (Default)
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational
// 4: DEBUG: errors, warnings, informational and debug

#ifndef WS_LOG_LEVEL
  #define WS_LOG_LEVEL       0
#endif

const char WS_MARK[] = "[WS] ";
#define WS_PRINT_MARK   WS_PRINT(WS_MARK)

#define WS_PRINT        WS_DEBUG_PORT.print
#define WS_PRINTLN      WS_DEBUG_PORT.println

#define WS_LOGERROR(x)         if(WS_LOG_LEVEL>0) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define WS_LOGERROR2(x,y)      if(WS_LOG_LEVEL>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINTLN(y); }
#define WS_LOGERROR3(x,y,z)    if(WS_LOG_LEVEL>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINTLN(z); }
#define WS_LOGERROR4(x,y,z,w)  if(WS_LOG_LEVEL>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINT(z); WS_PRINTLN(w); }

#define WS_LOGWARN(x)          if(WS_LOG_LEVEL>1) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define WS_LOGWARN2(x,y)       if(WS_LOG_LEVEL>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINTLN(y); }
#define WS_LOGWARN3(x,y,z)     if(WS_LOG_LEVEL>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINTLN(z); }
#define WS_LOGWARN4(x,y,z,w)   if(WS_LOG_LEVEL>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINT(z);  WS_PRINTLN(w); }

#define WS_LOGINFO(x)          if(WS_LOG_LEVEL>2) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define WS_LOGINFO2(x,y)       if(WS_LOG_LEVEL>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINTLN(y); }
#define WS_LOGINFO3(x,y,z)     if(WS_LOG_LEVEL>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINTLN(z); }
#define WS_LOGINFO4(x,y,z,w)   if(WS_LOG_LEVEL>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINT(z); WS_PRINTLN(w); }

#define WS_LOGDEBUG(x)         if(WS_LOG_LEVEL>3) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define WS_LOGDEBUG2(x,y)      if(WS_LOG_LEVEL>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINTLN(y); }
#define WS_LOGDEBUG3(x,y,z)    if(WS_LOG_LEVEL>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINTLN(z); }
#define WS_LOGDEBUG4(x,y,z,w)  if(WS_LOG_LEVEL>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT(y); WS_PRINT(z); WS_PRINTLN(w); }

#endif    // WEBSOCKETS_DEBUG_GENERIC_H_

