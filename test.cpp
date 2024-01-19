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

    int time = 20;
    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << result;

    string cars[4] = {"Opel", "BMW", "Mercedes", "Porsche"};
    cars[0] = "Audi"; 
    int lengthOfArray = sizeof(cars) / sizeof(int); 
    for (int i = 0; i < lengthOfArray - 1; i++)
    {
        cout << cars[i]; 
    }
    
    string food = "Pizza";  // food variable
    string &meal = food;    // reference to food

    string food = "Pizza";
    cout << &food; // Outputs 0x6dfed4

    string food = "Pizza";  // A food variable of type string
    string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food
    newMain(); 
    return 0; 
}

void myFunction(string fname, int age) {
  cout << fname << " Refsnes. " << age << " years old. \n";
}

int newMain(){
    myFunction("Liam", 3);
    myFunction("Jenny", 14);
    myFunction("Anja", 30);
    return 0;
}

int plusFunc(int x, int y) {
  return x + y;
}

double plusFunc(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFunc(8, 5);
  double myNum2 = plusFunc(4.3, 6.26);
  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
}

class MyClass {
    public: 
    int myNum; 
    void functionMethod(){
        cout << 15; 
    }
    MyClass(){
        cout << "Hello World"; //Constructor
    }
};

int functionToTestClass(){
    MyClass myObject; 
    myObject.myNum = 1; 
    cout << myObject.myNum; 
    myObject.functionMethod(); 
    MyClass myObject; 
    return 0; 
}

/* Access Specifier: 
public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more
*/