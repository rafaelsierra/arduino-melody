/*
 * This file explains how to write a song to play using Melody
 */

/*
 * Each note contains information about:
 *  the note it self (from A to G)
 *  its duration  (from 0 to 7 units-of-time)
 *  its octave (from 0 to 7), note that octaves are not absolute, it depends 
 *		on thee Melody::setOctave() value, so you can go as far as 4 octaves 
 *		above the default
 *  if its a pause
 */

/*
 * Note structure:
 * int C = B0000000000000000
 *               || || ||  |
 *		         || || |+--+-> Note you are playing 0001=A, 0010=A#/Bb, 0011=C, ..., 1100=G#/Ab
 *               || |+-+--> Its duration
 *               |+-+-> Its octave 
 *               +-> Is it a pause? (0=no, 1=yes, duh...)
 */
#include "Melody.h"

int sample_music[] = {MND_C, MND_D, MND_E, MN_F | MN_D2, MND_F, MND_F, MND_C, MND_D, MND_C, MND_D, MND_D, MND_D, MND_C, MND_E, MND_F, MND_E, MND_E, MND_E, MND_C, MND_D, MND_E, MN_F | MN_D2, MND_F, MND_F};
int sample_music_size = 24;