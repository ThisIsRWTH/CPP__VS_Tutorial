#include<string>
using std::string;

class Lamp
{
private:
	int weight;
	string color;
	bool status;

public:

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
