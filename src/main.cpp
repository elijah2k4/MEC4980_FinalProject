#include <Arduino.h>
#include <HCSR04.h>
#include <ESP32Servo.h>


UltraSonicDistanceSensor distanceSensor(6, 4);  
Servo servoOut;  
Servo servo1;  
Servo servo2;  
Servo servo3;  


int servoPinOut = 17;

int servoPin1 = 12; 
int servoPin2 = 11; 
int servoPin3 = 10; 


const int button1Pin = 16;   // Top Button
const int button2Pin = 13;   // Middle Button
const int button3Pin = 9;  // Bottom Button

int button1State = HIGH;  
int button2State = HIGH;  
int button3State = HIGH;  

void setup() {
  delay(1000);
  Serial.begin(115200);
  delay(1000);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);

    // All servos run at 50Hz
    servo1.setPeriodHertz(50);
    servo2.setPeriodHertz(50);
    servo3.setPeriodHertz(50);
    servoOut.setPeriodHertz(50);

    // Attach each servo to a different pin
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
    servo3.attach(servoPin3);
    servoOut.attach(servoPinOut, 1000, 2000);

    servo1.write(90);
    servo2.write(90);
    servo3.write(90);

}

void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  int CheckHand = distanceSensor.measureDistanceCm();

  if (button1State == LOW) {
    Serial.println("Button 1 pressed!");
    servo1.write(130); 
    delay(250);
    servo1.write(90);
  }

  if (button2State == LOW) {
    Serial.println("Button 2 pressed!");
    servo1.write(40); 
    delay(250);
    servo1.write(90);
  }

  if (button3State == LOW) {
    Serial.println("Button 3 pressed!");
    delay(1000);
    servoOut.write(0);   
    delay(3000);
    servoOut.write(55);    
    delay(1000);

  }/*
  if (CheckHand < 4){
      delay(1000);
      servoOut.write(0);   
      delay(3000);
      servoOut.write(55);    
      delay(1000);
      Serial.println("Candy Dispensed!");
    }*/
  delay(200);
}
