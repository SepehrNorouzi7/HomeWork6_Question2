//Sepehr Norouzi
//Student Number = 992023035

#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "Boss.h"
#include "Company.h"
using namespace std;

int main(){
    Address address("Zarand","Tehran","Iran");
    Employee employee1=Employee("Soheil","93*12393",address,7,8,5,4);
    Employee employee2=Employee("Hossein","94*12382",address,7,8,5,4);
    Employee employee3=Employee("Mohammad","95*12383",address,7,8,5,5);
    Employee employee4=Employee("Sina","96*12389",address,7,8,5,4);
    Employee employee5=Employee("Amir","97*12397",address,7,8,5,4);
    Employee employee6=Employee("Alireza","98*12398",address,7,8,5,3);
    Employee employee7=Employee("Saman","99*12399",address,7,8,5,4);
    Employee employee8=Employee("Amin","89*12388",address,7,8,5,2);
    Employee employee9=Employee("Arash","91*12383",address,7,8,5,3);
    Employee employee10=Employee("Mahdi","91*12381",address,7,8,5,1);
    Boss boss("Ali","90*12389",address,8,10,5,1,10);
    Employee *ptr[10];
    ptr[0]=&employee1;
    ptr[1]=&employee2;
    ptr[2]=&employee3;
    ptr[3]=&employee4;
    ptr[4]=&employee5;
    ptr[5]=&employee6;
    ptr[6]=&employee7;
    ptr[7]=&employee8;
    ptr[8]=&employee9;
    ptr[9]=&employee10;
    Employee **ptrToPtr=&ptr[0];
    cout<<"salary of employee1 is "<<employee1.calculateSalary()<<endl;
    cout<<"efficiency of employee1 is "<<employee1.efficiency()<<"%"<<endl;
    cout<<"salary of boss is "<<boss.calculateSalary()<<endl;
    cout<<"efficiency of boss is "<<boss.efficiency()<<"%"<<endl;
    Company company(1000,boss,ptrToPtr);
    cout<<"information of employee1: "<<endl<<employee1<<endl;
    cout<<"information of company: "<<endl<<company<<endl;
    if(company.isEnoughBudget()==true){
        cout<<"budget of company is enough"<<endl;
    }
    if(company.isEnoughBudget()==false){
        cout<<"budget of company is not enough"<<endl;
    }
    cout<<"average of efficiency of company is "<<company.averageEfficiency()<<"%"<<endl;
    cout<<company.maxEfficiency().getName()<<" has max efficiency"<<endl;
    company.changeBoss(boss);
    cout<<"new boss is "<<boss.getName()<<endl;
    company.gift();
    company.payForService();
    company.writeInFile();
    return 0;
}