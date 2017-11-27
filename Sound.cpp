#include <Audio.h>
#include "Sound.h"
#include <Arduino.h>

AudioSynthWaveform       waveform2;      //xy=134.047607421875,203.6350555419922
AudioSynthWaveform       waveform5;      //xy=139.325439453125,619.0240020751953
AudioSynthWaveform       waveform1;      //xy=142.04763793945312,107.96832275390625
AudioSynthWaveform       waveform3;      //xy=141.35317993164062,341.2739715576172
AudioSynthWaveform       waveform4;      //xy=146.797607421875,480.69065856933593
AudioSynthWaveform       waveform6;      //xy=150.16683959960937,757.3890686035156
AudioSynthWaveform       waveform7;      //xy=150.57952880859375,893.3096923828125
AudioSynthWaveform       waveform8;      //xy=157.8336181640625,1023.8333740234375
AudioFilterStateVariable filter5;        //xy=289.547607421875,620.1350860595703
AudioFilterStateVariable filter2;        //xy=292.0475769042969,204.41285705566406
AudioFilterStateVariable filter6;        //xy=292.6112365722656,757.83349609375
AudioFilterStateVariable filter1;        //xy=295.7142333984375,104.07942199707031
AudioFilterStateVariable filter3;        //xy=295.24188232421875,345.05174255371093
AudioFilterStateVariable filter4;        //xy=296.46417236328125,480.0240020751953
AudioFilterStateVariable filter7;        //xy=297.24609375,892.4208068847656
AudioFilterStateVariable filter8;        //xy=305.6113586425781,1023.0556030273437
AudioEffectFade          filter2LP;          //xy=435.2697448730469,188.1905517578125
AudioEffectFade          filter2BP;          //xy=436.3809509277344,221.5238800048828
AudioEffectFade          filter2HP;          //xy=436.3809509277344,256.1905059814453
AudioEffectFade          filter3LP;          //xy=436.51995849609375,322.6905059814453
AudioEffectFade          filter3BP;          //xy=436.51983642578125,354.4405059814453
AudioEffectFade          filter1LP;          //xy=439.1586608886719,70.19056701660156
AudioEffectFade          filter3HP;          //xy=438.21429443359375,390.35719299316406
AudioEffectFade          filter1BP;          //xy=439.6030578613281,104.74610900878906
AudioEffectFade          filter1HP;          //xy=439.6030578613281,137.8572235107422
AudioEffectFade          filter4HP;         //xy=438.21429443359375,521.6071929931641
AudioEffectFade          filter4BP;         //xy=440.71429443359375,489.10719299316406
AudioEffectFade          filter5LP;         //xy=441.96429443359375,586.6071929931641
AudioEffectFade          filter4LP;         //xy=444.46429443359375,457.85719299316406
AudioEffectFade          filter5BP;         //xy=445.71429443359375,620.3571929931641
AudioEffectFade          filter5HP;         //xy=445.71429443359375,652.8571929931641
AudioEffectFade          filter6HP;         //xy=454.2857142857142,788.5714285714284
AudioEffectFade          filter6BP;         //xy=464.2857142857142,762.8571428571428
AudioEffectFade          filter7BP;         //xy=470,894.28564453125
AudioEffectFade          filter7HP;         //xy=471.4285714285714,922.8571428571428
AudioEffectFade          filter6LP;         //xy=474.2857142857142,737.1428571428571
AudioEffectFade          filter7LP;         //xy=475.71428571428566,869.9999999999999
AudioEffectFade          filter8LP;         //xy=479.99999999999994,987.142857142857
AudioEffectFade          filter8HP;         //xy=480,1061.4285278320312
AudioEffectFade          filter8BP;         //xy=481.4285888671875,1024.2857055664062
AudioMixer4              mixer2;         //xy=588.2699584960937,221.85720825195312
AudioMixer4              mixer1;         //xy=593.9366760253906,98.41278076171875
AudioMixer4              mixer3;         //xy=593.7380981445312,354.7223815917969
AudioMixer4              mixer4;         //xy=598.9287719726562,497.7976989746094
AudioMixer4              mixer5;         //xy=599.2461547851562,627.0040283203125
AudioMixer4              mixer6;         //xy=611.4683837890625,756.52783203125
AudioMixer4              mixer7;         //xy=614.1667175292969,892.7183227539062
AudioMixer4              mixer8;         //xy=615.4364624023437,1020.4960327148437
AudioMixer4              mixer9;         //xy=801.4285714285713,207.1428571428571
AudioMixer4              mixer10;        //xy=862.8571428571428,679.9999999999999
AudioMixer4              mixer11;        //xy=1134.28564453125,472.8571472167969
AudioEffectReverb        reverb1;        //xy=1269.9998604910715,472.857173374721
AudioMixer4              mixer12;        //xy=1319.9998779296875,740
AudioOutputAnalog        dac1;           //xy=1527.079345703125,636.3017578125
AudioConnection          patchCord1(waveform2, 0, filter2, 0);
AudioConnection          patchCord2(waveform5, 0, filter5, 0);
AudioConnection          patchCord3(waveform1, 0, filter1, 0);
AudioConnection          patchCord4(waveform3, 0, filter3, 0);
AudioConnection          patchCord5(waveform4, 0, filter4, 0);
AudioConnection          patchCord6(waveform6, 0, filter6, 0);
AudioConnection          patchCord7(waveform7, 0, filter7, 0);
AudioConnection          patchCord8(waveform8, 0, filter8, 0);
AudioConnection          patchCord9(filter5, 0, filter5LP, 0);
AudioConnection          patchCord10(filter5, 1, filter5BP, 0);
AudioConnection          patchCord11(filter5, 2, filter5HP, 0);
AudioConnection          patchCord12(filter2, 0, filter2LP, 0);
AudioConnection          patchCord13(filter2, 1, filter2BP, 0);
AudioConnection          patchCord14(filter2, 2, filter2HP, 0);
AudioConnection          patchCord15(filter6, 0, filter6LP, 0);
AudioConnection          patchCord16(filter6, 1, filter6BP, 0);
AudioConnection          patchCord17(filter6, 2, filter6HP, 0);
AudioConnection          patchCord18(filter1, 0, filter1LP, 0);
AudioConnection          patchCord19(filter1, 1, filter1BP, 0);
AudioConnection          patchCord20(filter1, 2, filter1HP, 0);
AudioConnection          patchCord21(filter3, 0, filter3LP, 0);
AudioConnection          patchCord22(filter3, 1, filter3BP, 0);
AudioConnection          patchCord23(filter3, 2, filter3HP, 0);
AudioConnection          patchCord24(filter4, 0, filter4LP, 0);
AudioConnection          patchCord25(filter4, 1, filter4BP, 0);
AudioConnection          patchCord26(filter4, 2, filter4HP, 0);
AudioConnection          patchCord27(filter7, 0, filter7LP, 0);
AudioConnection          patchCord28(filter7, 1, filter7BP, 0);
AudioConnection          patchCord29(filter7, 2, filter7HP, 0);
AudioConnection          patchCord30(filter8, 0, filter8LP, 0);
AudioConnection          patchCord31(filter8, 1, filter8BP, 0);
AudioConnection          patchCord32(filter8, 2, filter8HP, 0);
AudioConnection          patchCord33(filter2LP, 0, mixer2, 0);
AudioConnection          patchCord34(filter2BP, 0, mixer2, 1);
AudioConnection          patchCord35(filter2HP, 0, mixer2, 2);
AudioConnection          patchCord36(filter3LP, 0, mixer3, 0);
AudioConnection          patchCord37(filter3BP, 0, mixer3, 1);
AudioConnection          patchCord38(filter1LP, 0, mixer1, 0);
AudioConnection          patchCord39(filter3HP, 0, mixer3, 2);
AudioConnection          patchCord40(filter1BP, 0, mixer1, 1);
AudioConnection          patchCord41(filter1HP, 0, mixer1, 2);
AudioConnection          patchCord42(filter4HP, 0, mixer4, 2);
AudioConnection          patchCord43(filter4BP, 0, mixer4, 1);
AudioConnection          patchCord44(filter5LP, 0, mixer5, 0);
AudioConnection          patchCord45(filter4LP, 0, mixer4, 0);
AudioConnection          patchCord46(filter5BP, 0, mixer5, 1);
AudioConnection          patchCord47(filter5HP, 0, mixer5, 2);
AudioConnection          patchCord48(filter6HP, 0, mixer6, 2);
AudioConnection          patchCord49(filter6BP, 0, mixer6, 1);
AudioConnection          patchCord50(filter7BP, 0, mixer7, 1);
AudioConnection          patchCord51(filter7HP, 0, mixer7, 2);
AudioConnection          patchCord52(filter6LP, 0, mixer6, 0);
AudioConnection          patchCord53(filter7LP, 0, mixer7, 0);
AudioConnection          patchCord54(filter8LP, 0, mixer8, 0);
AudioConnection          patchCord55(filter8HP, 0, mixer8, 2);
AudioConnection          patchCord56(filter8BP, 0, mixer8, 1);
AudioConnection          patchCord57(mixer2, 0, mixer9, 1);
AudioConnection          patchCord58(mixer1, 0, mixer9, 0);
AudioConnection          patchCord59(mixer3, 0, mixer9, 2);
AudioConnection          patchCord60(mixer4, 0, mixer9, 3);
AudioConnection          patchCord61(mixer5, 0, mixer10, 0);
AudioConnection          patchCord62(mixer6, 0, mixer10, 1);
AudioConnection          patchCord63(mixer7, 0, mixer10, 2);
AudioConnection          patchCord64(mixer8, 0, mixer10, 3);
AudioConnection          patchCord65(mixer9, 0, mixer11, 0);
AudioConnection          patchCord66(mixer9, 0, mixer12, 0);
AudioConnection          patchCord67(mixer10, 0, mixer11, 1);
AudioConnection          patchCord68(mixer10, 0, mixer12, 1);
AudioConnection          patchCord69(mixer11, reverb1);
AudioConnection          patchCord70(reverb1, 0, mixer12, 2);
AudioConnection          patchCord71(mixer12, dac1);



// synth
float freq = 2000.0;
float lastFreq = 2000.0;
float fmFreq = 20;
float lastFmFreq = 20;
const float fmSineAmp = 1.0;
unsigned int cutOff = 4000;
int ftype = 0;
int filterFadeTime = 200;

int fadeTime = 4000;

extern uint16_t clear, red, green, blue;
extern unsigned int INTEGRATIONTIME_MAXCOUNT;

extern String colorStr;
String lastColorStr;


void Sound_setup() {
    AudioMemory(20);
    waveform1.begin(0.3, 200, WAVEFORM_SINE);
    waveform2.begin(0.3, 400, WAVEFORM_SINE);
    waveform3.begin(0.3, 600, WAVEFORM_SINE);
    waveform4.begin(0.3, 800, WAVEFORM_SINE);
    waveform5.begin(0.3, 1000, WAVEFORM_SINE);
    waveform6.begin(0.3, 1200, WAVEFORM_SINE);
    waveform7.begin(0.3, 1600, WAVEFORM_SINE);
    waveform8.begin(0.3, 2000, WAVEFORM_SINE);
    
    
    
    mixer1.gain(0, 0.5); // lopass
    mixer1.gain(1, 0.0); // bpass
    mixer1.gain(2, 0.0); // hpass
    
    mixer2.gain(0, 0.5); // lopass
    mixer2.gain(1, 0.0); // bpass
    mixer2.gain(2, 0.0); // hpass
    
    mixer3.gain(0, 0.5); // lopass
    mixer3.gain(1, 0.0); // bpass
    mixer3.gain(2, 0.0); // hpass
    
    mixer4.gain(0, 0.5); // lopass
    mixer4.gain(1, 0.0); // bpass
    mixer4.gain(2, 0.0); // hpass
    
    mixer5.gain(0, 0.5); // lopass
    mixer5.gain(1, 0.0); // bpass
    mixer5.gain(2, 0.0); // hpass
    
    mixer6.gain(0, 0.5); // lopass
    mixer6.gain(1, 0.0); // bpass
    mixer6.gain(2, 0.0); // hpass
    
    mixer7.gain(0, 0.5); // lopass
    mixer7.gain(1, 0.0); // bpass
    mixer7.gain(2, 0.0); // hpass
    
    mixer8.gain(0, 0.5); // lopass
    mixer8.gain(1, 0.0); // bpass
    mixer8.gain(2, 0.0); // hpass
    
    // summing
    mixer9.gain(0, 0.4);
    mixer9.gain(1, 0.4);
    mixer9.gain(2, 0.4);
    mixer9.gain(3, 0.4);
    mixer10.gain(0, 0.4);
    mixer10.gain(1, 0.4);
    mixer10.gain(2, 0.4);
    mixer10.gain(3, 0.4);
    // pre verb
    mixer11.gain(0, 0.3);
    mixer11.gain(1, 0.3);

    mixer12.gain(0, 3.0);
    mixer12.gain(1, 3.0);
    mixer12.gain(2, 3.0);
    
    
    // reverb
    reverb1.reverbTime(15.0);
    
    
}

bool faderFlag = true;

void synthState() {
    if (colorStr == "GREY" && colorStr != lastColorStr) {
        fadeIn();
        synthTest3();
        lastColorStr = colorStr;
    } else if (colorStr == "WHITE" && colorStr != lastColorStr) {
        fadeIn();
        synthTest3();
        lastColorStr = colorStr;
    } else if (colorStr == "BLACK" && colorStr != lastColorStr) {
        fadeIn();
        synthTest3();
        lastColorStr = colorStr;
    } else if (colorStr == "RED" && colorStr != lastColorStr) {
        fadeIn();
        synthTest();
        lastColorStr = colorStr;
    } else if (colorStr == "ORANGE" && colorStr != lastColorStr) {
        fadeIn();
        synthTest();
        lastColorStr = colorStr;
    } else if (colorStr == "YELLOW" && colorStr != lastColorStr) {
        fadeOut();
        lastColorStr = colorStr;
    } else if (colorStr == "GREEN" && colorStr != lastColorStr) {
        fadeIn();
        synthTest2();
        lastColorStr = colorStr;
    } else if (colorStr == "BLUE" && colorStr != lastColorStr) {
        fadeIn();
        synthTest();
        lastColorStr = colorStr;
    } else if (colorStr == "PURPLE" && colorStr != lastColorStr) {
        fadeIn();
        synthTest4();
        lastColorStr = colorStr;
    } else if (colorStr == "PINK" && colorStr != lastColorStr) {
        fadeIn();
        synthTest();
        lastColorStr = colorStr;
    }
}



void fadeIn() {
    AudioNoInterrupts();
    filter1LP.fadeIn(fadeTime);
    // filter1BP.fadeIn(fadeTime);
    // filter1HP.fadeIn(fadeTime);
    
    filter2LP.fadeIn(fadeTime);
    // filter2BP.fadeIn(fadeTime);
    // filter2HP.fadeIn(fadeTime);
    
    filter3LP.fadeIn(fadeTime);
    // filter3BP.fadeIn(fadeTime);
    // filter3HP.fadeIn(fadeTime);
    
    filter4LP.fadeIn(fadeTime);
    // filter4BP.fadeIn(fadeTime);
    // filter4HP.fadeIn(fadeTime);
    
    filter5LP.fadeIn(fadeTime);
    // filter5BP.fadeIn(fadeTime);
    // filter5HP.fadeIn(fadeTime);
    
    filter6LP.fadeIn(fadeTime);
    // filter6BP.fadeIn(fadeTime);
    // filter6HP.fadeIn(fadeTime);
    
    filter7LP.fadeIn(fadeTime);
    // filter7BP.fadeIn(fadeTime);
    // filter7HP.fadeIn(fadeTime);
    
    filter8LP.fadeIn(fadeTime);
    // filter8BP.fadeIn(fadeTime);
    // filter8HP.fadeIn(fadeTime);
    AudioInterrupts();
}
void fadeOut() {
    AudioNoInterrupts();
    filter1LP.fadeOut(fadeTime);
    // filter1BP.fadeOut(fadeTime);
    // filter1HP.fadeOut(fadeTime);
    
    filter2LP.fadeOut(fadeTime);
    // filter2BP.fadeOut(fadeTime);
    // filter2HP.fadeOut(fadeTime);
    
    filter3LP.fadeOut(fadeTime);
    // filter3BP.fadeOut(fadeTime);
    // filter3HP.fadeOut(fadeTime);
    
    filter4LP.fadeOut(fadeTime);
    // filter4BP.fadeOut(fadeTime);
    // filter4HP.fadeOut(fadeTime);
    
    filter5LP.fadeOut(fadeTime);
    // filter5BP.fadeOut(fadeTime);
    // filter5HP.fadeOut(fadeTime);
    
    filter6LP.fadeOut(fadeTime);
    // filter6BP.fadeOut(fadeTime);
    // filter6HP.fadeOut(fadeTime);
    
    filter7LP.fadeOut(fadeTime);
    // filter7BP.fadeOut(fadeTime);
    // filter7HP.fadeOut(fadeTime);
    
    filter8LP.fadeOut(fadeTime);
    // filter8BP.fadeOut(fadeTime);
    // filter8HP.fadeOut(fadeTime);
    AudioInterrupts();
}



void synthTest() {
    int co1 = 4000;
    int co2 = 4000;
    int co3 = 4000;
    int co4 = 4000;
    int co5 = 4000;
    int co6 = 4000;
    int co7 = 4000;
    int co8 = 4000;
    
    int wf1 = 4000;
    int wf2 = 4001;
    int wf3 = 4002;
    int wf4 = 4003;
    int wf5 = 4004;
    int wf6 = 4005;
    int wf7 = 4006;
    int wf8 = 4007;
    
    AudioNoInterrupts();
    filter1.frequency(co1);
    filter2.frequency(co2);
    filter3.frequency(co3);
    filter4.frequency(co4);
    filter5.frequency(co5);
    filter6.frequency(co6);
    filter7.frequency(co7);
    filter8.frequency(co8);
    
    waveform1.frequency(wf1);
    waveform2.frequency(wf2);
    waveform3.frequency(wf3);
    waveform4.frequency(wf4);
    waveform5.frequency(wf5);
    waveform6.frequency(wf6);
    waveform7.frequency(wf7);
    waveform8.frequency(wf8);
    AudioInterrupts();
    
    /* Serial.print("co1  "); Serial.println(co1);
    Serial.print("co2  "); Serial.println(co2);
    Serial.print("co3  "); Serial.println(co3);
    Serial.print("co4  "); Serial.println(co4);
    Serial.print("co5  "); Serial.println(co5);
    Serial.print("co6  "); Serial.println(co6);
    Serial.print("co7  "); Serial.println(co7);
    Serial.print("co8  "); Serial.println(co8);
    
    Serial.print("wf1  "); Serial.println(wf1);
    Serial.print("wf2  "); Serial.println(wf2);
    Serial.print("wf3  "); Serial.println(wf3);
    Serial.print("wf4  "); Serial.println(wf4);
    Serial.print("wf5  "); Serial.println(wf5);
    Serial.print("wf6  "); Serial.println(wf6);
    Serial.print("wf7  "); Serial.println(wf7);
    Serial.print("wf8  "); Serial.println(wf8);
    
    Serial.print("fadeIn  ");
    Serial.println(timeGuardInterval2); */
}


void synthTest2() {
    int co1 = 1200;
    int co2 = 1200;
    int co3 = 1200;
    int co4 = 1200;
    int co5 = 1600;
    int co6 = 1600;
    int co7 = 2200;
    int co8 = 2200;
    
    int wf1 = 120;
    int wf2 = 130;
    int wf3 = 140;
    int wf4 = 150;
    int wf5 = 230;
    int wf6 = 150.3;
    int wf7 = 130.2;
    int wf8 = 120.1;
    
    AudioNoInterrupts();
    filter1.frequency(co1);
    filter2.frequency(co2);
    filter3.frequency(co3);
    filter4.frequency(co4);
    filter5.frequency(co5);
    filter6.frequency(co6);
    filter7.frequency(co7);
    filter8.frequency(co8);
    
    waveform1.frequency(wf1);
    waveform2.frequency(wf2);
    waveform3.frequency(wf3);
    waveform4.frequency(wf4);
    waveform5.frequency(wf5);
    waveform6.frequency(wf6);
    waveform7.frequency(wf7);
    waveform8.frequency(wf8);
    AudioInterrupts();
}

void synthTest3() {

    int co1 = 600;
    int co2 = 600;
    int co3 = 600;
    int co4 = 600;
    int co5 = 700;
    int co6 = 700;
    int co7 = 800;
    int co8 = 800;
    
    int wf1 = 200;
    int wf2 = 200.1;
    int wf3 = 300;
    int wf4 = 300.1;
    int wf5 = 500;
    int wf6 = 501;
    int wf7 = 800;
    int wf8 = 807;

/*     int co1 = 600;
    int co2 = 600;
    int co3 = 600;
    int co4 = 600;
    int co5 = 700;
    int co6 = 700;
    int co7 = 800;
    int co8 = 800;
    
    int wf1 = 60;
    int wf2 = 75;
    int wf3 = 90;
    int wf4 = 105;
    int wf5 = 230;
    int wf6 = 340;
    int wf7 = 450;
    int wf8 = 550; */
    
    AudioNoInterrupts();
    filter1.frequency(co1);
    filter2.frequency(co2);
    filter3.frequency(co3);
    filter4.frequency(co4);
    filter5.frequency(co5);
    filter6.frequency(co6);
    filter7.frequency(co7);
    filter8.frequency(co8);
    
    waveform1.frequency(wf1);
    waveform2.frequency(wf2);
    waveform3.frequency(wf3);
    waveform4.frequency(wf4);
    waveform5.frequency(wf5);
    waveform6.frequency(wf6);
    waveform7.frequency(wf7);
    waveform8.frequency(wf8);
    AudioInterrupts();
}

void synthTest4() {
    int co1 = 8400;
    int co2 = 8400;
    int co3 = 8400;
    int co4 = 8400;
    int co5 = 8800;
    int co6 = 8800;
    int co7 = 8800;
    int co8 = 8800;
    
    int wf1 = 6000;
    int wf2 = 7000;
    int wf3 = 6100;
    int wf4 = 7100;
    int wf5 = 6200;
    int wf6 = 7200;
    int wf7 = 7300;
    int wf8 = 7110;
    
    AudioNoInterrupts();
    filter1.frequency(co1);
    filter2.frequency(co2);
    filter3.frequency(co3);
    filter4.frequency(co4);
    filter5.frequency(co5);
    filter6.frequency(co6);
    filter7.frequency(co7);
    filter8.frequency(co8);
    
    waveform1.frequency(wf1);
    waveform2.frequency(wf2);
    waveform3.frequency(wf3);
    waveform4.frequency(wf4);
    waveform5.frequency(wf5);
    waveform6.frequency(wf6);
    waveform7.frequency(wf7);
    waveform8.frequency(wf8);
    AudioInterrupts();
}

void setFilterType(unsigned int ftype) {
    AudioNoInterrupts();
    
    filter1.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.1*1000);
    filter2.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.2*1000);
    filter3.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.3*1000);
    filter4.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.4*1000);
    filter5.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.5*1000);
    filter6.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.45*1000);
    filter7.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.35*1000);
    filter8.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.25*1000);
    
    waveform1.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.1*100);
    waveform2.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.2*100);
    waveform3.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.3*100);
    waveform4.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.4*100);
    waveform5.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.5*100);
    waveform6.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.45*100);
    waveform7.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.35*100);
    waveform8.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.25*100);
    
    // noisey state
    /* filter1.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.1);
    filter2.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.2);
    filter3.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.3);
    filter4.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.4);
    filter5.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.5);
    filter6.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.45);
    filter7.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.35);
    filter8.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.25);
    
    waveform1.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.1);
    waveform2.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.2);
    waveform3.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.3);
    waveform4.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.4);
    waveform5.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.5);
    waveform6.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.45);
    waveform7.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.35);
    waveform8.frequency(INTEGRATIONTIME_MAXCOUNT/ftype*0.25); */
    
    AudioInterrupts();
}

/* void setFilterType(unsigned int ftype) { 
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
} */

/* void Sound_noteOn() {
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
} */



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