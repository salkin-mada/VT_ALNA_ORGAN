#include <Audio.h>
#include "Sound.h"
#include <Arduino.h>

AudioSynthWaveform       waveform1;      //xy=124,482
AudioSynthWaveformSineModulated sine_fm1;       //xy=230,411
AudioEffectEnvelope      envelope1;      //xy=366,349
AudioFilterStateVariable filter1;        //xy=396,494
AudioEffectFade          fade1;          //xy=562,436
AudioEffectFade          fade2;          //xy=563,470
AudioEffectFade          fade3;          //xy=563,504
AudioMixer4              mixer1;         //xy=719,469
AudioOutputAnalog        dac1;           //xy=867,469
AudioConnection          patchCord1(waveform1, sine_fm1);
AudioConnection          patchCord2(sine_fm1, envelope1);
AudioConnection          patchCord3(envelope1, 0, filter1, 0);
AudioConnection          patchCord4(filter1, 0, fade1, 0);
AudioConnection          patchCord5(filter1, 1, fade2, 0);
AudioConnection          patchCord6(filter1, 2, fade3, 0);
AudioConnection          patchCord7(fade1, 0, mixer1, 0);
AudioConnection          patchCord8(fade2, 0, mixer1, 1);
AudioConnection          patchCord9(fade3, 0, mixer1, 2);
AudioConnection          patchCord10(mixer1, dac1);


// synth
float freq = 2000.0;
float lastFreq = 2000.0;
float fmFreq = 20;
float lastFmFreq = 20;
const float fmSineAmp = 1.0;
unsigned int cutOff = 4000;
int ftype = 0;
int filterFadeTime = 200;

extern uint16_t clear, red, green, blue;
extern unsigned int INTEGRATIONTIME_MAXCOUNT;


void Sound_setup() {
    AudioMemory(20);
    waveform1.begin(1.0, 2, WAVEFORM_TRIANGLE);
    mixer1.gain(0, 0.6); // lopass
    mixer1.gain(1, 0.8); // bpass
    mixer1.gain(2, 2.0); // hpass
}

void setFilterType(unsigned int ftype) { 
    if (ftype > 0 && ftype < INTEGRATIONTIME_MAXCOUNT / 3) {
        fade1.fadeIn(filterFadeTime);
        fade2.fadeOut(filterFadeTime);
        fade3.fadeOut(filterFadeTime);
        // Serial.println("lowpass");
    }
    if (ftype >= INTEGRATIONTIME_MAXCOUNT / 3 && ftype < INTEGRATIONTIME_MAXCOUNT / 3 * 2) {
        fade1.fadeOut(filterFadeTime*10);
        fade2.fadeIn(filterFadeTime);
        fade3.fadeOut(filterFadeTime);
        // Serial.println("bandpass");    
    }
    if (ftype >= INTEGRATIONTIME_MAXCOUNT / 3 * 2 && ftype <= INTEGRATIONTIME_MAXCOUNT) {
        fade1.fadeOut(filterFadeTime*10);
        fade2.fadeOut(filterFadeTime);
        fade3.fadeIn(filterFadeTime);
        // Serial.println("highpass");
    }
}

void Sound_noteOn() {
    if (freq != lastFreq) {
        envelope1.noteOn();
        envelope1.noteOff();
        lastFreq = freq;
    }
    if (fmFreq != lastFmFreq) {
        envelope1.noteOn();
        envelope1.noteOff();
        lastFmFreq = fmFreq;
    }    
}
void Sound_apply() {
    waveform1.frequency(fmFreq);
    sine_fm1.frequency(freq);
    sine_fm1.amplitude(fmSineAmp);
    filter1.frequency(blue / 1.2);
    filter1.resonance(0.5);
}



void setFreq(unsigned int setter) {
    if (setter > 0 && setter < INTEGRATIONTIME_MAXCOUNT / 12) {
        freq = 220.000;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 && setter < INTEGRATIONTIME_MAXCOUNT / 12 * 2) {
        freq = 233.082;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 2 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 3) {
        freq = 246.942;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 3 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 4) {
        freq = 261.626;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 4 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 5) {
        freq = 277.183;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 5 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 6) {
        freq = 293.665;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 6 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 7) {
        freq = 311.127;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 7 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 8) {
        freq = 329.628;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 8 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 9) {
        freq = 349.228;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 9 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 10) {
        freq = 369.994;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 10 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 11) {
        freq = 391.995;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 11 && setter <= INTEGRATIONTIME_MAXCOUNT) {
        freq = 415.305;
    }
}

void setFmFreq(unsigned int setter) {
    if (setter > 0 && setter < INTEGRATIONTIME_MAXCOUNT / 12) {
        fmFreq = freq * 0.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 && setter < INTEGRATIONTIME_MAXCOUNT / 12 * 2) {
        fmFreq = freq * 1.0;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 2 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 3) {
        fmFreq = freq * 1.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 3 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 4) {
        fmFreq = freq * 2.0;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 4 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 5) {
        fmFreq = freq * 2.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 5 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 6) {
        fmFreq = freq * 3.0;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 6 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 7) {
        fmFreq = freq * 3.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 7 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 8) {
        fmFreq = freq * 4.0;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 8 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 9) {
        fmFreq = freq * 4.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 9 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 10) {
        fmFreq = freq * 5.0;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 10 && setter <= INTEGRATIONTIME_MAXCOUNT / 12 * 11) {
        fmFreq = freq * 5.5;
    }
    if (setter >= INTEGRATIONTIME_MAXCOUNT / 12 * 11 && setter <= INTEGRATIONTIME_MAXCOUNT) {
        fmFreq = freq * 6.0;
    }
}