#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    
    //variables
    string operation;
    double number1, number2;
    char cont = 'y';
    
    //user input
    while(cont == 'y' || cont == 'Y'){
        cout << "Enter first number: ";
        cin >> number1;
        cout << "Enter Operation (+, -, *, /): ";
        cin >> operation;
        cout << "Enter second number: ";
        cin >> number2;

        //if else statements for operations
        if (operation == "+"){
            cout << "Result: " << number1 + number2 << endl;
        }
        else if (operation == "-"){
            cout << "Result: " << number1 - number2 << endl;
        }
        else if (operation == "*"){
            cout << "Result: " << number1 * number2 << endl;
        }
        else if (operation == "/"){
            if (number2 != 0){
                cout << "Result: " << number1 / number2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
        }
        else {
            cout << "Invalid operation!" << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> cont;

        switch(cont){
            case 'y':
            case 'Y':
                continue;
            case 'n':
            case 'N':
                cout << "Exiting calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid input. Exiting calculator. Goodbye!" << endl;
                cont = 'n';
                break;
        }
        }
    return 0;
}
