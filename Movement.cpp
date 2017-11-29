#include <Arduino.h>
#include <PWMServo.h>
#include "Movement.h"

PWMServo feedServo;

extern String colorStr;
String lastColorStr_Movement;
extern uint8_t range;
extern unsigned long timeElapsed;

int servoPin = 9;
int poss = 0; // servo position

// dc motor color wheel
int enablePin = 10; // pwm
int in1Pin = 11; //digital
int in2Pin = 12; //digital
int speed = 0;
bool reverse = false;

unsigned long prevGuard = 0;
long guardInterval = 3000;

void Movement_setup() 
{ 
    feedServo.attach(servoPin);
    
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
} 

void Movement_run() {
    
    if (colorStr == "GREY" && colorStr != lastColorStr_Movement) {
        poss = 80;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "WHITE" && colorStr != lastColorStr_Movement) {
        poss = 60;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "BLACK" && colorStr != lastColorStr_Movement) {
        poss = 0;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "RED" && colorStr != lastColorStr_Movement) {
        poss = 125;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "ORANGE" && colorStr != lastColorStr_Movement) {
        poss = 135;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "YELLOW" && colorStr != lastColorStr_Movement) {
        poss = 158;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "GREEN" && colorStr != lastColorStr_Movement) {
        poss = 112;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "BLUE" && colorStr != lastColorStr_Movement) {
        poss = 150;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "PURPLE" && colorStr != lastColorStr_Movement) {
        poss = 115;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "PINK" && colorStr != lastColorStr_Movement) {
        poss = 118;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    }
    
    timeElapsed = millis();
    // colorwheel control testing
    if (timeElapsed - prevGuard >= guardInterval) {
        guardInterval = random(1000, 10000);

        if (reverse) {
            reverse = false;
        } else if (!reverse) {
            reverse = true;
        }

        speed = random(20, 255);
        
        analogWrite(enablePin, speed);
        digitalWrite(in1Pin, ! reverse);
        digitalWrite(in2Pin, reverse);
        
        prevGuard = timeElapsed;
    }
    
}