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
	virtual void print() const=0;
};

class Worker : public Employee
{
public:
	Worker(string, string, string);

	//I delete this method to generate an incomplete inheritence tree
	//virtual void print() const;

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

//I delete this method to generate an incomplete inheritence tree
//void Worker::print() const
//{
//	cout << "This is a print function explicitely defined in Worker class." << endl;
//}

Manager::Manager(string name, string family, string day) :Employee(name, family, day)
{

}

void Manager::print() const
{
	cout << "This is a print function explicitely defined in Manager class." << endl;
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
void Employee::print() const
{
	cout << this->name << " " << family << " is hired on " << day << endl;
}

int main()
{
	Employee mahdi("Mahdi", "Saber", "1.1.1970");
	mahdi.print();

	Manager nika("Nika", "Khosravi", "2.1.1970");
	Employee *nikaPtr = &nika;
	nikaPtr->print();
	nika.print();

	Worker mina("Mina", "Dehghani", "3.1.1970");
	mina.print();
	//Employee* minaPtr = &mina;
	//minaPtr->print();

	Employee* arrayOfMyEmployees[3];
	arrayOfMyEmployees[0] = &mahdi;
	arrayOfMyEmployees[1] = nikaPtr;
	arrayOfMyEmployees[2] = &mina;

	cout << "\n\n\nThis for traverse the array of Employees: \n";
	for (int i = 0; i < size(arrayOfMyEmployees); i++)
	{
		//arrayOfMyEmployees[i]->print();

		(*arrayOfMyEmployees[i]).print();
	}

	_getch();

	return 0;
}