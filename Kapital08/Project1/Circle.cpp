#include "Shape.h"
#include "Circle.h"
#include <string>
using namespace std;

void Circle::specificFunctionOnlyDefinedInCircle()
{
	//Error: Shape's private element does exist in the shape element of circle
	//       It does NOT inherited as a private element.
	//this->color = "Black";


	// These two are pointed to the same thing in memory
	this->bright = "bright circle";
	Shape::bright = "bright in Shape Element";


}

string Circle::getName()
{
	return name;
}

void Circle::setName(string name)
{
	this->name = name;
}