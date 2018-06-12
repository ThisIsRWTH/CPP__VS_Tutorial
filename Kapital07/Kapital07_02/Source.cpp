#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void print(int a);
void print(char a);


int main()
{
	cout << "This is project07_02";

	_getch();
	return 0;
}

void print(int a)
{
	cout << "print for int: "<< a << endl;
}

void print(char a)
{
	cout << "print for char: " << a << endl;
}
