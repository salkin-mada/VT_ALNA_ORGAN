#ifndef SOUND_H
#define SOUND_H

void Sound_setup();
void setFreq(unsigned int setter);
void setFmFreq(unsigned int setter);
void setFilterType(unsigned int ftype);
void Sound_noteOn();
void Sound_apply();

#endif
