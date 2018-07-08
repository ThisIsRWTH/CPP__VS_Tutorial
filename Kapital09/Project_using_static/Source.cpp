#include <iostream>
#include <conio.h>
using namespace std;

void function();

int main()
{
	function();
	function();

	_getch();
	return 0;
}

void function()
{
	static int a = 100;
	int b = 0;
	
	a++;
	b++;
	cout << a << endl;
	cout << b << endl;
	cout << endl;

	return;
}
