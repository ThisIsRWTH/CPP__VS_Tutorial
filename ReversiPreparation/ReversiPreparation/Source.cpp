#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	const int SIZE_X = 8;
	const int SIZE_Y = 8;
	char board[SIZE_X][SIZE_Y] = {};

	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			//ghotre asli:  i + j == SIZE-1
			//ghotre farsi: i - j == 0
			//ghotre asli with offset: i + j == SIZE-1 + offset [0..Size/2]
			//ghotre asli with offset: i - j ==  0 + offset [0..Size/2]
			if (i - j == -1)
			{
				board[i][j] = 'X';
			}
			else
			{
				board[i][j] = 'O';
			}

		}
	}

	//print board

	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			cout << board[i][j]<<' ';

		}
		cout << endl;
	}

	_getch();
	return 0;
}