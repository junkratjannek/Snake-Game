#include <iostream>
#include <windows.h> 
#include "functions.h" 
// Beim Nutzen von '' wird zuerst lokal nach einer Bibliothek gesucht, beim Einsatz von <> wird erst bei externen Bibliotheken gesucht

using namespace std; 

void printArray(int count, int numbers[]); 

int learning2Function (int argc, char* args[]) {

    std::cout << 'Hello World!' << std::endl;
    // Datentyp (const char[12])"Hello World" - am ende kommt noch \0 dazu, deshlab 12 Zeichen
    std::cout << "Hello" << " " << "World" << std::endl; 
    std::cout << 10 << std::endl; 

    cout << "Hello World"; 

    int number;
    cin >> number;
    cout << "Number: " << number <<endl; 

    char sz[256]; 
    cin >> sz; 
    cout << "sz: " << sz << endl; 

    int number2[5]; 
    for (size_t i = 0; i < sizeof(number2); i++)
    {
        cout << number2[i] << " "; 
    }
    
    cout << endl; 

    return 0; 
}

void printArray(int count, int numbers[])
{
    for (size_t i = 0; i < count; i++)
    {
        cout << numbers[i] << " "; 
    }

    cout << endl; 
    
}

// void printArray(int numbers[]){
//     for (size_t i = 0; i < size(numbers); i++)
//     {
//         cout << numbers[i] << " "; 
//     }
    
//     cout << endl;
// }