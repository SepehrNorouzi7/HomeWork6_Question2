#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <sstream>
using namespace std;

class Address
{
    string street;
    string city;
    string country;

public:
    Address(); //no-arg constructor
    Address(string, string, string); //3-arg constructor
    string getStreet();
    void setStreet(string);
    string getCity();
    void setCity(string);
    string getCountry();
    void setCountry(string);
    friend istream &operator>>(istream &, Address &);
    friend ostream &operator<<(ostream &, const Address &);
protected:
};

#endif