
#include <iostream>
#include <string>
#include "shape.h"
#include "circle.h"
#include <conio.h>
using namespace std;





int main()
{
	Shape a;
	cout << a.getColor() << endl;

	Circle c1;
	cout << c1.getColor() << endl;

	c1.specificFunctionOnlyDefinedInCircle();
	
	cout << c1.getBright() << endl;




	_getch();
	return 0;
}
