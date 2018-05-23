#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Lamp
{
private:
	int weight;
	string color;
	bool status;

public:
	int xyz;
	void setWeight(int);
	void turnOn();
	void turnOff();
	int getWeight();
	bool getStatus();
	void setColor(string theColor);
	string getColor();
	Lamp();
	Lamp(string theColor, int theWeight);
};

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

int main()
{
	Lamp l1;
	l1 = Lamp();
	Lamp l2 = Lamp();
	l1.setWeight(200);
	l2.setWeight(300);
	Lamp l3 = Lamp();
	l3.setColor("red");

	Lamp l4 = Lamp();
	l4.setWeight(400);

	Lamp l5 = Lamp("Purple", 500);
	l5.xyz = 800;


		

	cout <<" Lamp1: " <<l1.getWeight() <<" Lamp2: "<<l2.getWeight();
	cout << " Lamp3: " << l3.getColor();



	_getch();
	return 0;
}