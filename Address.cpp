#include "Address.h"

Address::Address(){
    this->street="";
    this->city="";
    this->country="";
}

Address::Address(string street, string city, string country){
    this->street=street;
    this->city=city;
    this->country=country;
}

string Address::getStreet(){
    return street;
}

void Address::setStreet(string street){
    this->street=street;
}

string Address::getCity(){
    return city;
}

void Address::setCity(string city){
    this->city=city;
}

string Address::getCountry(){
    return country;
}

void Address::setCountry(string country){
    this->country=country;
}

istream &operator>>(istream &strm, Address &address){
    strm>>address.country>>address.city>>address.street;
    return strm;
}

ostream &operator<<(ostream &strm, const Address &address){
    strm<<"country: "<<address.country<<"\t"<<"city: "<<address.city<<"\t"<<"street: "<<address.street;
    return strm;
}