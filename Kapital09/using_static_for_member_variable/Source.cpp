#include <iostream>
#include <conio.h>
using namespace std;

class Lamp
{
private:
	int b;
	static int a;
public:
	
	Lamp();

	static int ReadA();

	void setA(int a);
	int getA();

	void setB(int b);
	int getB();

};

Lamp::Lamp()
{
	//Since it is static, it would be better to initialize outside the constructor.
	//a = 100;
	b = 0;
}

void Lamp::setA(int a)
{
	this->a = a;
}

void Lamp::setB(int b)
{
	this->b = b;
}

int Lamp::getA()
{
	a++;
	return a;
}

int Lamp::getB()
{
	b++;
	return b;
}


int Lamp::a = 100;

int Lamp::ReadA()
{
	a++;

	return a;

}

int main()
{

	cout << Lamp::ReadA();


	Lamp l1;

	Lamp l2;

	cout << l1.getA() << endl;
	cout << l1.getA() << endl;
	cout << l1.getA() << endl;
	//cout <<Lamp::ReadA() << endl;

	cout << l1.getB() << endl;
	cout << l1.getB() << endl;
	
	cout << endl;

	cout << l2.getA() << endl;
	//cout <<Lamp::ReadA() << endl;
	cout << l2.getB() << endl;

	

	_getch();
	return 0;
}
