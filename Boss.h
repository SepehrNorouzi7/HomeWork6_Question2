#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee
{
    int numberOfEmployees;

public:
    Boss(); //no-arg constructor
    Boss(string, string, Address, int, int, int, int, int); //5-arg constructor
    Boss(const Boss &); //copy constructor
    int getNumberOfEmployees();
    void setNumberOfEmployees(int);
    friend istream &operator>>(istream &, Boss &);
    friend ostream &operator<<(ostream &, Boss &);
    Boss &operator=(Boss &);
    double calculateSalary();
protected:
};

#endif