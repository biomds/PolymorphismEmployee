//
// Created by Administrator on 2022/12/25.
//
#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last,
        const string &ssn, int mn, int dy, int yr, double sales, double rate, double salary)
        :CommissionEmployee(first, last, ssn, mn, dy, yr, sales, rate)
{
    setBaseSalary(salary);
};
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if(salary >=0.0)
    {
        baseSalary = salary;
    } else{
        throw invalid_argument("Salary must be >= 0.0");
    }
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    double earnings = getBaseSalary() + CommissionEmployee::earnings();
    return earnings;
}

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "; base salary: " << getBaseSalary();
}




