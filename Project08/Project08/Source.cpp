#include <iostream>
#include <conio.h>
using namespace std;
int func_double(int &, int &, int &);
int main()
{
	int x = 10;
	int y = 20;
	int z = 30;

	int a = func_double(x, y, z);

	cout << "Output values are: " << x <<" "<< y <<" "<< z<<endl;
	cout << a;


	_getch();
	return 0;
}

int func_double(int &A, int &B, int &C)
{
	A = A * 2;
	B = B * 2;
	C = C * 2;

	return 500;
}

