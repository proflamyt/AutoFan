#include "DHT.h"
#include <AFMotor.h>
#define DHTPIN A0   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

AF_DCMotor motor(3);


// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
    //Set initial speed of the motor & stop
  motor.setSpeed(200);
  motor.run(RELEASE);
  //motor.run(FORWARD);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float t = dht.readTemperature();
  
  //motor.setSpeed(250); 


  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(t);
  Serial.print(F("C "));

  
  
}
