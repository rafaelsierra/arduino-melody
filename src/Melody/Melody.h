#ifndef MELODY_RS
#define MELODY_RS

#define MELODY_DEBUG 1
/*
 * Each note contains information about:
 *  the note it self (from A to G)
 *  its duration  (from 1 to 32 beats)
 *  its octave (from 0 to 7), note that octaves are not absolute, it depends 
 *      on thee Melody::setOctave() value, so you can go as far as 4 octaves 
 *      above the default
 *  if its a pause
 */

/*
 * Note structure:
 * int C = B0000000000000000
 *             || |||  ||  |
 *             || |||  |+--+-> Note you are playing 0001=A, 0010=A#/Bb, 0011=C, ..., 1100=G#/Ab
 *             || ||+--+--> Its duration
 *             || |+-> If its tempo is a fraction of the tempo or double it
 *             |+-+-> Its octave 
 *             +-> Is it a pause? (0=no, 1=yes, duh...)
 */

// MN means Melody Note
#define MN_A 0x1
#define MN_As 0x2
#define MN_Bb 0x2
#define MN_B 0x3
#define MN_C 0x4
#define MN_Cs 0x5
#define MN_Db 0x5
#define MN_D 0x6
#define MN_Ds 0x7
#define MN_Eb 0x7
#define MN_E 0x8
#define MN_F 0x9
#define MN_Fs 0xa
#define MN_Gb 0xa
#define MN_G 0xb
#define MN_Gs 0xc
#define MN_Ab 0xc

#define MN_PAUSE 0x1000

#define MN_D1 0x10
#define MN_D2 0x20
#define MN_D3 0x30
#define MN_D4 0x40
#define MN_D5 0x50
#define MN_D6 0x60
#define MN_D7 0x70
#define MN_D8 0x80
#define MN_D9 0x90
#define MN_D10 0xa0
#define MN_D11 0xb0
#define MN_D12 0xc0
#define MN_D13 0xd0
#define MN_D14 0xe0
#define MN_D15 0xf0

// TODO: Octaves below
#define MN_O0 0x200 // This uses the current octave
#define MN_O1 0x400
#define MN_O2 0x600
#define MN_O3 0x800
#define MN_O4 0xa00
#define MN_O5 0xc00
#define MN_O6 0xe00

// MND means Melody Note Default
#define MND_DO MN_D2 | MN_O0
#define MND_A MND_DO | MN_A
#define MND_B MND_DO | MN_B
#define MND_C MND_DO | MN_C
#define MND_D MND_DO | MN_D
#define MND_E MND_DO | MN_E
#define MND_F MND_DO | MN_F
#define MND_G MND_DO | MN_G
#define MND_PAUSE MND_DO | MN_PAUSE

#define MN_NOTE_MASK 0xf
#define MN_DURATION_MASK 0x1f0
#define MN_OCTAVE_MASK 0xe00
#define MN_OCTAVE_PAD 9

// DO NOT USE A4 AS NOTE! Use MN_A | MN_O4 instead!
#define MN_A4 ((4*12)+MN_A) // 4th octave, A. Used as reference the get the correct frequency

#include "Arduino.h"

class Melody{
  public:
    Melody(int pin);
    ~Melody();
    
    void play(int *riff, int size);
    void play();
    void setOctave(int octave);

    void setTempo(int tempo);

    int getFreq(int note);
    #if MELODY_DEBUG==1
        void setSerial(Print &print);
        Print *print;
    #endif  
  private:
    int _pin;
    int octave;
    
    unsigned int delta;
    unsigned long lastMillis;
    int millisPerBeat;

    int *riff;
    int riffSize;
    int tempo;
    int currentNote;
};
#endif
