#include "Employee.h"

Employee::Employee() : Person()
{
    this->hourWork=0;
    this->salaryPerHour=0;
    this->workToDo=0;
    this->workDone=0;
}

Employee::Employee(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone) : Person(name,id,address)
{
    //agar id fard mo'tabar nabashad payam invakid id chap va barname khareg mishavad
    if(validate(id)==false){
        cout<<"invalid id"<<endl;
        exit(1);
    }
    else{
        this->hourWork=hourWork;
        this->salaryPerHour=salaryPerHour;
        this->workToDo=workToDo;
        this->workDone=workDone;
    }
}

Employee::Employee(const Employee &constructor) : Person(constructor)
{
    this->hourWork=constructor.hourWork;
    this->salaryPerHour=constructor.salaryPerHour;
    this->workToDo=constructor.workToDo;
    this->workDone=constructor.workDone;
}

istream &operator>>(istream &strm, Employee &employee){
    /*moteqayyer haye morede nazar vared va dar address va emply zakhire mishavand
      dar akhar mply be employee assign mishavad
    */
    strm>>employee.hourWork>>employee.salaryPerHour>>employee.workToDo>>employee.workDone;
    string name;
    string id;
    string country;
    string city;
    string street;
    strm>>name>>id>>country>>city>>street;
    Address address(street,city,country);
    Employee mply(name,id,address,employee.hourWork,employee.salaryPerHour,employee.workToDo,employee.workDone);
    employee=mply;
    return strm;
}

ostream &operator<<(ostream &strm, Employee &employee){
    strm<<"name: "<<employee.Person::getName()<<"\t"<<"id: "<<employee.Person::getId()<<endl;
    strm<<"country: "<<employee.Person::getAddress().getCountry()<<"\t"<<"city: "<<employee.Person::getAddress().getCity()<<"\t"<<"street: "<<employee.Person::getAddress().getStreet()<<endl;
    strm<<"hourWork: "<<employee.hourWork<<"\t"<<"salaryPerHour: "<<employee.salaryPerHour<<"\t"<<"WorkToDo: "<<employee.workToDo<<"\t"<<"workDone: "<<employee.workDone;
    return strm;
}

Employee &Employee::operator=(Employee &employee){
    hourWork=employee.hourWork;
    salaryPerHour=employee.salaryPerHour;
    workToDo=employee.workToDo;
    workDone=employee.workDone;
    return *this;
}

int Employee::getHourWork(){
    return hourWork;
}

void Employee::setHourWork(int hourWork){
    this->hourWork=hourWork;
}

int Employee::getSalaryPerHour(){
    return salaryPerHour;
}

void Employee::setSalaryPerHour(int salaryPerHour){
    this->salaryPerHour=salaryPerHour;
}

int Employee::getWorkToDo(){
    return workToDo;
}

void Employee::setWorkToDo(int workToDo){
    this->workToDo=workToDo;
}

int Employee::getWorkDone(){
    return workDone;
}

void Employee::setWorkDone(int workDone){
    this->workDone=workDone;
}

bool Employee::validate(string id){
    /*sale vorude karmand az id gerefte mishavad
      halat haye na mo'tabar check mishavand
      agar id mo'tabar bud check=true mishavad
    */
    int dahgan, yekan, salevorud;
    bool check=false;
    dahgan=(int)id[0]-48;
    yekan=(int)id[1]-48;
    salevorud=10*dahgan+yekan;
    if(id.length()==8){
        if(salevorud>=84 && salevorud<=99){
            if((int)id[2]==42){
                int checkFiveNumber=0;
                for(int i=3; i<8; i++){
                    if(((int)id[i]>=48 && (int)id[i]<=51) | ((int)id[i]>=55 && (int)id[i]<=57)){
                        checkFiveNumber++;
                    }
                }
                //dar surati ke checkFiveNumber==5 shavad yani inke har 5 character akhare id mo'tabarand
                if(checkFiveNumber==5){
                    check=true;
                }
            }
        }
    }
    if(id.length()==9){
        if(salevorud>=84 && salevorud<=99){
            if((int)id[2]==42 && ((int)id[3]<48 | (int)id[3]>57)){
                int checkFiveNumber=0;
                for(int i=4; i<9; i++){
                    if(((int)id[i]>=48 && (int)id[i]<=51) | ((int)id[i]>=55 && (int)id[i]<=57)){
                        checkFiveNumber++;
                    }
                }
                if(checkFiveNumber==5){
                    check=true;
                }
            }
        }
    }
    if(id.length()==10){
        if(salevorud>=84 && salevorud<=99){
            if((int)id[2]==42 && ((int)id[3]<48 | (int)id[3]>57) && ((int)id[4]<48 | (int)id[4]>57)){
                int checkFiveNumber=0;
                for(int i=5; i<10; i++){
                    if(((int)id[i]>=48 && (int)id[i]<=51) | ((int)id[i]>=55 && (int)id[i]<=57)){
                        checkFiveNumber++;
                    }
                }
                if(checkFiveNumber==5){
                    check=true;
                }
            }
        }
    }
    return check;
}

double Employee::calculateSalary(){
    double salary=(hourWork*salaryPerHour)*(((double)workDone)/((double)workToDo));
    return salary;
}

double Employee::efficiency(){
    double efficiency=100*(((double)workDone)/((double)workToDo));
    return efficiency;
}
