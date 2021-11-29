#include "DHT.h"

#define dht_1 2
#define DHTTYPE DHT11
DHT dht(dht_1,DHTTYPE);


int redPin=7;
int greenPin=6;
int bluePin=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  float humidity=dht.readHumidity();
  float temp=dht.readTemperature();

  if(temp<=25){
    setColor(0, 0, 255); // Blue Color
    Serial.print("Humidity:");
    Serial.println(humidity);
    Serial.print("Temperature:");
    Serial.println(temp);
    delay(300);
    }
  else if(temp>25 && temp<=50){
    setColor(0, 255, 0); // Green Color
    Serial.print("Humidity:");
    Serial.println(humidity);
    Serial.print("Temperature:");
    Serial.println(temp);
    delay(300);
    }
  else if (temp>50){
   setColor(255, 0, 0); // Red Color
   Serial.print("Humidity:");
   Serial.println(humidity);
   Serial.print("Temperature:");
   Serial.println(temp); 
   delay(1000);
  }
}

void setColor(int redValue,int greenValue,int blueValue){
  analogWrite(redPin,redValue);
  analogWrite(greenPin,greenValue);
  analogWrite(bluePin,blueValue);
  }
