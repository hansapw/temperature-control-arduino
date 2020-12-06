// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

#define fan D1
#define sensords D5
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS sensords

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(115200);
  Serial.println("Wemos + DS18b20 + fan");
  pinMode (fan, OUTPUT);
  digitalWrite (fan, HIGH);
  delay (2000);
  digitalWrite (fan, LOW);
  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
    ceksuhu();
}

void ceksuhu(){
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  float suhu=sensors.getTempCByIndex(0);
  Serial.print("Suhu: ");
  Serial.println(suhu);
  if (suhu>32) digitalWrite (fan,HIGH);
  if (suhu<29) digitalWrite (fan,LOW);
}
