#include <Wire.h>
// #include <Math.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>
#include "DetectColor.h"
#include "DetectDistance.h"
#include "Sound.h"
#include "Movement.h"


extern uint16_t clear, red, green, blue, colorTemp, lux; // raw data
extern uint8_t range, status;
extern String colorStr;


void setup() {
    analogReference(INTERNAL);
    // analogReference(EXTERNAL);
    // Serial.begin(9600);
    // Serial.begin(19200);
    Serial.begin(115200);
    while (!Serial) {
        // wait for serial
    };

    Movement_setup();
    Sound_setup();
    DetectDistance_setup();
    DetectColor_setup();
    delay(1000);
} 



// time guard stuff
unsigned long previousTimeGuard = 0;
const long timeGuardInterval = 50;
unsigned long previousTimeGuard2 = 0;
long timeGuardInterval2 = 100;





void loop() {
    //second init / setup style
    
    // quick scope begin
    while(1) {
        unsigned long timeElapsed = millis();
        
        DetectColor_human();
        DetectDistance_run();
        
        
         if (timeElapsed - previousTimeGuard >= timeGuardInterval) {
            
            // Serial.print("\n\n");
            // Serial.println(colorStr);
            // DetectColor_print();

            Movement_run();
            
            // Vl distance baby
            // Serial.print("\nRange: "); Serial.println(range);

            previousTimeGuard = timeElapsed; 
        }
        
        if (timeElapsed - previousTimeGuard2 >= timeGuardInterval2) {
            synthState();

            previousTimeGuard2 = timeElapsed;
        }
    }
    // quick scope end
    
}









