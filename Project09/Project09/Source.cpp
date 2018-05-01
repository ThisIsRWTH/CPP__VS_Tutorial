#include<iostream>
#include<conio.h>
using namespace std;

void func_double(int *aptr, int *bptr, int *cptr);
int main()
{
	int x = 10;
	int y = 20;
	int z = 30;
	func_double(&x, &y, &z);
	cout << x << " " << y << " " << z << endl;

	_getch();
	return 0;
}

void func_double(int *aptr, int *bptr, int *cptr)
{
	*(aptr) = *(aptr) * 2;
	*(bptr) = *(bptr) * 2;
	*(cptr) = *(cptr) * 2;

	return;
}