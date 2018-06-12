#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Student
{
public:
	Student(string name, string family, int matNum);
	int getMat() const;
	bool operator==(const Student& st);

private:
	string name;
	string family;
	int matNum;
};

Student::Student(string name, string family, int matNum)
{
	this->name = name;
	this->family = family;
	this->matNum = matNum;
}

int Student::getMat() const
{
	return this->matNum;
	//return matNum;
}

bool Student::operator==(const Student& st)
{
	if (this->getMat() == st.getMat())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Student s1 = Student("Nika", "Khosravi", 123456);
	Student s2 = Student("Mina", "Dehghani", 654321);

	if (s1 == s2)
	{
		cout << "These are equal";
	}
	else
	{
		cout << "These are not equal";
	}

	//Other Form:
	//Since this function is defined ""inside"" the class
	if (s1.operator==(s2))
	{
		cout << "These are equal";
	}
	else
	{
		cout << "These are not equal";
	}

	_getch();
	return 0;
}



