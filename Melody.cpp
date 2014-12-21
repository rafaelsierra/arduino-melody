#include "Arduino.h"
#include "Melody.h" 
#include <stdlib.h>
#include <string.h>
#include <math.h>

Melody::Melody(int pin){
    // From: http://en.wikipedia.org/wiki/Scientific_pitch_notation
    // Values are rounded to avoid lots of floats/double
    A=1; As=2; B=3; C=4; Cs=5; D=6; Ds=7; E=8; F=9; Fs=10; G=11; Gs=12;
    
    _pin = pin;
    tempo = (int)((20.0/60.0)*1000); // TODO: set/get 

    // Is this really the best way to do this?
    int _tetris[] = {
        G,G,G,D,E,F,F,E,D,C,C,C,E,G,G,F,E,D,D,D,E,F,G,E,C,C,C,
        F,F,F,A+12,C+12,B+12,A+12,G,G,E,G,F,E,D,D,D,E,F,G,E,C,C,C,-1
    };
    //int _tetris[] = {E,E,B,C,D,C,D,B,A,A,C,E,D,C,B,C,D,E,C,A,A,D,F,A+12,G,F,E,C,E,D,C,B,B,C,D,E,C,A,A,E,C,D,B,C,A,Gs-12,B,E,C,D,B+12,A,C,A,Gs};
    this->tetris_size = 51;
    int memsize = this->tetris_size*sizeof(int);
    this->tetris = (int *)malloc(memsize);    
    memcpy(this->tetris, _tetris, memsize);
    free(_tetris);

    // Set the default octave 
    this->octave = 4;

    // Set the pin
    pinMode(_pin, OUTPUT);   
}

Melody::~Melody(){
    free(this->tetris);
}

void Melody::setOctave(int octave){
    this->octave = octave;
}

int Melody::getFreq(int note, int pitch){
    return (int)(440.0 * pow(1.059463094359,(note+12*pitch)-(A+48)));
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
