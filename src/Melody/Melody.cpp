#include "Arduino.h"
#include "Melody.h" 
#include <stdlib.h>
#include <string.h>
#include <math.h>

Melody::Melody(int pin){
    _pin = pin;

    // Set the base octave, every note will play above this octave
    this->octave = 4;
    // Set the default tempo in bpm, two beats per second
    this->tempo = 120;
    // Set the pin
    pinMode(_pin, OUTPUT);   
}

Melody::~Melody(){
    
}

void Melody::setOctave(int octave){
    this->octave = octave;
}

void Melody::setTempo(int tempo){
    this->tempo = tempo;
}

int Melody::getFreq(int note, int pitch){
    if(note & MN_PAUSE) return 0;

    // Clear every other bit so we have only the number of the note, from 0 to 12
    int octave = (note&MN_OCTAVE_MASK)>>MN_OCTAVE_PAD;
    note &= MN_NOTE_MASK;

    int note_pos = ((this->octave+octave)*12)+note;
    int n = note_pos - MN_A4;

    return (int)(pow(2, n/12)*400);
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
}

void Melody::play(){
    if(currentNote >= this->riffSize){
        currentNote = 0;
    }



    currentNote++;
    
}
#if MELODY_DEBUG==1
void Melody::setSerial(Print &print){
    this->print = &print;
}
#endif
