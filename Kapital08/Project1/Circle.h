#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
private:
	string name;
public:
	void specificFunctionOnlyDefinedInCircle();
	string getName();
	void setName(string name);
	
};

#endif