//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define trigPin1 10
#define echoPin1 13
#define trigPin2 9
#define echoPin2 12
float duration1, distance1, duration2, distance2;
void setup()
{
  int sensorPin = A0; // select the input pin for LDR
  int sensorValue = 0;
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
 
  lcd.print("BioBot Booting");
  lcd.setCursor(0, 1);
  lcd.print(" Please Wait... ");
  delay(5000);

  
}

void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Measure the response from the HC-SR04 Echo Pin
 
  duration1 = pulseIn(echoPin1, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance1 = (duration1 / 2) * 0.0343;
  distance2 = (duration2 / 2) * 0.0343;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance 1:");
    lcd.print(distance1);
    lcd.setCursor(0, 1);
    lcd.print("Distance 2:");
    lcd.print(distance2);
    delay(1000);
    
 
  
  }

 
