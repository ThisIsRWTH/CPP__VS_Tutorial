#include <iostream>
#include <conio.h>
using namespace std;

int sum(int a, int b); // another correct syntax ==> int sum(int, int);

int main()
{
	cout << sum(3, 8);

	_getch();
	return 0;
}

int sum(int a, int b)
{
	int c = a + b;
	
	return c;
}