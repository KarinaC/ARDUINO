#include <Console.h>

int Hsensor = A5;
void setup()
{
  Bridge.begin();
  Console.begin();

  while(!Console)
    {
      ; // wait for console port to connect
    }
  Console.println("Consola conectada, comenzamos el test");
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
}
if(SensorValue < 600 && SensorValue >= 370) {
  Console.println("Solid is HUMID");
}
if(SensorValue < 370) {
  Console.println("Solid in WATER");
}
delay(100);  
}
