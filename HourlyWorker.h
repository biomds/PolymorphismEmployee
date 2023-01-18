//
// Created by Administrator on 2023/1/18.
//

#ifndef CLION_HOURLYWORKER_H
#define CLION_HOURLYWORKER_H

#include <iostream>
#include "Employee.h"

class HourlyWorker: public Employee {
public:
    HourlyWorker(const std::string &, const std::string &,
                const std::string &, int=1, int=1, int=1900,
                double=0.0, double=0);
    virtual ~HourlyWorker(){}
    virtual double earnings() const override ;
    virtual void print() const override;

private:
    double wage;
    double hours;
};


#endif //CLION_HOURLYWORKER_H
