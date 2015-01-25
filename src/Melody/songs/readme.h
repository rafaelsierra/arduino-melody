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
 *                || || || |
 *		          || || |+-+> Note you are playing 000=A, 001=B, 010=C, ..., 111=G
 *                || |+-+--> Its duration
 *                |+-+-> Its octave 
 *                +-> Is it a pause? (0=no, 1=yes, duh...)
 */
#include <Melody.h>
 
int sample_music[] = {, B00000011, B00000100,};
int sample_music_size = 