#include<Servo.h>//header file for servo
#include <LiquidCrystal.h>//header file for LCD


//first of all we will use the  TMP36 which is a temperature sensor that outputs
//a voltage that's proportional to the ambient temperature.

// We'll use analog input 0 to measure the temperature sensor's signal pin.
//Temparature Sensor
const int temperaturePin = 0; //The output of tmp36 is connected to A0 of arduino

//buzzer
const int buzzer = 12; //buzzer is connected to D12 on the arduino

//Gas Sensor
int gasSensorPin=A1;//Gas sensor output is connected to A1 of Arduino
int sensorval;//For storing the value sensed by gas sensor

//Doors
Servo servo1,servo2;
int servo1Pin=11;
int servo2Pin=10;

//RGB LED
int red_led=9;//Red terminal of RGB LED is connected to D9 of Arduino
int green_led=8;//Green terminal of RGB LED is connected to D8 of Arduino

//LCD
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);//Sets the interfacing pins on Arduino that are connected to LCD
//(rs, enable, d4, d5, d6, d7)
//7-Rs,6-E(Enable), 5,4,3,2 are the inputs->4 bit mode

//reset button
int buttonstate = 0;
const int resetbtn = 13;
int repeat = 0;

void setup()
{
  pinMode(buzzer, OUTPUT);//set the pin connected to the buzzer as an output
  
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo1.write(90);//Intially both doors are closed(i.e, 90 degrees)
  servo2.write(90);
  delay(2000);
  
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(resetbtn,INPUT);
  //Serial.begin(9600);
  
  lcd.begin(16,2);//initialisation of 16*2 LCD
}

void loop()
{
  	//for buzzer and tmp36 temp sensor
 	float voltage, degreesC;
  	voltage = getVoltage(temperaturePin);
	degreesC = (voltage - 0.5) * 100.0;
	
  	sensorval=analogRead(gasSensorPin);
  	//Serial.print(sensorval);
 	buttonstate = digitalRead(resetbtn);
  
  if(buttonstate == HIGH) {
  	repeat = 0;
  }  
  
  	
  	if(degreesC>37 || sensorval>700 || repeat == 1)
  	{
      repeat = 1;
      
      //digitalWrite(buzzer, LOW);
      tone(buzzer, 800, 800);
      delay(200);  //delay 
      tone(buzzer,600,800);
    
      servo1.write(0);
      servo2.write(0);
      delay(1000);
      
      
      digitalWrite(red_led,HIGH);
      digitalWrite(green_led,LOW);
      delay(1000);
      digitalWrite(red_led,LOW);
      
      lcd.clear();
      lcd.setCursor(0,0);//row 0 column 0
  	  lcd.print("DANGER!!");
      lcd.setCursor(0,1);//row 1 column 0
      lcd.print("VACATE Building!");
  	}
  	else{
      servo1.write(90);
      servo2.write(90);
      delay(1000);
      
      digitalWrite(green_led,HIGH);
      digitalWrite(red_led,LOW);
      
      lcd.clear();
  	  lcd.setCursor(0,0);//column 0 row 0
  	  lcd.print("SAFE");
      lcd.setCursor(6,0);//column 6 row 0
      lcd.print(degreesC);
      lcd.print("C");
      lcd.setCursor(0,1);
      lcd.print("Gas Conc.:");
      lcd.print(sensorval);
  }
  
}
float getVoltage(int pin)
{
  
  return (analogRead(pin) * 0.004882814);
}