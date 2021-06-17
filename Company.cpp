#include "Company.h"
#include <fstream>

Company::Company(int budget, Boss boss, Employee **employee)
{
    //faza giri haye employee ba tavajoh be te'dade karmandane boss anjam mishavad
    this->budget=budget;
    this->boss=new Boss(boss);
    this->employee=new Employee *[boss.getNumberOfEmployees()];
    for(int i=0; i<boss.getNumberOfEmployees(); i++){
        this->employee[i]=new Employee(*employee[i]);
    }
}

Company::Company(const Company &constructor) : Boss(constructor)
{
    this->budget=constructor.budget;
    *this->boss=*constructor.boss;
    for(int i=0; i<Boss::getNumberOfEmployees(); i++){
        *this->employee[i]=*constructor.employee[i];
    }
}

Company::~Company(){
    budget=0;
    delete boss;
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        delete [] employee[i];
    }
    delete [] employee;
}

int Company::getBudget(){
    return budget;
}

void Company::setBudget(int budget){
    this->budget=budget;
}

Employee Company::maxEfficiency(){
    /*avval employee[0] be pointeri be Employee ke karmandi ba bishtarin bazdehi ast assign mishavad
      ba check kardan bazdehi ha karmande ba bishtarin bazdehi moshakhas mishavad
    */
    Employee *maxEfficiencyEmployee=employee[0];
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        if(((double)employee[i]->getWorkDone())/((double)(employee[i]->getWorkToDo()))>(((double)maxEfficiencyEmployee->getWorkDone())/(double)(maxEfficiencyEmployee->getWorkToDo()))){
            maxEfficiencyEmployee=employee[i];
        }
    }
    return *maxEfficiencyEmployee;
}

double Company::averageEfficiency(){
    double averageEfficiency=0;
    double total=0;
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        total+=((double)employee[i]->getWorkDone())/((double)(employee[i]->getWorkToDo()));
    }
    averageEfficiency=100*total/boss->getNumberOfEmployees();
    return averageEfficiency;
}

void Company::changeBoss(Boss &boss){
    /*dar surate bazdehi kamtar az 40 darsade boss karmande ba bishtarin bazdehi moshakhas mishavad
      etela'ate boss be karmande ba bishtarin bazdehi montaqel mishavad
      dar akhar etela'ate karmande ba bishtarin bazdehi be boss montaqel mishavad
    */
    Employee *maxEfficiencyEmployee=employee[0];
    for(int i=0; i<boss.getNumberOfEmployees(); i++){
        if(((double)employee[i]->getWorkDone())/((double)(employee[i]->getWorkToDo()))>(((double)maxEfficiencyEmployee->getWorkDone())/(double)(maxEfficiencyEmployee->getWorkToDo()))){
            maxEfficiencyEmployee=employee[i];
        }
    }
    if(boss.efficiency()<40){
        Employee temp=maxEfficiency();
        Employee *employeeTemp=&temp;
        maxEfficiencyEmployee->Person::setName(boss.Person::getName());
        maxEfficiencyEmployee->Person::setId(boss.Person::getId());
        maxEfficiencyEmployee->Person::setAddress(boss.Person::getAddress());
        maxEfficiencyEmployee->Employee::setHourWork(boss.Employee::getHourWork());
        maxEfficiencyEmployee->Employee::setSalaryPerHour(boss.Employee::getSalaryPerHour());
        maxEfficiencyEmployee->Employee::setWorkToDo(boss.Employee::getWorkToDo());
        maxEfficiencyEmployee->Employee::setWorkDone(boss.Employee::getWorkDone());
        int numberOfEmployees=boss.getNumberOfEmployees();
        boss.Person::setName(employeeTemp->Person::getName());
        boss.Person::setId(employeeTemp->Person::getId());
        boss.Person::setAddress(employeeTemp->Person::getAddress());
        boss.Employee::setHourWork(employeeTemp->Employee::getHourWork());
        boss.Employee::setSalaryPerHour(employeeTemp->Employee::getSalaryPerHour());
        boss.Employee::setWorkToDo(employeeTemp->Employee::getWorkToDo());
        boss.Employee::setWorkDone(employeeTemp->Employee::getWorkDone());
        boss.setNumberOfEmployees(numberOfEmployees);
    }
}

void Company::gift(){
    //be afrade pishkesvate qable sale 90 5 sa'at ezafe mishavad
    for(int i=0; i<Boss::getNumberOfEmployees(); i++){
        int dahgan, yekan, salevorud;
        dahgan=(int)employee[i]->Person::getId()[0]-48;
        yekan=(int)employee[i]->Person::getId()[1]-48;
        salevorud=10*dahgan+yekan;
        if(salevorud<90){
            employee[i]->setHourWork(employee[i]->getHourWork()+5);
        }
    }
    //be karmande ba bishtarin bazdehi 10 sa'at ezafe mishavad
    maxEfficiency().Employee::setHourWork(maxEfficiency().Employee::getHourWork()+10);
}

void Company::payForService(){
    //be afrade sakene khareje tehran 7 sa'at ezafe mishavad
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        if(employee[i]->Person::getAddress().Address::getCity()!="tehran"){
            if(employee[i]->Person::getAddress().Address::getCity()!="Tehran"){
                employee[i]->setHourWork(employee[i]->getHourWork()+7);
            }
        }
    }
}

bool Company::isEnoughBudget(){
    double total=0;
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        total+=employee[i]->calculateSalary();
    }
    total+=boss->Boss::calculateSalary();
    if((double)budget>=total){
        return true;
    }
    else{
        return false;
    }
}

void Company::writeInFile(){
    payForService();
    gift();
    ofstream dataFile("data.dat", ios::out);
    if (!dataFile){
        cerr<<"Something wrong during opening file!"<<endl;
        exit(1);
    }
    for(int i=0; i<boss->getNumberOfEmployees(); i++){
        dataFile<<employee[i]->Person::getName()<<endl;
        dataFile<<employee[i]->Person::getId()<<endl;
        dataFile<<employee[i]->Employee::efficiency()<<endl;
        dataFile<<employee[i]->Employee::calculateSalary()<<endl;
    }
    dataFile<<boss->Person::getName()<<endl;
    dataFile<<boss->Person::getId()<<endl;
    dataFile<<boss->Employee::efficiency()<<endl;
    dataFile<<boss->Boss::calculateSalary()<<endl;
}

int strcmp(string str1, string str2, int i) {
    if((int)str1[i]==(int)str2[i] && str1[i]!=NULL && str2[i]!=NULL){
        return strcmp(str1,str2,i+1);
    }
    if(str1[i+1]==NULL && str2[i+1]==NULL){
        return 0;
    }
    if((int)str1[i]>(int)str2[i]){
        return 1;
    }
    if((int)str1[i]<(int)str2[i]){
        return -1;
    }
}


istream &operator>>(istream &strm, Company &company){
    for(int i=0; i<company.boss->getNumberOfEmployees(); i++){
        cin>>*company.employee[i];
    }
    return strm;
}

ostream &operator<<(ostream &strm, Company &company){
    Employee *emply[1000];
    Employee *temp;
    int intTemp;
    int salevorud[1000];
    for(int i=0; i<company.boss->getNumberOfEmployees(); i++){
        emply[i]=company.employee[i];
        int yekan, dahgan;
        yekan=(int)(company.employee[i]->getId()[1])-48;
        dahgan=(int)(company.employee[i]->getId()[0])-48;
        salevorud[i]=10*dahgan+yekan;
    }
    //ba moratab sazi tartibe chap kardan moshakhas mishavad
    for(int i=0; i<company.boss->getNumberOfEmployees()-1; i++){
        for(int j=i+1; j<company.boss->getNumberOfEmployees(); j++){
            if(salevorud[i]>salevorud[j]){
                temp=emply[j];
                emply[j]=emply[i];
                emply[i]=temp;
                intTemp=salevorud[j];
                salevorud[j]=salevorud[i];
                salevorud[i]=intTemp;
            }
            if(salevorud[i]>salevorud[j]){
                if(strcmp(emply[i]->getName(),emply[j]->getName(),0)>0){
                    temp=emply[j];
                    emply[j]=emply[i];
                    emply[i]=temp;
                }
            }
        }
    }
    for(int i=0; i<company.boss->getNumberOfEmployees(); i++){
        cout<<"employee "<<i<<" -> "<<*emply[i]<<endl;
    }
    cout<<"boss -> "<<*company.boss;
    return strm;
}
