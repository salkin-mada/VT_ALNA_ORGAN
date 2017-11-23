#include <Wire.h>
// #include <Math.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>
#include "DetectColor.h"
#include "DetectDistance.h"
#include "Sound.h"

extern uint16_t clear, red, green, blue, colorTemp, lux; // raw data
extern uint8_t range, status;
extern String colorStr;


void setup() {
    analogReference(EXTERNAL);
    
    // Serial.begin(9600);
    // Serial.begin(19200);
    Serial.begin(115200);
    while (!Serial) {
        // wait for serial
    };

    Sound_setup();
    DetectDistance_setup();
    DetectColor_setup();
    delay(1000);
} 



// time guard stuff
unsigned long previousTimeGuard = 0;
const long timeGuardInterval = 100;
unsigned long previousTimeGuard2 = 0;
long timeGuardInterval2 = 1000;





void loop() {
    //second init / setup style
    
    // quick scope begin
    while(1) {
        unsigned long timeElapsed = millis();
        
        DetectColor_human();
        DetectDistance_run();
        
        if (timeElapsed - previousTimeGuard >= timeGuardInterval) {
            Serial.println(colorStr);
            DetectColor_print();
            // setFilterType(clear);
            
            // Vl distance baby
            Serial.print("\nRange: "); Serial.println(range);

            previousTimeGuard = timeElapsed; 
        }
        
        if (timeElapsed - previousTimeGuard2 >= timeGuardInterval2) {
            
            synthTest();
            
            
            // for plotter
            /* Serial.print(re);
            Serial.print("\t");
            Serial.print(ge);
            Serial.print("\t");
            Serial.print(be);
            Serial.print("\t");
            Serial.print(value.H);
            Serial.print("\t");
            Serial.print(value.S * 255);
            Serial.print("\t");
            Serial.print(value.V * 255);
            Serial.print("\t");
            Serial.println(range); */
            
            timeGuardInterval2 = random(5000, 20000);
            
            previousTimeGuard2 = timeElapsed;
        }
    }
    
}









