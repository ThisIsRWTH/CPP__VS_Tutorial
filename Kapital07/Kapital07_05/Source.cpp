#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool operator==(const Student& st1, const Student& st2);

class Student
{
public:
	Student(string name, string family, int matNum);
	
	bool operator==(const Student& st);

	int getMat() const;
	string getName() const;
	string getFamily() const;


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

string Student::getName() const
{
	return this->name;
	//return matNum;
}

string Student::getFamily() const
{
	return this->family;
	//return matNum;
}


bool operator==(const Student& st1 , const Student& st2)
{
	if (st1.getMat() == st2.getMat())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& output, const Student& st)
{
	output << "Mat#: " << st.getMat() << " Name: " << st.getName() << " Family:" << st.getFamily() << endl;
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

	// Other Form
	//Since this function is defined ""outside"" the class
	if (operator==(s1,s2))
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



