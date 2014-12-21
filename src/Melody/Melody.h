#ifndef MELODY_RS
#define MELODY_RS

#define MELODY_DEBUG 0

#include "Arduino.h"

class Melody{
  public:
    Melody(int pin);
    ~Melody();
    int A, As, B, C, Cs, D, Ds, E, F, Fs, G, Gs;
    int  octave;

    int *tetris;
    int tetris_size;

    void play(int *riff, int size);
    void play();
    void setOctave(int octave);

    int getFreq(int note, int pitch);
    #if MELODY_DEBUG==1
    void setSerial(Print &print);
    Print *print;
    #endif  
  private:
    int _pin;
    unsigned int delta;
    unsigned long lastMillis;
    int *riff;
    int riffSize;
    int tempo;
    int currentNote;
    
};
#endif
