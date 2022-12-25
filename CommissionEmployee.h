//
// Created by Administrator on 2022/12/22.
//

#ifndef CLION_COMMISSIONEMPLOYEE_H
#define CLION_COMMISSIONEMPLOYEE_H
#include <string>
#include "Employee.h"

class CommissionEmployee: public Employee {
public:
    CommissionEmployee(const std::string &, const std::string &,
            const std::string &, double=0.0, double=0.0);
    virtual ~CommissionEmployee(){};
    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double);
    double getGrossSales() const;
    virtual double earnings() const override ;
    virtual void print() const override ;

private:
    double grossSales;
    double commissionRate;

};


#endif //CLION_COMMISSIONEMPLOYEE_H
