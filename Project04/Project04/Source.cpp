#include <iostream>
#include <conio.h>
using namespace std;

int square(int a);

int main()
{
	cout << square(9);

	_getch();
	return 0;
}

int square(int a)
{
	int b = a*a;
	return b;
}