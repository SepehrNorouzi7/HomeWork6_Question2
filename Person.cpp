#include "Person.h"

Person::Person(){
    this->name="";
    this->id="";
    this->address.Address::getCountry()="";
    this->address.Address::getCity()="";
    this->address.Address::getStreet()="";
}

Person::Person(string name, string id, Address address){
    //agar id fard mo'tabar nabashad payam invakid id chap va barname khareg mishavad
    if(validate(id)==false){
        cout<<"invalid id"<<endl;
        exit(1);
    }
    else{
        this->name=name;
        this->id=id;
        this->address=address;
    }
}

Person::Person(const Person &constructor){
    this->name=constructor.name;
    this->id=constructor.id;
    this->address=constructor.address;
}

string Person::getName(){
    return name;
}

void Person::setName(string name){
    this->name=name;
}

string Person::getId(){
    return id;
}

void Person::setId(string id){
    this->id=id;
}

Address Person::getAddress(){
    return address;
}

void Person::setAddress(Address address){
    this->address=address;
}

istream &operator>>(istream strm, Person &person){
    /*karbar moteqayyer haye Person va Address ra vared mikonad
      moteqayyer haye address dar address zakhire mishavand
      dar nahayat prsn va prsn be person assign mishavad
    */
    string country;
    string city;
    string street;
    strm>>person.name>>person.id>>street>>city>>country;
    Address address(street,city,country);
    Person prsn(person.name,person.id,address);
    person=prsn;
    return strm;
}

ostream &operator<<(ostream strm, Person &person){
    strm<<"name: "<<person.name<<"\t"<<"id: "<<person.id<<endl;
    strm<<"country: "<<person.getAddress().getCountry()<<"\t"<<"city: "<<person.getAddress().getCity()<<"\t"<<"street: "<<person.getAddress().getStreet()<<endl;;
    return strm;
}

Person &Person::operator=(Person &person){
    name=person.name;
    id=person.id;
    address=person.address;
    return *this;
}

bool Person::validate(string id){
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
            if((int)id[2]<48 | (int)id[2]>57){
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
            if(((int)id[2]<48 | (int)id[2]>57) && ((int)id[3]<48 | (int)id[3]>57)){
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
            if(((int)id[2]<48 | (int)id[2]>57) && ((int)id[3]<48 | (int)id[3]>57) && ((int)id[4]<48 | (int)id[4]>57)){
                int checkFiveNumber=0;
                for(int i=5; i<10; i++){
                    if((int)id[i]>=48 && (int)id[i]<=51 && (int)id[i]>=55 && (int)id[i]<=57){
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