//
// Created by Administrator on 2022/12/22.
//

#ifndef CLION_EMPLOYEE_H
#define CLION_EMPLOYEE_H
#include <string>

class Employee {
public:
    Employee(const std::string &, const std::string &,
    const std::string &);
    virtual ~Employee(){};
    void setFirstName(const std::string &);
    std::string getFirstName()const;
    void setLastName(const std::string &);
    std::string getLastName()const;
    void setSocialSecurityNumber(const std::string &);
    std::string getSocialSecurityNumber() const;

    //pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0;
    virtual void print() const;

private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
};


#endif //CLION_EMPLOYEE_H
