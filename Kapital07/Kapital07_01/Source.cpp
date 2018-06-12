#include <iostream>
#include <conio.h>
#include <string>
using namespace std;




int main()
{
	

	cout << "This is project07_01";
	_getch();
	return 0;
}



class Lamp
{
private:
	int weight;
	string color;
public:
	void Lamp::printTest(int a) const;
	
};

void Lamp::printTest(int a) const
{
	int temp;
	temp = a;
	
	//Error: We can not change the memebers/attributes of the class in a const function.
	//color = "red";

	cout << "This is the passed parameter"<< temp;

	cout << "This is a test function for const!";
}

