//
//  main.cpp
//  valeriabukova18
//
//  Created by Valeria  Bukova on 09.09.2024.
//

#include <iostream>
using namespace std;

struct Employee
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    double salary;
};

Employee employees[100];
int employeeCount = 0;


bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}


bool isPhoneNumberValid(const char* phoneNumber)
{
    int length = 0;
    while (phoneNumber[length] != '\0')
    {
      
        if (!isDigit(phoneNumber[length]))
        {
            return false;
        }
        length++;
    }
    return length == 10;
}

void addEmployee()
{
    if (employeeCount < 100)
    {
        Employee& emp = employees[employeeCount];

        cout << "Enter employee first name: ";
        cin >> emp.firstName;

        cout << "Enter employee last name: ";
        cin >> emp.lastName;

        cout << "Enter employee phone number (10 digits): ";
        cin >> emp.phoneNumber;

       
        while (!isPhoneNumberValid(emp.phoneNumber))
        {
            cout << "Invalid number format. Re-enter your phone number (10 digits): ";
            cin >> emp.phoneNumber;
        }

        cout << "Enter employee salary: ";
        cin >> emp.salary;

        employeeCount++;
    }
    else
    {
        cout << "Can't add more employees.\n";
    }
}

void displayEmployees()
{
    for (int i = 0; i < employeeCount; ++i)
    {
        Employee& emp = employees[i];
        cout << "Name: " << emp.firstName << " " << emp.lastName
             << ", Phone Number: " << emp.phoneNumber
             << ", Salary: " << emp.salary << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add an employee\n";
        cout << "2. Show all employees\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                cout << "Exit the program.\n";
                break;
            default:
                cout << "Wrong choice, try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

