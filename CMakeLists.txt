cmake_minimum_required (VERSION 3.4)
project (Polymorphism CXX)
 
 
add_executable (Employee main.cpp Date.cpp Employee.cpp SalariedEmployee.cpp CommissionEmployee.cpp BasePlusCommissionEmployee.cpp)
 
target_link_libraries (Employee)
