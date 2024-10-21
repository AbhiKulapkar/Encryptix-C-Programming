#include<iostream>
using namespace std;

int main(){
    double num1, num2;
    char op;

    cout << "Enter the operator (+ - * / ): ";
    cin>>op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;


    switch(op)
    {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
         cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            break;
    }
}