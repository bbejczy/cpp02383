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

bool Hotel::roomExist(string name) {
    if(find(this->roomNames.begin(), this->roomNames.end(), name) != this->roomNames.end()) {
        return true;
    }
    else{
        return false;
    }
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {

    if(this->roomExist(name)==true) {
        return;
    }
    else{
        this->roomNames.push_back(name);
    }
    
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    // Write your code here

    if(this->roomExist(roomName)==true){
        if (this->roomOccupancy.find(guestId) != this->roomOccupancy.end()) {
            this->roomOccupancy[roomName] = {guestName, guestId};
            }
    }
    else{
        return;
    }

}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    // Write your code here
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
