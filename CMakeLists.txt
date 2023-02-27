cmake_minimum_required(VERSION 3.8)
project(WebSockets_Generic CXX)

# Instead of editing generated BoardOptions.cmake you can set your board like this
#set(ARDUINO_BOARD "ESP32 Dev Module [esp32.esp32]")
#set(ARDUINO_BOARD "NodeMCU 1.0 (ESP-12E Module) [esp8266.nodemcuv2]")

include_directories(src)
include_directories(src/libb64)
include_directories(src/libsha1)

add_library(WebSockets_Generic STATIC
        src/debug_macros.h
        src/SocketIOclient_Generic.h
        src/SocketIOclient_Generic-Impl.h
        src/WebSockets4WebServer_Generic.h
        src/WebSockets_Generic.h
        src/WebSockets_Generic-Impl.h
        src/WebSocketsClient_Generic.h
        src/WebSocketsClient_Generic-Impl.h
        src/WebSocketsServer_Generic.h
        src/WebSocketsServer_Generic-Impl.h)

target_link_arduino_libraries(WebSockets_Generic PRIVATE core)
target_link_arduino_libraries(WebSockets_Generic AUTO_PUBLIC)
