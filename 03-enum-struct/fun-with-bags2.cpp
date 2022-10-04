#include <iostream>
#include <string>
#include <array>
#include <tuple>

using namespace std;

void add(int *p){
    int i;
    cin >> i;
    if (p[i] >= 0){
        p[i] += 1;
    } 
}

void del(int *p){
    int i;
    cin >> i;
    if (p[i] > 0){
        p[i] -= 1;
    }
}

void qry(int *p){
    int i;
    cin >> i;
    if (p[i] > 0){
        cout<<"T";
    }else if (p[i] == 0)
    {
        cout<<"F";
    }
    
}

int main () {

    // array<int, 1001> storage = {};
    int storage[1001] = {};
    string action;

    int *p = storage;

    while(true){
         cin>>action;
        if(action=="add"){
            add(p);
        }else if (action == "del")
        {
            del(p);
        }else if (action == "qry")
        {
            qry(p);
        }else if (action == "quit")
        {
            return 0;
        }else{
            return 1;
        }
        
    }

    return 0;
}