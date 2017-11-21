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
int re,ge,be; // rgb set [0,255]

void setup() {
    analogReference(EXTERNAL);
    
    Serial.begin(9600);
    while (!Serial) {
        //muahaha
    };
    
    Sound_setup();
    // DetectColor_setup();
    DetectDistance_setup();
    
} 



// time guard stuff
unsigned long previousTimeGuard = 0;
const long timeGuardInterval = 100;


void loop() {

    DetectColor_run(re,ge,be);
    DetectDistance_run();
    
    setFreq(red);
    setFmFreq(green);
    setFilterType(clear);
    Sound_apply();
    Sound_noteOn();
    
    //Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );
    
    /* analogWrite(redpin, gammatable[(int)r]);
    analogWrite(greenpin, gammatable[(int)g]);
    analogWrite(bluepin, gammatable[(int)b]); */
    
    
    
    unsigned long currentTimeGuard = millis();  
    if (currentTimeGuard - previousTimeGuard >= timeGuardInterval) {
        // Vl distance baby
        Serial.print("Range: "); Serial.println(range);


        /*COLOR de new skool 1987 ish*/
        
        RGB data = RGB(re, ge, be);
        HSV value = RGBToHSV(data);

        Serial.print("\n\n\n");
        Serial.print("\t\tH: "); Serial.println(value.H);
        Serial.print("\t\tS: "); Serial.println(value.S);
        Serial.print("\t\tV: "); Serial.println(value.V);

        Serial.print("\t\t\tB/W"); Serial.println("\tCOLORS");
        
        if(value.S <= 0.25 && value.V >= 0.40 && value.V <= 0.60) {
            Serial.println("\t\t\tGREY");
        } else if (value.S < 0.25 && value.V > 0.60) {
            Serial.println("\t\t\tWHITE");
        } else if (value.S <= 0.25  && value.V <= 0.40) {
            Serial.println("\t\t\tBLACK");
        }
        else
        {
            if( (value.H >= 0 && value.H <= 20) || (value.H >= 330 && value.H <= 360) ) 
            {
                Serial.println("\t\t\t\tRED");
            } 
            else if (value.H > 20 && value.H <= 40) 
            {
                Serial.println("\t\t\t\tORANGE");
            } 
            else if (value.H > 40 && value.H <= 70) 
            {
                Serial.println("\t\t\t\tYELLOW");
            } 
            else if (value.H > 70 && value.H <= 165) 
            {
                Serial.println("\t\t\t\tGREEN");
            } 
            else if (value.H > 165 && value.H <= 270) 
            {
                Serial.println("\t\t\t\tBLUE");
            } 
            else if (value.H > 270 && value.H <= 300) 
            {
                Serial.println("\t\t\t\tPURPLE / MAGENTA");
            } 
            else if (value.H > 300 && value.H <= 330) 
            {
                Serial.println("\t\t\t\tPINK");
            } 
            else 
            {
                Serial.println("I DONT KNOW THAT COLOR ...");
            }
        }
        
        
        
        /*COLOR de old skool 1860-1861 rgb*/
        /* if((re>be) && (re>ge)) {
            Serial.println("\033[4;31mdetecting\033[0m\033[30;41m red \033[0m");
        } else if((ge>be) && (ge>re)) {
            if(be>re) {
                Serial.println("\033[4;33mdetecting\033[0m\033[30;43m yellow \033[0m");
            }
            else if (be<re) {
                Serial.println("\033[4;32mdetecting\033[0m\033[30;42m green \033[0m");
            }
            else {
                Serial.println("color is .....");
            }
            
        }
        else if((be>re) && (be>ge)) {
            Serial.println("\033[4;34mdetecting\033[0m\033[30;44m blue \033[0m");
        }
        else {
            Serial.println("color not detectable");
        }   */
        
        
        Serial.print("\n\nRe256:\t"); Serial.print(re);
        Serial.print("\tGe256:\t"); Serial.print(ge);
        Serial.print("\tBe256:\t"); Serial.print(be);
        // Serial.print("\n");
        Serial.println("");
        
        Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K ** ");
        Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" ** ");
        Serial.print("R: "); Serial.print(red, DEC); Serial.print(" ");
        Serial.print("G: "); Serial.print(green, DEC); Serial.print(" ");
        Serial.print("B: "); Serial.print(blue, DEC); Serial.print(" ");
        Serial.print("C: "); Serial.print(clear, DEC); Serial.print(" ");
        Serial.println("");
        
        // Serial.println("\033[1;32mbold green text\033[0m plain text\n");
        
        
        previousTimeGuard = currentTimeGuard; 
    }
    
}









