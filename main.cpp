#include <iostream>
#include "User.h"
using namespace std;

int main() {

    int choice;

    UserService add;
    char option;
    do{
        system("clear");
        cout << "\t\t --------------------------------------------------" << endl;
        cout << "\t\t ----------------------Haz-Chat--------------------" << endl;
        cout << "\t\t --------------------------------------------------" << endl;
        cout << "\t\t 1. Add User." << endl;
        cout << "\t\t 2. Remove a user." << endl;
        cout << "\t\t 3. Update Users." << endl;
        cout << "\t\t 4. Add to a user friend." << endl;
        cout << "Enter your choice :";
        cin  >> choice;
        switch(choice){
            case 1:{
                int userID;
                string name;
                string hashPass;
                cout << "Enter the ID :" << endl;
                cin >> userID;
                cout << "Enter the name :" << endl;
                cin.ignore();
                getline(cin,name);
                cout << "Enter the password :" << endl;
                getline(cin,hashPass);
                cin.ignore();
                add.addUser(userID,name,hashPass);
                break;
            }
            case 2:{
                break;
            }
            default :{
                break;
            }
        }
        cout << "Do you want to continue or Exit(y/n) :";
        cin >> option;
    }while(option == 'y' || option == 'Y');


    return 0;
}
