#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>


class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address);
	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getDateOfBirth() const;
	std::string getAddress() const;
	void print() const;
	bool operator<(const Student& s1);
	bool operator==(const Student& s2);
	bool operator>(const Student& s1);
	std::ostream& operator<<(std::ostream& output);
private:
	unsigned int matNr;
	std::string name;
	std::string dateOfBirth;
	std::string address;
};

#endif

