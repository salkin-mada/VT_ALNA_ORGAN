#include <Wire.h>
// #include "Adafruit_VL6180X.h" // bad library, cant set i2c address
#include "VL6180X.h"
#include <Arduino.h>
#include "DetectDistance.h"



// Adafruit_VL6180X vl = Adafruit_VL6180X();
VL6180X vl;
// VL6180X vl = VL6180X();

uint8_t range, status;


void DetectDistance_setup() {
    
    Wire.begin();
    
    vl.setAddress(0x40);
    
    vl.init();
    vl.configureDefault();
    
    // Reduce range max convergence time and ALS integration
    // time to 30 ms and 50 ms, respectively, to allow 10 Hz
    // operation (as suggested by Table 6 ("Interleaved mode
    // limits (10 Hz operation)") in the datasheet).
    vl.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
    vl.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
    
    vl.setTimeout(500);
    
    // stop continuous mode if already active
    vl.stopContinuous();
    // in case stopContinuous() triggered a single-shot
    // measurement, wait for it to complete
    delay(300);
    // start interleaved continuous mode with period of 100 ms
    vl.startInterleavedContinuous(100);
    
}

/* void DetectDistance_setup() {
    Serial.println("Adafruit VL6180x test!");
    if (! vl.begin()) {
        Serial.println("Failed to find sensor");
        while (1); // halt!
    }
    Serial.println("VL Sensor found!");
    
} */

void DetectDistance_run() {

    range = vl.readRangeContinuousMillimeters();
    // rawAmbientLight = vl.readAmbientContinuous();

    if (vl.timeoutOccurred()) {
        Serial.print(" TIMEOUT"); Serial.println(); 
    }
}

/* void DetectDistance_run() {
    // VL also has LUX sensor, but may not be needed. hence TCS has lux calculations
    // float lux = vl.readLux(VL6180X_ALS_GAIN_5);
    //   Serial.print("Lux: "); Serial.println(lux);
    
    range = vl.readRange();
    status = vl.readRangeStatus();
    
    //  if (status == VL6180X_ERROR_NONE) {
        // Serial.print("Range is good, no errors");
        // Serial.print("Range: "); Serial.println(range);
        // } 
        
        // Some error occurred, print it out!
        
        if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
            Serial.println("System error");
        }
        else if (status == VL6180X_ERROR_ECEFAIL) {
            Serial.println("ECE failure");
        }
        else if (status == VL6180X_ERROR_NOCONVERGE) {
            Serial.println("No convergence");
        }
        else if (status == VL6180X_ERROR_RANGEIGNORE) {
            Serial.println("Ignoring range");
        }
        else if (status == VL6180X_ERROR_SNR) {
            Serial.println("Signal/Noise error");
        }
        else if (status == VL6180X_ERROR_RAWUFLOW) {
            Serial.println("Raw reading underflow");
        }
        else if (status == VL6180X_ERROR_RAWOFLOW) {
            Serial.println("Raw reading overflow");
        }
        else if (status == VL6180X_ERROR_RANGEUFLOW) {
            Serial.println("Range reading underflow");
        }
        else if (status == VL6180X_ERROR_RANGEOFLOW) {
            Serial.println("Range reading overflow");
        }
        // delay(50);
    } */
    
    