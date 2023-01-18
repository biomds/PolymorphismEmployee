//
// Created by Administrator on 2023/1/18.
//
#include <iostream>
#include "HourlyWorker.h"
using namespace std;

HourlyWorker::HourlyWorker(const string &first, const string &last, const string &ssn, int mn, int dy, int yr,
                          double wage, double hour)
:Employee(first, last, ssn, mn, dy, yr), wage(wage), hours(hour)
{

}

double HourlyWorker::earnings() const
{
    if(hours <= 40)
    {
        return wage * hours;
    } else{
        return wage * hours + wage * (hours - 40) * 1.5;
    }
}

void HourlyWorker::print() const
{
    cout << "hourly worker: ";
    Employee::print();
    cout << "\nhourly worker salary: " << earnings();
}
