#include <Arduino.h>
#include <PWMServo.h>
#include "Movement.h"

PWMServo feedServo;

extern String colorStr;
String lastColorStr_Movement;

int poss = 0; // servo position

void Movement_setup() 
{ 
    feedServo.attach(9);
} 

void Movement_run() {

    Serial.println(colorStr);

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
        poss = 175;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "ORANGE" && colorStr != lastColorStr_Movement) {
        poss = 145;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "YELLOW" && colorStr != lastColorStr_Movement) {
        poss = 130;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "GREEN" && colorStr != lastColorStr_Movement) {
        poss = 180;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "BLUE" && colorStr != lastColorStr_Movement) {
        poss = 150;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "PURPLE" && colorStr != lastColorStr_Movement) {
        poss = 165;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    } else if (colorStr == "PINK" && colorStr != lastColorStr_Movement) {
        poss = 135;
        feedServo.write(poss);
        lastColorStr_Movement = colorStr;
    }
} 