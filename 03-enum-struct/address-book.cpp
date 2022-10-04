#include <iostream>
#include <string>
#include <array>
#include <tuple>

#define MAX_SIZE 50

using namespace std;

struct addressBook{
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    string houseNumber;
    string zipCode;
    int region;
};

void add(addressBook e){
    cin>>e.firstName;
    cin>>e.middleName;
    cin>>e.lastName;
    cin>>e.phoneNumber;
    cin>>e.streetAddress;
    cin>>e.houseNumber;
    cin>>e.zipCode;
    cin>>e.region;
}

void clr(addressBook e){
    e.firstName = "";
    e.middleName = "";
    e.lastName = "";
    e.phoneNumber = "";
    e.streetAddress = "";
    e.houseNumber = "";
    e.zipCode = "";
    e.region = 0;
}

void qry(addressBook e){
    cout<<e.firstName<<",";
    cout<<e.middleName<<",";
    cout<<e.lastName<<",";
    cout<<e.phoneNumber<<",";
    cout<<e.streetAddress<<",";
    cout<<e.houseNumber<<",";
    cout<<e.zipCode<<",";
    cout<<e.region<<","<<endl;
}

int main () {

    addressBook entry[MAX_SIZE];
    string action;
    int storage[51] = {};
    int *p = storage;
    unsigned int n;


    while(true){
        cin>>action;
        if(action=="add"){
            cin>>n;
            if (p[n] == 0){
                p[n] += 1;
                add(entry[n]);
            } 
        }else if (action == "del")
        {
            cin>>n;
            if (p[n] == 1){
                p[n] -= 1;
                clr(entry[n]);
            } 
        }else if (action == "qry")
        {
            cin>>n;
            if (p[n] == 1){
                qry(entry[n]);
            } 
        }else if (action == "quit")
        {
            return 0;
        }else{
            return 1;
        }
        
    }

    return 0;
}