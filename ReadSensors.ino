
#include "dht.h" //include your libraries
dht DHT;

/******** Choose your pin numbers *********/
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;


/***** Prototype sensor reading functions**/
int readCO2(int pin);
int readDHT_t (int pin);
int readDHT_h (int pin);

void setup() {
   Serial.begin(9600);
}
 
void loop() 
{
  Serial.println("********************");
   int brightness = analogRead(sensor3);
   Serial.println(brightness); //lux
   delay(100);
   int CO2 = readCO2(sensor1); //air quality
   Serial.println(CO2);
   delay(100);
   int temperature = readDHT_t (sensor2); //temperature
   Serial.println(temperature);
   delay(100);
   int humidity = readDHT_h (sensor2); //humidity
   Serial.println(humidity);
   delay(100);
   
   dealy(1000);
    }
}

/********* Write your functions *********/

int readCO2(int pin) {
  //MQ-135  Benzene, alcohol, smoke, air quality
  int mq135_adc = analogRead(pin);
  return mq135_adc;
}

int readDHT_t (int pin) {
  //DHT11 Temperatura and Humidity
    DHT.read11(pin);
    return DHT.temperature;
}

int readDHT_h (int pin) {
  //DHT11 Temperatura and Humidity
    DHT.read11(pin);
    return DHT.humidity;
}
