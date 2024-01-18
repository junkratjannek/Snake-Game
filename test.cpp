#include <iostream> 
using namespace std; 

namespace myNameSpace {
    int zahl = 10; 
}

int main() {
    // output
    cout << "Hello World\n"; 
    // numbers 
    int x = 10; 
    int y = 5; 
    int z = x + y; 
    cout << z; 

    int a; 
    cout << "Type a number: "; // Type a number and press enter
    cin >> a; // Get user input from the keyboard
    cout << "Your number is: " << a; // Display the input value

    // Data Types
    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;     // Floating point number
    double myDoubleNum = 9.98;   // Floating point number
    char myLetter = 'D';         // Character
    bool myBoolean = true;       // Boolean
    string myText = "Hello";     // String

    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << isCodingFun;  // Outputs 1 (true)
    cout << isFishTasty;  // Outputs 0 (false)

    int number1 = 1; 
    int number2 = 2; 
    cout << (number1 > number2); // returns true 
    cout << (number1 < number2);  // returns false 
    cout << (number1 != number2); // returns true
    cout << (number1 == number2); // return false 
    cout << (number1 >= number2); // returns true 
    cout << (number1 <= number2);  // returns false
    bool bool1 = true, bool2 = false; 
    if (bool1 && bool2)
    {
        cout << "Both are correct";
    }

    if (bool1 || bool2)
    {
        cout << "One of them is correct"; 
    }
    
    string fullName;
    cout << "Type your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName;
    
    std::string greeting = "Hello"; // heißt, dass es daraus entnommen wird 
    std::cout << greeting;

    return 0; 
}