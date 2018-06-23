#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
	matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

unsigned int Student::getMatNr() const
{
	return this->matNr;
}

std::string Student::getName() const
{
	return this->name;
}

std::string Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}

std::string Student::getAddress() const
{
	return this->address;
}

void Student::print() const
{
	std::cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
		<< this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
		<< std::endl;
}

bool Student::operator<(const Student& s1)
{
	if (this->getMatNr() < s1.getMatNr())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Student::operator>(const Student& s1)
{
	if (this->getMatNr() > s1.getMatNr())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



bool Student::operator==(const Student& s2)
{
	if (this->getMatNr() == s2.getMatNr())
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
std::ostream&  Student::operator<<(std::ostream& output)
{
	output << "Mat: " << this->getMatNr() << " "
		<< "Name: " << this->getName() << " "
		<< "Birth: " << this->getDateOfBirth() << " "
		<< "Address: " << this->getAddress() << std::endl;
	return output;
}
