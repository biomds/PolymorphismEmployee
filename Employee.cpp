//
// Created by Administrator on 2022/12/22.
//
#include <iostream>
#include <ctime>
#include "Employee.h"
using namespace std;

Employee::Employee(const string &first, const string &last, const string &ssn, int mn, int dy, int yr)
:firstName(first), lastName(last), socialSecurityNumber(ssn), birthDate(mn, dy, yr)
{
}
void Employee::setFirstName(const std::string &first)
{
    firstName = first;
}

string Employee::getFirstName() const
{
    return firstName;
}

void Employee::setLastName(const std::string &last)
{
    lastName = last;
}

string Employee::getLastName() const
{
    return lastName;
}

void Employee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName()
    << "\nsocial security number: " << getSocialSecurityNumber();
}

Date Employee::getBirthDate() const
{
    return birthDate;
}

