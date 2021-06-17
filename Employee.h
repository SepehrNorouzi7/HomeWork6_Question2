#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;

public:
    Employee(); //no-arg constructor
    Employee(string, string, Address, int, int, int, int); //7-arg constructor
    Employee(const Employee &); //copy constructor
    friend istream &operator>>(istream &, Employee &);
    friend ostream &operator<<(ostream &, Employee &);
    Employee &operator=(Employee &);
    int getHourWork();
    void setHourWork(int);
    int getSalaryPerHour();
    void setSalaryPerHour(int);
    int getWorkToDo();
    void setWorkToDo(int);
    int getWorkDone();
    void setWorkDone(int);
    bool validate(string);
    virtual double calculateSalary();
    double efficiency();
};

#endif