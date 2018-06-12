#include <iostream>
#include <conio.h>
#include <string>
using namespace std;



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

std::ostream& operator<<(std::ostream& output, const Student& st);

std::ostream& operator<<(std::ostream& output, const Student& st)
{
	output << "Mat#: " << st.getMat() << " Name: " << st.getName() << " Family:" << st.getFamily() << endl;
	return output;
}

int main()
{
	Student s1 = Student("Nika", "Khosravi", 123456);
	Student s2 = Student("Mina", "Dehghani", 654321);

	cin >> s1;

	cout << s1;
	cout << s2;

	_getch();
	return 0;
}



