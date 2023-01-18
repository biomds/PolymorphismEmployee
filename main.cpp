//
// Created by Administrator on 2022/12/25.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <typeinfo>
#include "Date.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"

using namespace std;

void virtualViaPointer(const Employee *const, int); // prototype
void virtualViaReference(const Employee &, int); //prototype
void RTTIDynamicCasting(); //prototype
int determineMonth(); //prototype
int main() {
    int month = determineMonth(); // current month
    cout << fixed << setprecision(2); // set floating-point output formatting
//    Date birth1(12, 8,1995);
    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 12, 8, 1995, 800);
//    Date birth2(11, 9,1996);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 11, 9, 1996, 10000, .06);
//    Date birth3(1, 2,1998);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444",
                                                           1, 2, 1998, 5000, .04, 300);
    PieceWorker pieceWorker("Jack", "Ma", "888-88-8888", 1, 2, 1968, 10, 5);
    HourlyWorker hourlyWorker("Denny", "Liu", "666-66-6666", 12, 15, 2000, 12, 45);
    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    pieceWorker.print();
    cout << "\nearned $" << pieceWorker.earnings() << "\n\n";
    hourlyWorker.print();
    cout << "\nearned $" << hourlyWorker.earnings() << "\n\n";


    // create vector of three base-class pointers

//    vector<Employee *> employees(3);
    vector<Employee *> employees(5);
    // initialize vector with pointers to Employees

    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;
    employees[3] = &pieceWorker;
    employees[4] = &hourlyWorker;

    cout << "\nEmployees processed polymorphically via dynamic binding:\n\n";
    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding

    cout << "Virtual function calls made off base-class pointers:\n\n";
    for (const Employee *employeePtr:employees) {
        virtualViaPointer(employeePtr, month);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class references:\n\n";

    for (const Employee *employeePtr:employees) {
        virtualViaReference(*employeePtr, month);
    }

    // runtime type information (RTTI) and dynamic casting
    RTTIDynamicCasting();
    return 0;
}


void virtualViaPointer(const Employee *const baseClassPtr, int month) {
    baseClassPtr->print();
    cout << "\nwhose birthday is " << baseClassPtr->getBirthDate();
    double earnings = baseClassPtr->earnings();
    cout << "\nearned $";
    if(baseClassPtr->getBirthDate().getMonth() == month)
    {
        earnings += 100.0;
        cout << earnings << " HAPPY BIRTHDAY!\n\n";
    }else{
        cout << earnings << "\n\n";
    }

}

void virtualViaReference(const Employee &baseClassPtr, int month) {
    baseClassPtr.print();
    cout << "\nwhose birthday is " << baseClassPtr.getBirthDate();
    double earnings = baseClassPtr.earnings();
    cout << "\nearned $";
    if(baseClassPtr.getBirthDate().getMonth() == month)
    {
        earnings += 100.0;
        cout << earnings << " HAPPY BIRTHDAY!\n\n";
    } else{
        cout << earnings << "\n\n";
    }

}

void RTTIDynamicCasting() {
    cout << fixed << setprecision(2);
//    vector<Employee *> employees(3);
    vector<Employee *> employees(5);
    employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 12, 8, 1995, 800);
    employees[1] = new CommissionEmployee("Sue", "Jones", "333-33-3333",  11, 9, 1996, 10000, .06);
    employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 1, 2, 1998, 5000, .04, 300);
    employees[3] = new PieceWorker("Jack", "Ma", "888-88-8888", 1, 2, 1968, 10, 5);
    employees[4] = new HourlyWorker("Denny", "Liu", "666-66-6666", 12, 15, 2000, 12, 45);

    // polymorphically process each element in vector employees
    for (Employee *employeePtr:employees) {
        employeePtr->print(); // output employee information
        cout << endl;

        // attempt to downcast pointer
        BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>(employeePtr);
        if (derivedPtr != nullptr) {
            double oldBaseSalary = derivedPtr->getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
            cout << "new base salary with 10% increase is: $"
                 << derivedPtr->getBaseSalary() << endl;
        }
        cout << "earned $" << employeePtr->earnings() << endl;
    }
    // release objects pointed to by vector’s elements
    for (const Employee *employeePtr:employees) {
        cout << "deleting object of "
             << typeid(*employeePtr).name() << endl;
        delete employeePtr;
    }
}

int determineMonth() {
    time_t currentTime;
    char monthString[3];
    time(&currentTime);
    strftime(monthString, 3, "%m", localtime(&currentTime));
    return atoi(monthString);

}

