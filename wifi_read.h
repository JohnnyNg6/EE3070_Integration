#ifndef WIFI_READ_H
#define WIFI_READ_H

#include <Arduino.h>

#include "WiFiEsp.h"
#include "ThingSpeak.h"


// Weather station channel details
extern unsigned long weatherStationChannelNumber;
extern unsigned int temperatureFieldNumber;

// Counting channel details
extern unsigned long counterChannelNumber;
extern const char * myCounterReadAPIKey;
extern unsigned int counterFieldNumber; 

extern char ssid[];
extern char pass[];


void WiFi_Read();

void setEspBaudRate(unsigned long baudrate);

#endif
