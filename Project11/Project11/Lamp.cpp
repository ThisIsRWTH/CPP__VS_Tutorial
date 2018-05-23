#include "Lamp.h"
void Lamp::setWeight(int weight)
{
	this->weight = weight;
}
string Lamp::getColor()
{
	return color;
}
void Lamp::setColor(string theColor)
{
	color = theColor;

}

void Lamp::turnOn()
{
	status = true;
}

void Lamp::turnOff()
{
	status = false;
}

int Lamp::getWeight()
{
	return weight;
}

bool Lamp::getStatus()
{
	return status;
}

Lamp::Lamp()
{
	color = "White";
	weight = 100;
}
Lamp::Lamp(string theColor, int theWeight)
{
	color = theColor;
	weight = theWeight;
}