#include <string>
#include "shape.h"
using namespace std;

Shape::Shape()
{
	this->color = "white";

}
string Shape::getColor()
{
	return color;
}

void Shape::setColor(string color)
{
	this->color = color;
}

string Shape::getBright()
{
	return bright;
}

void Shape::setBright(string bright)
{
	this->bright = bright;
}

string Shape::getName()
{
	return name;
}

