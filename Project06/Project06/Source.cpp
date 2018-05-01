#include <iostream>
#include <conio.h>
using namespace std;

char tolittle(char key);

int main()
{
	char res;
	res = tolittle('f');

	cout << res;
	_getch();
	return 0;
}

char tolittle(char key)
{
	char result = 0;
	if (key > 'a' && key < 'z')
	{
		result = key;
	}
	else if (key > 'A' && key < 'Z')
	{
		result = key + 32;
	}
	else
	{
		result = key;
	}

	return result;
}