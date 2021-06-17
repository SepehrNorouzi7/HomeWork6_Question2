#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Person
{
    string name;
    string id;
    Address address;

public:
    Person(); //no-arg constructor
    Person(string, string, Address); //3-arg constructor
    Person(const Person &); //copy constructor
    string getName();
    void setName(string);
    string getId();
    void setId(string);
    Address getAddress();
    void setAddress(Address);
    friend istream &operator>>(istream, Person &);
    friend ostream &operator<<(ostream, Person &);
    Person &operator=(Person &);
    virtual bool validate(string);
};

#endif