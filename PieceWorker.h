//
// Created by Administrator on 2023/1/18.
//

#ifndef CLION_PIECEWORKER_H
#define CLION_PIECEWORKER_H
#include <iostream>
#include "Employee.h"

class PieceWorker: public Employee {
public:
    PieceWorker(const std::string &, const std::string &,
                const std::string &, int=1, int=1, int=1900,double=0.0, int=0);
    virtual ~PieceWorker(){}
    virtual double earnings() const override ;
    virtual void print() const override;


private:
    double wage;
    int pieces;
};


#endif //CLION_PIECEWORKER_H
