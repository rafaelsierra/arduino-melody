#ifndef MELODY_RS
#define MELODY_RS

#define MELODY_DEBUG 0
// MN means Melody Note
#define MN_A = 0x1
#define MN_B = 0x2
#define MN_C = 0x3
#define MN_D = 0x4
#define MN_E = 0x5
#define MN_F = 0x6
#define MN_G = 0x7

#define MN_D1 = 0x8
#define MN_D2 = 0x10
#define MN_D3 = 0x18
#define MN_D4 = 0x20
#define MN_D5 = 0x28
#define MN_D6 = 0x30
#define MN_D7 = 0x38

#define MN_O1 = 0x40
#define MN_O2 = 0x80
#define MN_O3 = 0xc0
#define MN_O4 = 0x100
#define MN_O5 = 0x140
#define MN_O6 = 0x180
#define MN_O7 = 0x1c0

// MND means Melody Note Default
#define MND_DO MN_D1 | MN_O1
#define MND_A MND_DO | MN_A
#define MND_B MND_DO | MN_B
#define MND_C MND_DO | MN_C
#define MND_D MND_DO | MN_D
#define MND_E MND_DO | MN_E
#define MND_F MND_DO | MN_F
#define MND_G MND_DO | MN_G
#define MND_PAUSE MND_DO | MN_PAUSE


#define MN_PAUSE = 0x200

#include "Arduino.h"

class Melody{
  public:
    Melody(int pin);
    ~Melody();
    
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
    int octave;
    unsigned int delta;
    unsigned long lastMillis;
    int *riff;
    int riffSize;
    int tempo;
    int currentNote;
};
#endif
