#include "Arduino.h"
#include "Melody.h" 
#include <stdlib.h>
#include <string.h>
#include <math.h>

Melody::Melody(int pin){
    _pin = pin;

    // Set the base octave, every note will play above this octave
    this->octave = 4;

    // Set the pin
    pinMode(_pin, OUTPUT);   
}

Melody::~Melody(){
    
}

void Melody::setOctave(int octave){
    this->octave = octave;
}

int Melody::getFreq(int note, int pitch){
    // TODO: Fix this since there there is no A anymore
    //return (int)(440.0 * pow(1.059463094359,(note+12*pitch)-(A+48)));
}

void Melody::play(int *riff, int size){
    riffSize = size;
    int memsize = riffSize*sizeof(int);
    this->riff = (int *)malloc(memsize);
    memcpy(this->riff, riff, memsize);
    // Restart the timer
    delta = 0;
    lastMillis = millis();
    // Plays the first note
    currentNote = 0;
    if(this->riff[0] >= 0){
    	tone(_pin, getFreq(this->riff[0],octave)); 
    }

}

void Melody::play(){
    // TODO: Loop over maximum time
    delta += millis()-lastMillis;
    lastMillis = millis();

    if(delta >= tempo){
        delta = 0;
        currentNote = (currentNote+1 >= riffSize)?0:currentNote+1;
        noTone(_pin);
	    if(riff[currentNote] >= 0){	
            int f = getFreq(riff[currentNote],this->octave);
            tone(_pin, f);
            #if MELODY_DEBUG==1
            this->print->println(f);
            #endif
        }
    }
}
#if MELODY_DEBUG==1
void Melody::setSerial(Print &print){
    this->print = &print;
}
#endif
