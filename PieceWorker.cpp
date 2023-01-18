//
// Created by Administrator on 2023/1/18.
//
#include <iostream>
#include "PieceWorker.h"

using namespace std;

PieceWorker::PieceWorker(const string &first, const string &last, const string &ssn, int mn, int dy, int yr,
        double wg, int pc)
:Employee(first, last, ssn, mn, dy, yr), wage(wg), pieces(pc)
{

}

double PieceWorker::earnings() const
{
    return wage * pieces;
}

void PieceWorker::print() const
{
    cout << "pieceworker: ";
    Employee::print();
    cout << "\npiecework salary: " << earnings();
}