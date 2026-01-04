#include <iostream>
#include <fstream>  //File Manipulation
#include <string>
#include <stdlib.h>
using namespace std;

void mainmenu();

int choice;
bool cinfail;
int confirmation;
string username, password, password2;

void writetofile(string username){
    ofstream writefile;
    string file = username+".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
    mainmenu();
}

void login(){
    cout << "Login in Process" << endl;
}

void registerpassword(){
    cout << "Please enter your password: " << endl;
    cin >> password;
    cout << "Please re-enter your password: " << endl;
    cin >> password2;
    if (password == password2){
        cin.clear();
        cin.ignore(10000,'\n');
        writetofile(username);
        exit(1);
    }
    else{
        cout << "Invalid Password, Please try again." << endl;
        registerpassword();
    }
}

void registerme(){
    cout << "Please Enter your username: " << endl;
    getline(cin, username);
    cout << "\nUsername - \"" << username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
    cin >> confirmation;
    if (confirmation ==1){
        registerpassword();
    }
    else{
        cout << "Invlaid Input, Please try again." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        registerme();
    }
}

void exit(){
    exit(0);
}

void mainmenu(){
    cout << "Welcome, Please select an option: " << endl;
    cout << "[1] Login\n[2] Register\n[3] Exit" << endl;
    cin >> choice;
    do{
        cinfail = cin.fail();
        cin.clear();
        cin.ignore(10000,'\n');
        }
    while (cinfail == true);{
        switch(choice){
            case 1:
                login();
                break;
            
            case 2:
                registerme();
                break;

            case 3:
                exit();
                break;
        }
    }
}

main(){
    cout<<"==================================\n";
    cout<<"|  Login and Registration System  |\n";
    cout<<"==================================\n\n";
    mainmenu();
}