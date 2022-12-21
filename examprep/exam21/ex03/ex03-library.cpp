#include <iostream>
#include <vector>
#include <algorithm>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    bool roomExist = false;
    if(find(this->roomNames.begin(), this->roomNames.end(), name) != this->roomNames.end()) {
        roomExist = true;
    }

    if(roomExist==true) {
        return;
    }
    else{
        this->roomNames.push_back(name);
    }
    
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    // Write your code here
    bool roomExist = false;
    if(find(this->roomNames.begin(), this->roomNames.end(), roomName) != this->roomNames.end()) {
        roomExist = true;
    }

    if(roomExist==true){

        for (auto g: this->roomOccupancy){
            if (g.second.id == guestId){
                return;
            }
        }

        if (this->roomOccupancy.find(guestId) == this->roomOccupancy.end()) {
            this->roomOccupancy[roomName] = {guestName, guestId};
            }
    }
    else{
        return;
    }

}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    for (auto r: this->roomNames){
        if (this->roomOccupancy.find(r) == this->roomOccupancy.end()){
            continue;
        }

        Guest g = this->roomOccupancy[r];
        
        bool match = true;
        if (guestName != "*"){
            match = (g.name == guestName);
        }
        if (guestId != "*"){
            match = match && (g.id == guestId);
        }
        if (match){
            cout << r << endl;
        }
    }
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
