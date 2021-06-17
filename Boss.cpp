#include "Boss.h"

Boss::Boss() : Employee()
{
    this->numberOfEmployees=0;
}

Boss::Boss(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone, int numberOfEmployees) : Employee(name,id,address,hourWork,salaryPerHour,workToDo,workDone)
{
    this->numberOfEmployees=numberOfEmployees;
}

Boss::Boss(const Boss &constructor) : Employee(constructor)
{
    numberOfEmployees=constructor.numberOfEmployees;
}

int Boss::getNumberOfEmployees(){
    return numberOfEmployees;
}

void Boss::setNumberOfEmployees(int numberOfEmployees){
    this->numberOfEmployees=numberOfEmployees;
}

istream &operator>>(istream &strm, Boss &boss){
    /*moteqayyer haye morede nazar vared va dar address va bss zakhire mishavand
      dar akhar bss be boss assign mishavad
    */
    string name;
    string id;
    string country;
    string city;
    string street;
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
    strm>>name>>id>>country>>city>>street>>hourWork>>salaryPerHour>>workToDo>>workDone;
    strm>>boss.numberOfEmployees;
    Address address(street,city,country);
    Boss bss(name,id,address,hourWork,salaryPerHour,workToDo,workDone,boss.numberOfEmployees);
    boss=bss;
    return strm;
}

ostream &operator<<(ostream &strm, Boss &boss){
    strm<<"name: "<<boss.Person::getName()<<"\t"<<"id: "<<boss.Person::getId()<<endl;
    strm<<"country: "<<boss.Person::getAddress().getCountry()<<"\t"<<"city: "<<boss.Person::getAddress().getCity()<<"\t"<<"street: "<<boss.Person::getAddress().getStreet()<<endl;
    strm<<"hourWork: "<<boss.Employee::getHourWork()<<"\t"<<"salaryPerHour: "<<boss.Employee::getSalaryPerHour()<<"\t"<<"WorkToDo: "<<boss.Employee::getWorkToDo()<<"\t"<<"workDone: "<<boss.Employee::getWorkDone()<<endl;
    strm<<"numberOfEmployees: "<<boss.numberOfEmployees;
    return strm;
}

Boss &Boss::operator=(Boss &boss){
    numberOfEmployees=boss.numberOfEmployees;
    return *this;
}

double Boss::calculateSalary(){
    double salary=1.15*(getHourWork()*getSalaryPerHour())*(((double)getWorkDone())/((double)getWorkToDo()));
    return salary;
}