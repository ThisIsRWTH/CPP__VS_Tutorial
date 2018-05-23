#include <iostream>
#include <conio.h>
#include <string>
#include "Lamp.h"
using namespace std;

int main()
{
	Lamp l1 = Lamp();
	Lamp* l2 = new Lamp();
	l2->setColor("Green");
	cout << "Lamp l2's color is " << l2->getColor()<<endl;
	delete l2;

	//Error: Because there is no l2 in runtime at this moment.
	//l2->setColor("Blue");
	l2 = new Lamp("Gray", 500);
	cout << "Lamp l2's color is " << l2->getColor()<<endl;

	l1.setColor("Pink");

	Lamp l3("Red", 700);
	cout << "Lamp l3's color is " << l3.getColor() << endl;

	
	





	_getch();
	return 0;
}