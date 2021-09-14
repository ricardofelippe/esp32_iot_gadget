#include <Arduino.h>
#include "sensor_readings.h"

// Passing the tft object by reference
void refresh_readings(Adafruit_BME280* bme, TFT_eSPI* tft) {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  //digitalWrite(LED_BUILTIN, HIGH); // If you enable this, the TFT will not work!!!

  uint16_t bg = TFT_BLACK;
  uint16_t fg = TFT_WHITE;
  // tft->setTextColor(fg, bg);
  // tft->setRotation(1);

  // tft->fillScreen(bg);

  tft->setCursor(5, 5);
  tft->setTextColor(fg, bg);
  tft->println("Right now...");


  f_temperature = bme->readTemperature();
  f_humidity    = bme->readHumidity();
  f_pressure    = bme->readPressure() / 100.0F;
  f_altitude    = bme->readAltitude(SEALEVELPRESSURE_HPA);

  tft->setTextColor(TFT_YELLOW, bg);
  
  // Temperature
  Serial.print(f_temperature);
  Serial.println(" °C");
  tft->fillRect(5, 50, 140, 30, bg);
  tft->setCursor(5, 50);
  tft->print(f_temperature);
  tft->println(" °C");

  // Humidity
  Serial.print(f_humidity);
  Serial.println(" %");
  tft->fillRect(5, 90, 130, 30, bg);
  tft->setCursor(5, 90);
  tft->print(f_humidity);
  tft->println(" %");

  // Pressure 
  Serial.print(f_pressure);
  Serial.println(" hPa");
  tft->fillRect(5, 130, 200, 30, bg);
  tft->setCursor(5, 130);
  tft->print(f_pressure);
  tft->println(" hPa");

  // Appx altitude
  Serial.print(f_altitude);
  Serial.println(" m");   
  tft->fillRect(5, 170, 200, 30, bg);
  tft->setCursor(5, 170);
  tft->print(f_altitude);
  tft->println(" m");
  
  //digitalWrite(LED_BUILTIN, LOW);
  Serial.println("-----v2----");   
}