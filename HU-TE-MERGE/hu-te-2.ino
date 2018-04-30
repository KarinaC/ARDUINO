// HUM and TEMP check toghether

//primer bloque para el DTH11
#include <Console.h>  //usado por ambos scripts
#include "DHT.h"


#define DHTPIN 2 // what digital pin we're connected to 
#define DHTTYPE DHT11 //type of sensor, this case dth11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);
//para el HUM
int Hsensor =A5;



//ARRANCO EL VOID

void setup() 
{
  Bridge.begin();
  Console.begin();
  
  while(!Console)
    {
      ; //wait for console port to connect
    }
   Console.println("Consola conectada podemos comenzar");
   Console.println("Starting HU-TE.ino, merge de todo");
   Console.println("DHTxx test!");
   dht.begin();
}

void loop()
{
  int SensorValue = analogRead(Hsensor); //take a sample
  Console.print(SensorValue); Console.print(" - ");

if(SensorValue >= 1000) {
  Console.println("sensor is not in the soil or Disconnected");
}
if(SensorValue < 1000 && SensorValue >= 600) {
  Console.println("Solid is DRY");
   // prueba de correos
   
  Process p;
  p.runShellCommand("echo -e \"Subject: test desde arduino kakakaka\nFROM: karmukis@gmail.com\nSensor seco ó fuera del agua \" | sendmail -v karmukis@gmail.com");
}
if(SensorValue < 600 && SensorValue >= 370) {
  Console.println("Solid is HUMID");
}
if(SensorValue < 370) {
  Console.println("Solid in WATER");
}
delay(2000);  

// #######################################
// Now the script for env. temp. and hum.
// #######################################

 // Wait a few seconds between measurements.
  delay(20000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Console.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Console.print("Humidity: ");
  Console.print(h);
  Console.print(" %\t");
  Console.print("Temperature: ");
  Console.print(t);
  Console.print(" *C ");
  Console.print(f);
  Console.print(" *F\t");
  Console.print("Heat index: ");
  Console.print(hic);
  Console.print(" *C ");
  Console.print(hif);
  Console.println(" *F");

}

