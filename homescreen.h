#ifndef HOMESCREEN_H
#define HOMESCREEN_H 
#define NUM_FRAMES  3 
#include "raylib.h"
#include <iostream>

using namespace std; 

// typedef enum Screen {LOGO = 0, Title, GAMEPlay, Ending} Screen; 
// Color darkGreen = {43, 51, 24, 255};  
// Color green = {34, 139, 34, 255}; 

// int cellSize = 30; 
// int cellCount = 25; 
// int offset = 75; 

class Homescreen {
    public: 

    const int screenWidth = 750; 
    const int screenHeigth = 750; 
    bool working = true; 

    Homescreen(); 

    void Update(){
        if (working){
            cout << "Test"; 
        } 
    }

    void Draw(){
        cout << "Test2"; 
    }

};

#endif 


    // int drawHomeScreen(){
    // InitWindow(screenWidth, screenHeigth, "Snake Game"); 

    //     while (WindowShouldClose() == false){
    //         BeginDrawing(); 

    //         ClearBackground(green); 
    //         DrawText("Welcome to Snake-Game!", offset - 5, 20, 40, darkGreen); 
    //         EndDrawing(); 
    //     }

    //     CloseWindow(); 
    //     return 0; 
    // }