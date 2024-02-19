#pragma once 

class ClassA 
{
    public: 
        ClassA(); // constructor 
        ClassA(int number); 
        ~ClassA(); // destructor

        int ToConsole(); 

    protected: 

    private: 
    int _number = 0; 
};