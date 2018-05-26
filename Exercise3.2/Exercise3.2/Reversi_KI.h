/**
 * @file Reversi_KI.h
 *
 * Provides a KI for the game Reversi.
 */

#ifndef REVERSI_KI_H_
#define REVERSI_KI_H_

#ifndef SIZE_X
/** Defines the number of colums of the field */
#define SIZE_X	8
#endif
#ifndef SIZE_Y
/** Defines the number of rows of the field */
#define SIZE_Y	8
#endif

bool computer_turn(int field[SIZE_Y][SIZE_X], const int player);

#endif /* REVERSI_KI_H_ */
