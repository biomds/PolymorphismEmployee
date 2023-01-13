//
// Created by Administrator on 2022/12/22.
//
#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn,
        int mn, int dy, int yr, double sales, double rate)
        :Employee(first, last, ssn, mn, dy, yr)

{
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setGrossSales(double sales)
{
    if(sales >= 0.0)
    {
        grossSales = sales;
    } else{
        throw invalid_argument("Gross sales must be >= 0.0");
    }
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setCommissionRate( double rate )
{
    if ( rate > 0.0 && rate < 1.0 )
    {
        commissionRate = rate;
    }else
    {
        throw invalid_argument( "Commission rate must be > 0.0 and < 1.0" );
    }

} // end function setCommissionRate
// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

double CommissionEmployee::earnings() const {
    double earnings = getCommissionRate() * getGrossSales();
    return earnings;
}

void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print();
    cout << "\ngross sales: " << getGrossSales()
    <<"; commission rate: " << getCommissionRate();
}

