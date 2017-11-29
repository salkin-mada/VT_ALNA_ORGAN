#ifndef SOUND_H
#define SOUND_H

extern long timeGuardInterval2;

void Sound_setup();
void synthTest();
void synthTest2();
void synthTest3();
void synthTest4();
void synthTest5();
void synthTest6();
void synthTest7();
void synthState();
void vanligMix();
void lavMix();
void hojMix();
void fadeIn();
void fadeOut();
void setFreq(unsigned int setter);
void setFmFreq(unsigned int setter);
void setFilterType(unsigned int ftype);
// void Sound_noteOn();
// void Sound_apply();

#endif
