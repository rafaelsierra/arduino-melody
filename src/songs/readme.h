/*
 * This file explains how to write a song to play using Melody
 */

#include "Melody.h"
/*
 * //Use MN_A to MN_G (including flat and sharp notes, just add s or b to the note, e.g. MN_Ab) to choose your note
 * int myC = MN_C;
 * // Then choose at what octave it will play, from MN_O1 to MN_O7
 * myC |= MN_O2
 * // And finally, for how long this will play:
 * myC |= MN_D1
 * // Now you can use myC as a note in a integer list
 * int riff[] = {myC,...}
 *
 * You can also create your notes in a single line:
 * int E1 = MN_E|MN_D2|MN_O3
 * 
 * After creating all the notes you need, you can make your riff:
 * int riff[] = {C1, A2, PAUSE_SHORT, E3, ...};
 * 
 * To use your riff you also need to know the size of your integer list and store it in a variable
 * int riff_size = 32;
 * 
 * Below there is a sample music using default notes (MND_A to MND_G)
 */
int sample_music[] = {MND_C, MND_D, MND_E, MN_F | MN_D4, MND_F, MND_F, MND_C, MND_D, MND_C, MND_D, MND_D, MND_D, MND_C, MND_G, MND_F, MN_E | MN_D4, MND_E, MND_E, MND_C, MND_D, MND_E, MN_F | MN_D4, MND_F, MND_F, MN_PAUSE | MN_D2};
int sample_music_size = 25;