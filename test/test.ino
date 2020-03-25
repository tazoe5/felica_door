#define SSID       "aterm-7a70d1-gw"
#define PASSWORD   "6425ad3b8eed0"
#include "uartWIFI.h"
#include <softwareserial.h>
WIFI wifi;
void setup()
{
  wifi.begin();
  bool b = wifi.Initialize(STA, SSID, PASSWORD);
  if(!b)
  {
    DebugSerial.println("Init error");
  }
  DebugSerial.print("Connecting...");
  String wifistring  = wifi.showJAP();
  while(wifistring == "") {
    delay(200);
    wifistring = wifi.showJAP();
  }
  String ipstring = wifi.showIP();
  while(ipstring == "") {
    delay(200);
    ipstring = wifi.showIP();
  }
  DebugSerial.println(wifistring); //show the name of current wifi access port, "AP" label is included here
  DebugSerial.print("IP Address:");
  DebugSerial.println(ipstring); //show the ip address of module
}
void loop()
{
}</softwareserial.h>
