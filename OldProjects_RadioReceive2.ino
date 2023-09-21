#include <Wire.h>

byte msg[32];
byte mems[12];
char ENDCHAR = "\n";


void setup() 
{
  Wire.begin(0xF2); //A 0xF2 kell, hogy SLAVE-ként viselkedjen az adatok továbbításához
  Wire.onRequest(requestEvent); // data request to slave
  Wire.onReceive(receiveEvent); // data slave recieved
  Serial.begin(9600);
  Serial.println("Ready.");

}

void loop() 
{
  //Serial.println("");

}

void receiveEvent(int howMany) 
{
  //Serial.println(howMany);
    for(byte i = 0; i< howMany; i++)
    {
      msg[i] = Wire.read();

      if(i==0)
      {
        switch (msg[0])
        {
          case 0:
            Serial.print("BRK?:\t");
            break;
          case 128:
            Serial.print("RDIO:\t");
            break;
          case 255:
            Serial.print("MEMS:\t");
            break;
          default:
            Serial.print("UKNWN\t");
            break;
        }
      }
      else
      {
      Serial.print(msg[i], DEC);
      Serial.print("\t");
      }
    }
    Serial.print("\r\n");

}
  
void requestEvent() 
{
  Serial.println("Incoming request");
    // respond to the question
   
}