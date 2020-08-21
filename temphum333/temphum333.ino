#include <DHT.h>

//#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
#define fan 4

int maxHum = 30;
//int maxTemp = 20;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(fan, OUTPUT);
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  //float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  if(h > maxHum ) {
      digitalWrite(fan, HIGH);
  } else {
     digitalWrite(fan, LOW); 
  }
  
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\n");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");

}
