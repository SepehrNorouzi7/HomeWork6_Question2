#ifndef COMPANY_H
#define COMPANY_H

#include "Boss.h"

class Company : public Boss
{
    int budget;
    Boss *boss;
    Employee **employee;

public:
    Company(int, Boss, Employee **); //3-arg constructor
    Company(const Company &); //copy constructor
    ~Company(); //destructor
    int getBudget();
    void setBudget(int);
    Employee maxEfficiency();
    double averageEfficiency();
    void changeBoss(Boss &);
    void gift();
    void payForService();
    bool isEnoughBudget();
    void writeInFile();
    friend istream &operator>>(istream &, Company &);
    friend ostream &operator<<(ostream &, Company &);
    friend int strcmp(string, string, int); //comparing two strings function
};

#endif
