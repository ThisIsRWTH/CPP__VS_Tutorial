/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include <iostream>

extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/*!
 * @brief A function, which tests if the winner is valid
 *
 * @param field The field of the game.
 * @param winner_code The real winner
 * @return True if the test passed, false if not
 */
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
	std::cout << "----------------------------" << std::endl;
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "Checking who wins" << std::endl;
	int result = winner(field);
	if (result == winner_code)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		if (VERBOSE == 1)
		{
			std::cout << "Calculated result: " << result << std::endl
					<< "Right result: " << winner_code << std::endl;
		}
		return false;
	}
}

/*!
 * @brief A function, which tests if the turn is valid
 *
 * @param field The field of the game.
 * @param player The player number
 * @param pos_x The x position on the field
 * @param pos_y The y position on the field
 * @param valid the expected result
 *
 * @return True if the test passed, False if not
 */
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y, const bool valid)
{
	std::cout << "----------------------------" << std::endl;
	std::cout << "Running turn validation test..." << std::endl;
	bool result = turn_valid(field, player, pos_x, pos_y);
	if (result == valid)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		if (VERBOSE == 1)
		{
			std::cout << "Calculated result: " << result << std::endl
					<< "Right result: " << valid << std::endl;
		}
		return false;
	}
	return 0;
}

/*!
 * @brief A function, which tests, if the executed turn is valid
 *
 * @param input The field, before the turn was executed
 * @param output The field, after the turn was exectuted
 * @param player The player, whicht exectued the turn
 * @param pos_x The x position in the field, where the turn was executed
 * @param pos_y The y position in the field, where the turn was exectued
 *
 * @return True, if the test passed, false if not
 */
bool test_execute_turn(int input[SIZE_Y][SIZE_X],
		const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y)
{
	// check for a given field whether the execution of a turn is valid
	std::cout << "----------------------------" << std::endl;
	std::cout << "Running turn execution test... at x:" << pos_x << ", y:"
			<< pos_y << std::endl;
	execute_turn(input, player, pos_x, pos_y);
	bool passed = true;
	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			if (input[j][i] != output[j][i])
			{
				passed = false;
				break;
			}
		}
	}
	if (passed)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		if (VERBOSE == 1)
		{
			std::cout << "Calculated result: " << std::endl;
			show_field(input);
			std::cout << "Right result: " << std::endl;
			show_field(output);
		}
		return false;
	}
	return 0;
}

/*!
 * @brief A function, which checks if the number possible turns calculated are correct
 *
 * @param field The field of the game.
 * @param player The player number
 * @param count_possible_turns the actual number of possible turns
 *
 * @return True if the test passed, False if not
 */
bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
		const int count_possible_turns)
{
	// very if your function finds all possible turns
	std::cout << "----------------------------" << std::endl;
	std::cout << "Running possible turns test..." << std::endl;
	int result = possible_turns(field, player);

	if (result == count_possible_turns)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		if (VERBOSE == 1)
		{
			std::cout << "Calculated result: " << result << std::endl
					<< "Right result: " << count_possible_turns << std::endl;
		}
		return false;
	}
	return 0;
}

/*!
 * @brief A function, which does a full test of the game
 *
 * @return True if the test passed, False if not
 */
bool run_full_test(void)
{
	bool result = true;

	// ----- CHECK WINNER -----

	int winner_matrix[3][8][8] =
	{+
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 } },
	{
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 2, 2, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 } },
	{
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2 } } };

	int winner_code[3] =
	{ 0, 2, 1 };

	for (int i = 0; i < 3; i++)
	{
		if (!test_winner(winner_matrix[i], winner_code[i]))
		{
			result = false;
		}
	}

	// ----- CHECK TURN VALID -----

	int turnvalid_matrix[6][8][8] =
	{
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 1, 1, 0, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } },

	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 0, 0, 2, 1, 1 },
	{ 0, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 1, 1, 0, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } },

	{
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } },

	{
	{ 0, 1, 0, 0, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 2, 0, 1, 2, 0, 2, 0, 0 },
	{ 0, 2, 0, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0 } },

	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 0, 2, 2, 1 } },

	{
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } } };

	int turnvalid_player[6] =
	{ 1, 2, 2, 1, 2, 1 };   // Player at for given test
	int turnvalid_pos[6][2] =
	{
	{ 2, 3 },
	{ 0, 3 },
	{ 4, 3 },
	{ 3, 4 },
	{ 3, 5 },
	{ 3, 4 } };  // {X-Position, Y-Position}
	bool turnvalid_valid[6] =
	{ 0, 0, 0, 1, 1, 0 };   // Correct Answer

	for (int i = 0; i < 6; i++)
	{
		if (!test_turn_valid(turnvalid_matrix[i], turnvalid_player[i],
				turnvalid_pos[i][0], turnvalid_pos[i][1], turnvalid_valid[i])
				!= 0)
		{
			result = false;
		}

	}

	// ----- CHECK EXECUTE TURN -----

	int executeturn_matrix_in[5][8][8] =
	{
	{
	{ 0, 1, 0, 0, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 2, 0, 1, 2, 0, 2, 0, 0 },
	{ 0, 2, 0, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0 } },

	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 0, 2, 2, 1 } },
	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 0, 2, 2, 1 } },
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 1, 1, 0, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } },
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 1, 1, 0, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } }

	};

	int executeturn_matrix_out[5][8][8] =
	{
	{
	{ 0, 1, 0, 0, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 2, 0, 1, 2, 0, 1, 0, 0 },
	{ 0, 2, 0, 2, 1, 2, 2, 2 },
	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0 } },
	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 2, 0, 1, 0, 0 },
	{ 1, 0, 0, 2, 1, 0, 0, 2 },
	{ 0, 0, 0, 2, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 0, 2, 2, 1 } },
	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 1, 1, 1, 1 } },
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 2, 1, 0, 2 },
	{ 1, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 2, 0, 0, 1, 0, 1 } },
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 2, 2, 2, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } } };

	int executeturn_player[5] =
	{ 1, 2, 1, 2, 2 };
	int executeturn_pos[5][2] =
	{
	{ 3, 4 },
	{ 3, 5 },
	{ 4, 7 },
	{ 2, 7 },
	{ 6, 5 } };

	for (int i = 0; i < 5; i++)
	{
		if (!test_execute_turn(executeturn_matrix_in[i],
				executeturn_matrix_out[i], executeturn_player[i],
				executeturn_pos[i][0], executeturn_pos[i][1]))
		{
			result = false;
		}
	}

	// ----- CHECK POSSIBLE TURNS -----

	int possibleturns_matrix[2][8][8] =
	{
	{
	{ 1, 0, 2, 0, 0, 1, 1, 1 },
	{ 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 2, 2 },
	{ 2, 2, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 2, 0 },
	{ 0, 0, 0, 2, 2, 2, 2, 2 },
	{ 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 } },
	{
	{ 2, 1, 0, 0, 2, 1, 1, 1 },
	{ 0, 2, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 2, 0 },
	{ 1, 1, 2, 0, 0, 2, 2, 1 } }

	};

	int possibleturns_player[2] =
	{ 1, 2 };
	int possibleturns_count[2] =
	{ 4, 5 };

	for (int i = 0; i < 2; i++)
	{
		std::cout << "Test possible turns" << std::endl;
		if (!test_possible_turns(possibleturns_matrix[i],
				possibleturns_player[i], possibleturns_count[i]))
		{
			result = false;
		}
	}

	return result;

}
