/*
 * ESP8266 ArduinoからSPIでBME280にアクセスする
 */
#include <ESP8266WiFi.h>
#include <SPI.h>
#include "BME280_SPI.h"

extern "C" {
#include "user_interface.h"
}

#define _DEBUG 1
#if _DEBUG
#define DBG(...) { Serial.print(__VA_ARGS__); }
#define DBGLED(...) { digitalWrite(__VA_ARGS__); }
#else
#define DBG(...)
#define DBGLED(...)
#endif /* _DBG */

#define BME_CS 15

BME280 bme280;

void setup()
{
#ifdef _DEBUG
    Serial.begin(115200);
    delay(10);
#endif
    DBG("\r\nStart\r\n");

    bme280.begin(BME_CS);
}


void loop()
{
    double temp, humid, pressure;

    temp = bme280.readTemperature();
    humid = bme280.readHumidity();
    pressure = bme280.readPressure();

    DBG("temp: "); DBG(temp);
    DBG(" DegC,  humid: "); DBG(humid);
    DBG(" %, pressure: "); DBG(pressure);
    DBG(" hPa\r\n");

    delay(5000);
}

