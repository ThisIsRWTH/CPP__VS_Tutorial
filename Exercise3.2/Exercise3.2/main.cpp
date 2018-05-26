/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
 * @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 3: Ablauf- und Kontrollstrukturen
 *
 */

/** Defines the number of colums of the field */
#define SIZE_X	8 // IMPORTANT: If you want to change this setting do not include test.h
/** Defines the number of rows of the field */
#define SIZE_Y	8 // IMPORTANT: If you want to change this setting do not include test.h
/** Defines if tests will run. */
#define TEST 1
/** Defines if output of tests will be verbose */
#define VERBOSE 0

#include <iostream>
#include <string>
#include <stdlib.h>
#include "test.h"
#include "Reversi_KI.h"
using namespace std;

/*!
 *  @brief Prints the field to the console
 *
 *  @param field The field, which will be printed
 */
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

	for (int j = 65; j < 65 + SIZE_Y; j++)
	{
		std::cout << ((char) j) << "|";
	}
	std::cout << std::endl;
	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1 << "|";
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
			case 0:
				std::cout << " |";
				break;
			case 1:
				std::cout << "X|";
				break;
			case 2:
				std::cout << "O|";
				break;
			default:
				std::cout << "Inconsistent data in field!" << std::endl;
				std::cout << "Aborting .... " << std::endl;
				exit(0);
				break;
			}
		}; //for j
		std::cout << std::endl;
	} //for i
}


/*!
 * @brief checks the winner for a given field.
 * @param field (int[][]) is the given field.
 * @return 1 if player 1 won and 2 if player 2 won. Returns 0 in case of draw.
 */
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			//loop through all fields + counting of X (1) and O (2)
			if (field[j][i] == 1) {
				count_p1++;
			} else if (field[j][i] == 2) {
				count_p2++;
			}
		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p1 < count_p2)
	{
		return 2;
	} else
	{
		return 1;
	}
}

/*!
 * @brief Checks, whether a certain turn can be executed.
 *
 * 	@param field is the current field,
 * 	@param player is the active player (1 or 2),
 * 	@param pos_x is the X-coordinate of the cell to be occupied.
 * 	@param pos_y is the Y-coordinate of the cell to be occupied.
 *
 * 	@return true if yes and false if not.
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
	// if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (field[pos_y + j][pos_x + i] != opponent)
				continue;

			int rev_y = pos_y;
			int rev_x = pos_x;
			while ((rev_x += i) >= 0 && rev_x < SIZE_X && (rev_y += j) >= 0 && rev_y < SIZE_Y)
			{
				if (field[rev_y][rev_x] == player)
				{
					return true;
				} else if (field[rev_y][rev_x] == 0)
				{
					break;
				}
			}
		}
	}
	return false;
}

/*!
 * @brief Executes a certain turn on the field
 *
 * 	@param field is the field where the turn shall be executed
 * 	@param player is the active player (1, or 2)
 * 	@param pos_x is the X-coordinate of the cell to be occupied.
 * 	@param pos_y is the Y-coordinate of the cell to be occupied.
 */

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y)
{
	// very similar to function "turn_valid" - just take care that all opponent
	// stones are changed to yours
	int opponent = 3 - player;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (field[pos_y + j][pos_x + i] != opponent)
				continue;

			int temp_Y = pos_y + j;
			int temp_X = pos_x + i;
			while (temp_X >= 0 && temp_X < SIZE_X && temp_Y >= 0 && temp_Y < SIZE_Y)
			{
				if (field[temp_Y][temp_X] == opponent)
				{
					temp_Y += j;
					temp_X += i;
					continue;
				} else if (field[temp_Y][temp_X] == player)
				{
					// when found a possible turn...
					while (temp_Y != pos_y || temp_X != pos_x)
					{
						// go backwards and replace all opponent cells
						temp_Y -= j;
						temp_X -= i;
						field[temp_Y][temp_X] = player;
					}
					break;
				} else // cell is = 0
					break;
			}
		}
	}
}
/*!
 * @brief Counts number of possible turns for a player in a given field.
 *
 * 	@param field (int[][]) is the given field,
 * 	@param player (int) is the active player (1 or 2).
 *
 * 	@return the number of possible turns.
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int possibilities = 0;
	for (int i=0;i<SIZE_X;i++)
	{
		for (int j=0;j<SIZE_Y;j++)
		{
			if (turn_valid(field, player, i, j)) {
				possibilities++;
			}
		}
	}
	return possibilities;
}

/*!
 * @brief Lets the human do his turn.
 *
 * 	@param field (int) is the current field
 * 	@param player (int, 1 or 2) is the active player
 *
 * 	@return true if turn is valid and false if not.
 */
bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}
	int px;
	int py;
	bool repeat = false;

	do
	{
		if (repeat)
		{
			std::cout << std::endl << "Invalid input !" << std::endl;

		}
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): ";
		input.erase(input.begin(), input.end());
		std::cin>>input;
		px = ((int) input.at(0)) - 65;
		py = ((int) input.at(1)) - 49;

		repeat = !turn_valid(field, player, px, py);
	} while (repeat);
	execute_turn(field, player, px, py);
	return true;
}

/*!
 * @brief Plays the game Reversi.
 *
 * @param playertyp (int[2]) in which playertyp[i]=0 means a human player and playertyp[i]=1 means a computer player.
 */

void game(const int playertyp[2])
{
	/* for SIZE_X = 8 and SIZE_Y = 8 equals:
	 int spielfeld[SIZE_Y][SIZE_X] = {
	 {0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0},
	 {0,0,0,1,2,0,0,0},
	 {0,0,0,2,1,0,0,0},
	 {0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0}};*/

	int field[SIZE_Y][SIZE_X];
	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			field[j][i] = 0;
		}
	}
	field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
	field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
	field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
	field[SIZE_Y / 2][SIZE_X / 2] = 1;

	int current_player = 1;
	show_field(field);
	//let each player make its moves until no further moves are possible
	std::cout<<"Spieler 1 spielt X"<<std::endl<<"Spieler 2 spielt O"<<std::endl;

	do{
		std::cout<<std::endl;

		switch(playertyp[current_player-1]){
		case 0: std::cout<<"Spieler "<<current_player<<" (Mensch) ist an der Reihe"<<std::endl;		//human turn
		if(!human_turn(field,current_player)){
			std::cout<<"kein Zug möglich für Spieler "<<current_player<<"."<<std::endl;
		}
		break;
		case 1: std::cout<<"Spieler "<<current_player<<" (Computer) ist an der Reihe"<<std::endl;	//computer turn
		if(!computer_turn(field,current_player)){
			std::cout<<"kein Zug möglich für Spieler "<<current_player<<"."<<std::endl;
		}
		}
		current_player = 3-current_player;
		show_field(field);
	}while(!(possible_turns(field,1)==0 && possible_turns(field,2)==0));

	switch (winner(field))
	{
	case 0:	std::cout<<"Die Partie ist unentschieden ausgegangen"<<std::endl;
	break;
	case 1: std::cout<<"Spieler 1 hat gewonnen."<<std::endl;
	break;
	case 2:	std::cout<<"Spieler 2 hat gewonnen."<<std::endl;
	}
	char YesNoInput;
	bool validInput=false;
	do{
		std::cout<<"Nochmal? [J]a [N]ein?"<<std::endl;
		std::cin>>YesNoInput;
		switch((int)YesNoInput){
		case 'J':
		case 'j':
			//main();
			validInput = true;
			break;
		case 'N':
		case 'n':
			std::cout<<"Bis zum nächsten Mal!"<<std::endl;
			validInput = true;
		}
	}while(!validInput);

}

/*!
 * @brief main method (void)
 *
 * @return 0 when succeeded.
 */
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		} else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	char playerInput;
	bool validInput = 0;
	int typ[2];

	for(int i=0; i<2; i++){
		do {
			std::cout<<"Spieler "<<i+1<<": [C]omputer oder [M]ensch?"<<std::endl;
			std::cin>>playerInput;
			switch(playerInput){
			case 'C':
			case 'c':
				typ[i]=1;
				validInput = true;
				break;
			case 'M':
			case 'm':
				typ[i]=0;
				validInput = true;
				break;
			}
		} while (!validInput);
	}

	game(typ);
	return 0;
}
