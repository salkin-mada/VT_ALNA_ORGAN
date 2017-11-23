#include "DetectColor.h"
#include <Arduino.h>
#include "Adafruit_TCS34725.h"

// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_16X);
// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_4X);
unsigned int INTEGRATIONTIME_MAXCOUNT = 65535; // aka raw data resolution
/**<  2.4ms - 1 cycle    - Max Count: 1024  */
/**<  24ms  - 10 cycles  - Max Count: 10240 */
/**<  50ms  - 20 cycles  - Max Count: 20480 */
/**<  101ms - 42 cycles  - Max Count: 43008 */
/**<  154ms - 64 cycles  - Max Count: 65535 */
/**<  700ms - 256 cycles - Max Count: 65535 */

// RGB -> eye-recognized gamma color
byte gammatable[256];

uint16_t clear, red, green, blue, colorTemp, lux;
int re,ge,be; // rgb set [0,255]

RGB rgbData = RGB(re,ge,be);
HSV hsv = RGBToHSV(rgbData);

String colorStr;

volatile boolean state = false;
//Interrupt Service Routine
void isr() 
{
    state = true;
}

/* tcs.getRawData() does a delay(Integration_Time) after the sensor readout.
We don't need to wait for the next integration cycle because we receive an interrupt when the integration cycle is complete*/
void getRawData_noDelay(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *clear)
{
    *red = tcs.read16(TCS34725_RDATAL);
    *green = tcs.read16(TCS34725_GDATAL);
    *blue = tcs.read16(TCS34725_BDATAL);
    *clear = tcs.read16(TCS34725_CDATAL);
}


void DetectColor_setup() {
    if (tcs.begin()) {
        Serial.println("Found TCS sensor");
    } else {
        Serial.println("No TCS34725 found ... check ze connections");
        while (1); // halt!
    }
    
    pinMode(interruptPin, INPUT_PULLUP); //TCS interrupt output is Active-LOW and Open-Drain
    attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);
    // Set persistence filter to generate an interrupt for every RGB Cycle, regardless of the integration limits
    tcs.write8(TCS34725_PERS, TCS34725_PERS_NONE); 
    tcs.setInterrupt(true);
    
    Serial.flush(); // flush serial
    
    // its always good to have a gammatable, convert RGB colors for humans
    for (int i=0; i<256; i++) {
        float x = i;
        x /= 255;
        x = pow(x, 2.5);
        x *= 255;
        gammatable[i] = x;
    }
    
}

void DetectColor_human() {
    DetectColor_run(re,ge,be); // returning rgb
    
    // convert rgb to hsv
    rgbData = RGB(re, ge, be);
    hsv = RGBToHSV(rgbData);
    
    if(hsv.S <= 0.25 && hsv.V >= 0.40 && hsv.V <= 0.50) {
        colorStr = "GREY";
    } else if (hsv.S <= 0.25 && hsv.V > 0.50) {
        colorStr = "WHITE";
    } else if (hsv.S <= 0.25  && hsv.V < 0.40) {
        colorStr = "BLACK";
    }
    else
    {
        if( (hsv.H >= 0 && hsv.H <= 20) || (hsv.H >= 330 && hsv.H <= 360) ) 
        {
            colorStr = "RED";
        } 
        else if (hsv.H > 20 && hsv.H <= 40) 
        {
            colorStr = "ORANGE";
        } 
        else if (hsv.H > 40 && hsv.H <= 70) 
        {
            colorStr = "YELLOW";
        } 
        else if (hsv.H > 70 && hsv.H <= 165) 
        {
            colorStr = "GREEN";
        } 
        else if (hsv.H > 165 && hsv.H <= 220) 
        {
            colorStr = "BLUE";
        } 
        else if (hsv.H > 220 && hsv.H <= 300) 
        {
            colorStr = "PURPLE";
        } 
        else if (hsv.H > 300 && hsv.H <= 330) 
        {
            colorStr = "PINK";
        } 
        else 
        {
            // Serial.println("I DONT KNOW THAT COLOR ..."); // if hue is outside 0-360
        }
    }
}

void DetectColor_run(int& rei, int& gei, int& bei) {
    // get raw data with no delay
    if (state) {
        getRawData_noDelay(&red, &green, &blue, &clear);
        tcs.clearInterrupt();
        state = false;
    }
    // get raw data with delay
    /* tcs.setInterrupt(false);      // turn on LED
    tcs.getRawData(&red, &green, &blue, &clear);
    tcs.setInterrupt(true);  // turn off LED */
    
    // basic hex code for visualization (make raw reading into rgb)
    uint32_t sum = clear;
    float r, g, b;
    r = red; r /= sum;
    g = green; g /= sum;
    b = blue; b /= sum;
    r *= 256; g *= 256; b *= 256;
    /* Serial.print("\t");
    Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
    Serial.println(); */
    rei = r; gei = g; bei = b;
    
    colorTemp = tcs.calculateColorTemperature(red, green, blue);
    lux = tcs.calculateLux(red, green, blue);
    
}


void DetectColor_print() {
    
    Serial.print("\n\n\n");
    Serial.print("\t\tH: "); Serial.println(hsv.H);
    Serial.print("\t\tS: "); Serial.println(hsv.S);
    Serial.print("\t\tV: "); Serial.println(hsv.V);
    
    /* Serial.print("\n\nRe256:\t"); Serial.print(re);
    Serial.print("\tGe256:\t"); Serial.print(ge);
    Serial.print("\tBe256:\t"); Serial.print(be);
    Serial.print("\n");
    Serial.println(""); */
    
    Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K ** ");
    Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" ** ");
    Serial.print("R: "); Serial.print(red, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(green, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(blue, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(clear, DEC); Serial.print(" ");
    Serial.println("");
}

