#include <iostream>
#include <conio.h>
#include <string>
#include<list>
using namespace std;

class Employee
{
private:
	string name;
	string family;
	string day;
public:
	Employee(string name, string family, string today);
	// However, we define a body for this pure virtual functions.
	// Hence, pure virtual functions:
	//     1) may have body (default body to used by other inherited print functions).
	//     2) may not have body (inherited classes have to define thorouly the inherited print function).
	virtual void print() const=0;
};

class Worker : public Employee
{
public:
	Worker(string, string, string);
	virtual void print() const;

};

class Manager : public Employee
{
public:
	Manager(string, string, string);
	void addWorker(Worker*);
	void setLevel(int);
	virtual void print() const;

private:
	list<Worker*> group;
	int level;

};
Worker::Worker(string name, string family, string day) : Employee(name, family, day)
{


	//Error:
	// name, family, and day are the private members of Employee class.
	// we have no access to them in the children classes (i.e. Worker class)
	/*this->name = name;
	this->family = family;
	this->day = day;*/
}

void Worker::print() const
{
	cout << "Worker: ";
	Employee::print();
}

Manager::Manager(string name, string family, string day) :Employee(name, family, day)
{

}

void Manager::print() const
{
	cout << "Manager: ";
	Employee::print();
}

void Manager::addWorker(Worker* workerToAdd)
{
	group.push_back(workerToAdd);
}

void Manager::setLevel(int level)
{
	this->level = level;
}

Employee::Employee(string name, string family, string day)
{
	this->name = name;
	this->family = family;
	this->day = day;

}

// This is an pure virtual function with body!
// Hence, we defined a body for this pure virtual function.
// (default body to use by other inherited print functions) = print functions in Worker and Manager classes.
void Employee::print() const
{
	cout << this->name << " " << family << " is hired on " << day << endl;

}

int main()
{
	Worker mahdi("Mahdi", "Saber", "1.1.1970");
	mahdi.print();

	Manager nika("Nika", "Khosravi", "2.1.1970");
	Employee *nikaPtr = &nika;
	nikaPtr->print();
	nika.print();

	Manager mina("Mina", "Dehghani", "3.1.1970");
	Employee* minaPtr = &mina;
	minaPtr->print();

	Employee* arrayOfMyEmployees[3];
	arrayOfMyEmployees[0] = &mahdi;
	arrayOfMyEmployees[1] = nikaPtr;
	arrayOfMyEmployees[2] = &mina;

	cout << "\n\n\nThis for traverse the array of Employees: \n";
	for (int i = 0; i < size(arrayOfMyEmployees); i++)
	{
		arrayOfMyEmployees[i]->print();
	}

	_getch();

	return 0;
}