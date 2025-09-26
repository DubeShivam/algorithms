#include <iostream>
using namespace std;

// Statement
// Declaration statements
// Execution statements

// Execution statements are written inside functions




// Variables 
// Declaration
// Initialization
// int a; a = 10;      Wrong

int a;  
int b = 10;
int c = 2, d = 4;




// Data types
// int (4 bytes) 
// char (1 byte) 
// bool (1 byte) 
// float (4 bytes) 
// double (8 bytes)




// Type conversion
// Implicit conversion or type coercion (small to big) 
// Explicit conversion or type casting (big to small)

// In cpp we do not round off we just remove the numbers after decimal

char grade = 'A';
int frade = grade;  // Implicit

double x = 100.99;
float y = (float) x;  // Explicit




// Input and output 
void add() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a;
    cin >> b;
    cout << "Sum of give numbers: " << a + b;
}




// Operators
// Arithmetic operators (+ - * / %)
// Relational operators (< > <= >= == !=)
// Logical operators (&& || !)
// Bitwise operators

void calc() {
    cout << 5/2 << endl << 5%2;           // 2 // 1
}




// Control flow
// Conditionals 
// Loops
// Nested conditionals
// Nested loops

void f1() {
    int day = 1;
    char ch = 'a';

    if (ch >= '0' && ch <= '9') {
        cout << "Number";
    } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        cout << "Alphabet";
    } else {
        cout << "Something else";
    }

    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid input";
            break;
    }

    true? cout << 'True': cout << 'False';

    cout << (true? 'True': 'False');
}

void f2() {
    int j = 0;
    for (int i = 0; i < 11; i++) {
        cout << i;
    }
    
    while(j < 11) {
        cout << j++;
    }

    j=0;
    do {
        cout << j++;
    } while(j<11);
}




int main() {
    return 0;
}