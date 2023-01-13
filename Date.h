//
// Created by Administrator on 2022/12/27.
//

#ifndef CLION_DATE_H
#define CLION_DATE_H
#include <array>
#include <iostream>

class Date {
    friend std::ostream &operator <<(std::ostream &, const Date &);

public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int); // set month, day, year
    int getMonth() const;
    Date &operator++(); //prefix increment operator
    Date operator++(int); //postfix increment operator
    Date &operator+=(unsigned int); // add days, modify object
    static bool leapYear(int); // is date in a leap year
    bool endOfMonth(int) const; // is date at the end of month
    void print() const;

private:
     int month;
     int day;
     int year;
    static const std::array<unsigned int, 13> days; //days per month
    void helpIncrement(); // utility function for increment date
};

#endif //CLION_DATE_H
