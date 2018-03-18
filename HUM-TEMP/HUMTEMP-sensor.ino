#include <Console.h>
#include "DHT.h"

#define DHTPIN 2 // what digital pin we are connected to 
#define DHTTYPE DHT11 // type os sensor we are using
DHT dht(DHTPIN, DHTTYPE);

int Hsensor = A5;

//Beggining of the VOID SETUP
void setup setup()
     {
     Bridge.begin();
     Console.begin();

     while(!Console)
          {; } //wait for console to connect
     Console.println("Consola conectada, comienza el script HUMEDAD y TEMPERATURA");
     }

void loop()
    {
    delay(1800);  // wait a few seconds between measurements.

   float h = dth.readHumidity(); // read Humidity
   float t = dht.readTemperature(); // read temperature ac Celsius (default)
   float f = dht.readTemperature(false); //read temperature as Fahrenheit (isFahrenheit = true)

//Check if any reads failed and exit early (to try again).
   if (isnan(h) || isnan(t))
   {
      Console.println("Failed to read from DHT sensor!!!");
      return;
   }

//Conpute heat index in Fahrenheit (the default)
   float hif = dht.computeHeatIndex(f, h);
//Compute heat index in Celsius (isFahrenheit = false)
   float hic = dht.computeHeatIndex(t, h, false);

  Console.print("Humidity: ");
  Console.print(h);
  Console.print(" %\t");
  Console.print("Temperature: ");
  Console.print(t);
  Console.print(" *C ");
  //Console.print(f);
  //Console.print(" *F\t");
  //Console.print("Heat index: ");
  Console.print(hic);
  Console.print(" *C ");
  //Console.print(hif);
  //Console.println(" *F");


// Beggining of the code for the HUM sensor
  int SensorValue = analogRead(Hsensor); // take a sample
  Console.print(SensorValue); Console.print(" - ");

  if(SensorValue >= 1000) {
               Console.println("Sensor is not in the soil or is Disconnected");
                          }
  if(SensorValue < 1000 && SensorValue >= 600) {
               Console.println("Solid is DRY");
                                               }
  if(SensorValue < 600 && SensorValue >= 370) {
               Console.println("Solid is HUMID");
                                              } 
  if(SensorValue < 370) {
               Console.println("Solid in the WATER");
                        }

  delay(2700); // wait for 45 min

}





