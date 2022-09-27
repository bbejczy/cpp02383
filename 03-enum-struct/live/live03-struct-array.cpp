// Example showing how to use 'struct'ures
#include <iostream>
#include <string>

#define MAX_SIZE 3

using namespace std;

struct employee {
    string name;
    string surname;
    unsigned int salary;
};

void displayEmployee(employee e) {
    cout << "Name: " << e.name << "; surname: " << e.surname;
    cout << "; salary: " << e.salary << endl;
}

void raiseSalary(employee *e, int increment){
    e->salary = e->salary + increment;
}

int main() {
    
	employee employees[MAX_SIZE];
	
	
	employees[0] = {"Bjarne", "Stroustrup", 100000};
	employees[1] = {"John", "Doe", 50000};
    
    employees[2].name = "Margaret";
    employees[2].surname = "Hamilton";
    employees[2].salary = 500000;
	
    string action; // Will contain the user-supplied command
    int increment;
    unsigned int n;

	while (true)
    {
        cin >> action;
        if (action == "raise")
        {
            cin >> n;
            cin >> increment;
            if (n < MAX_SIZE) {
                raiseSalary(&employees[n], increment);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "display")
        {
            cin >> n;
            if (n < MAX_SIZE) {
                displayEmployee(employees[n]);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "quit")
        {
            return 0;
        }
        else
        {
            cout << "ERROR: invalid command" << endl;
            return 1;
        }
    }

    return 0;
}
