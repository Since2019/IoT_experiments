/**
 * ESP8266 18650 Shield Version :
 * 
 * connect VCC to the 3.3V output
   Signal: D2
*/

#include "DHT.h" // Adafruit DHT library

#ifndef _ARDUINOJSON_H_
#define _ARDUINOJSON_H_
#include <ArduinoJson.h>
#endif

// Uncomment one of the lines below for whatever DHT sensor type you're using!
// #define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321

// #ifndef DHT_DATA_PIN
// #define DHT_DATA_PIN A0
// #endif

// #define DHT_DATA_PIN D3

uint8_t DHTPin = 0; //D3 = GPIO 0
// Initialize DHT sensor.

String DHT_read()
{

  float Temperature;
  float Humidity;

  DHT dht(DHTPin, DHTTYPE);
  dht.begin();

  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity();       // Gets the values of the humidity

  // Posting JSON to the edge device
  DynamicJsonDocument doc(128);

  doc["sensor_model"] = "DHT22";                             // MQTT {sensor_model : String, ...}
  doc["sensor_data"]["temperature"] = dht.readTemperature(); // {}
  doc["sensor_data"]["humidity"] = dht.readHumidity();

  String json;
  serializeJson(doc, json);
  Serial.println(json);
  return json;
}