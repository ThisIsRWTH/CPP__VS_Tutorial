#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int a = 10;
	int &aref = a;
	cout << a << endl;

	a++;
	cout << aref << endl;

	aref++;
	cout << a << endl;


	_getch();
	return 0;
}