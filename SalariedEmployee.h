//
// Created by Administrator on 2022/12/22.
//

#ifndef CLION_SALARIEDEMPLOYEE_H
#define CLION_SALARIEDEMPLOYEE_H
#include <string>
#include "Employee.h"

class SalariedEmployee: public Employee {
public:
    SalariedEmployee(const std::string &, const std::string &,
            const std::string &, double=0.0);
    virtual ~SalariedEmployee(){};
    void setWeeklySalary(double);
    double getWeeklySalary() const;
    virtual double earnings() const override ;
    virtual void print() const override ;

private:
    double weeklySalary;
};


#endif //CLION_SALARIEDEMPLOYEE_H
