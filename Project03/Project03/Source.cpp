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

	int arr[5] = { 1000,1001,1002,1003,1004 };
	int &arr_ref = arr[1];
	arr_ref++;
	cout << arr_ref;
	cout << arr[1];

	int *arr_ptr = arr;
	// arr = arr + 1; >> Error!
	arr_ptr = arr_ptr + 1;
	arr_ptr++;
	//arr++; >> Error!

	arr_ptr = arr + 3;

	int* aptr02; // int* a == int *a;


	_getch();
	return 0;
}









