//
// Created by Administrator on 2022/12/25.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;
void virtualViaPointer(const Employee*const); // prototype
void virtualViaReference(const Employee &); //prototype
void RTTIDynamicCasting(); //prototype
int determineMonth(); //prototype
int main()
{
    cout << fixed << setprecision(2); // set floating-point output formatting
    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);
    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";


    // create vector of three base-class pointers

    vector<Employee *> employees(3);
    // initialize vector with pointers to Employees

    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    cout << "Employees processed polymorphically via dynamic binding:\n\n";
    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding

    cout << "Virtual function calls made off base-class pointers:\n\n";
    for(const Employee *employeePtr:employees)
    {
        virtualViaPointer(employeePtr);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class references:\n\n";

    for(const Employee *employeePtr:employees)
    {
        virtualViaReference(*employeePtr);
    }

    // runtime type information (RTTI) and dynamic casting
    RTTIDynamicCasting();
    return 0;
}

void virtualViaPointer(const Employee* const baseClassPtr)
{
    baseClassPtr->print();
    cout <<"\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee &baseClassPtr)
{
    baseClassPtr.print();
    cout <<"\nearned $" << baseClassPtr.earnings() << "\n\n";
}

void RTTIDynamicCasting()
{
    cout << fixed << setprecision(2);
    vector<Employee *>  employees(3);
    employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 800);
    employees[1] = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

    // polymorphically process each element in vector employees
    for(Employee *employeePtr:employees)
    {
        employeePtr->print(); // output employee information
        cout << endl;

        // attempt to downcast pointer
        BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>(employeePtr);
        if(derivedPtr != nullptr)
        {
            double oldBaseSalary = derivedPtr->getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
            cout << "new base salary with 10% increase is: $"
            << derivedPtr->getBaseSalary() << endl;
        }
        cout << "earned $" << employeePtr->earnings() << endl;
    }
    // release objects pointed to by vector’s elements
    for(const Employee *employeePtr:employees)
    {
        cout << "deleting object of "
            << typeid(*employeePtr).name() << endl;
        delete employeePtr;
    }
}

int determineMonth()
{
    time_t currentTime;
    char monthString[3];
    time(&currentTime);
    strftime(monthString, 3, "%m", localtime(&currentTime));
    return atoi(monthString);

}

