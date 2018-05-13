#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char letter;

	cout << "Please input the desired letter: ";
	cin >> letter;

	cout << "This letter is the " << (letter % 32) << "(th) letter in deuschte Alphabet\n";

	//Part02 => Your solution
	int letter_number;
	cout << "Please input the ASCII code for your desired letter: ";
	cin >> letter_number;
	cout << "Your ASCII code is equal to " << ( letter_number % 32)<< "(th) "<<" ["<<(char)letter_number<<"] "<<"character in deuschte Alphabet .\n";



	_getch();
	return 0;
}