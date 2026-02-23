// COMSC 210 | Lab 11 | Ibrahim Bello
// This program uses a dynamic array of structs to store a 
// directory of employees at a company.

// Employee data: Name, role, salary, vacation days used in the last 4 months

#include <iostream>
#include <string>
using namespace std;

const int NR_MONTHS = 4, NR_EMPLOYEES = 3;

struct Employee {
    string name;
    string role; // Job title 
    int salary; // Yearly salary
    int * vacayDays; // Number of vacation days used in each of the last NR_MONTHS months

    ~Employee() {
        if (vacayDays) 
            delete [] vacayDays;
        vacayDays = nullptr;
    }
};

void inputEmployee(Employee *);
void displayEmployee(Employee *);

int main() {
    Employee *team = new Employee[NR_EMPLOYEES];
    
    for (int i = 0; i < NR_EMPLOYEES; i++)
        inputEmployee(&team[i]);
    
    for (int i = 0; i < NR_EMPLOYEES; i++)
        displayEmployee(&team[i]);
    
    return 0;
}

void inputEmployee(Employee * eptr) {
    static int nrEmp = 1;
    cout << "Input data for Employee #" << nrEmp << ":\n";
    cout << "Name: ";
    getline(cin, eptr->name);
    cout << "Job Title: ";
    getline(cin, eptr->role);
    cout << "Salary: ";
    cin >> eptr->salary;
    eptr -> vacayDays = new int[NR_MONTHS];
    for (int i = 0; i < NR_MONTHS; i++) {
        cout << "Vacation days used in month #" << i + 1 << ": ";
        cin >> eptr->vacayDays[i];
    }
    cin.ignore();
    cout << endl << endl;
    nrEmp++;
}

void displayEmployee(Employee * eptr) {
    cout << "Employee summary:\n";
    cout << "Name: " << eptr->name << endl;
    cout << "Job Title: " << eptr->role << endl;
    cout << "Salary: " << eptr->salary << endl;
    for (int i = 0; i < NR_MONTHS; i++)
        cout << "Grade #" << i + 1 << ": " 
             << eptr->vacayDays[i] << endl;
    cout << endl << endl;
}