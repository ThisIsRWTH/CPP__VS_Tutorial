#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void print(int a);
void print(char a);

int main()
{
	Student s1;
	Student s2;

	s1.func01();
	s2.func01();

	_getch();
	return 0;
}

class Student
{
public:
	void func01();
	void func02(int a);

private:
	void func03(char c);
	string name;
	string family;
	int matNum;
};

void Student::func01()
{
	name = 10;
	this->name = 10;

	func01();
	this->func01();

}

void Student::func02(int a)
{

}

void Student::func03(char a)
{

}

