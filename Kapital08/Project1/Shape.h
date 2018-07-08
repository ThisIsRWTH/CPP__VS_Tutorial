#include <string>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
	string color;
	string name;

protected:
	string bright;

public:
	Shape();
	string getColor();
	void setColor(string bright);
	string getBright();
	void setBright(string bright);
	string getName();
	void setName(string name);

};

#endif // !SHAPE_H
