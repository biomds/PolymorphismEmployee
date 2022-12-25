//
// Created by Administrator on 2022/12/25.
//

#ifndef CLION_BASEPLUSCOMMISSIONEMPLOYEE_H
#define CLION_BASEPLUSCOMMISSIONEMPLOYEE_H
#include <string>
#include "CommissionEmployee.h"
class BasePlusCommissionEmployee: public CommissionEmployee {
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
            const std::string &, double = 0.0, double = 0.0, double = 0.0);
    virtual ~BasePlusCommissionEmployee(){};
    void setBaseSalary(double);
    double getBaseSalary() const;
    virtual double earnings() const override ;
    virtual void print() const  override ;
private:
    double baseSalary;
};


#endif //CLION_BASEPLUSCOMMISSIONEMPLOYEE_H
