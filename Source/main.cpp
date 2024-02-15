#include <iostream>
#include <raylib.h>
#include <deque> 
#include <raymath.h>

using namespace std;

// struct Color {red, green, blue, alpha} -> colors in raylib 
Color darkGreen = {43, 51, 24, 255};  
Color green = {34, 139, 34, 255};
Color red =  {255, 0, 0, 255}; 
Color white = {255, 255, 255, 255}; 
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

int cellSize = 30; 
int cellCount = 25; 
int offset = 75; 

double lastUpdateTime = 0; 

bool eventTriggered(double interval){
    double currentTime = GetTime(); 
    if (currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime; 
        return true; 
    }
    return false; 
}

bool ElementInDeque(Vector2 element, deque<Vector2> deque){
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element)){
            return true; 
        }
    }
    return false; 
    
}

class Snake {
    public:
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    Vector2 direction = {1,0};      
    bool addSegment = false; 

    void Draw() {
        for (unsigned int i = 0; i < body.size(); i++)
        {
           float x = body[i].x;
           float y = body[i].y; 
           Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, float(cellSize), float(cellSize)};
           DrawRectangleRounded(segment, 0.5, 6, darkGreen); 
        }
        
    }

    void Update(){
        body.push_front(Vector2Add(body[0], direction)); 

        if (addSegment == true){
            addSegment = false; 
        }else {
            body.pop_back(); 
        }
        
    }

    void Reset(){
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}}; 
        direction = {1,0}; 
    }
};

class Food {
    
    public: 

    Vector2 position; 
    Texture2D texture; 

    Vector2 GenerateRandomCell(){
        float x  = GetRandomValue(0, cellCount - 1); 
        float y  = GetRandomValue(0, cellCount - 1);
        return Vector2{x,y}; 
    }

    Vector2 generateRandomPositionForFood(deque<Vector2> snakeBody)
    {
        Vector2 position = GenerateRandomCell(); 
        while(ElementInDeque(position, snakeBody)){
            position = GenerateRandomCell(); 
        }
        return position; 
    }

    Food(deque<Vector2> snakeBody){
        Image imageApple = LoadImage("images/banana.png");
        ImageResize(&imageApple, 30, 30);
        texture = LoadTextureFromImage(imageApple); 
        UnloadImage(imageApple); 
        position = generateRandomPositionForFood(snakeBody); 
    }

    // Banana(deque<Vector2> snakeBody){
    //     Image imageBanana = LoadImage("images/banana.png"); 
    //     ImageResize(&imageBanana, 30, 30); 
    //     texture = LoadTextureFromImage(imageBanana); 
    //     UnloadImage(imageBanana); 
    //     position = generateRandomPositionForFood(snakeBody);  
    // }

    // Stone(deque<Vector2> snakeBody){
    //     Image imageRock = LoadImage("images/rock.png"); 
    //     ImageResize(&imageRock, 30, 30); 
    //     texture = LoadTextureFromImage(imageRock); 
    //     UnloadImage(imageRock); 
    //     position = generateRandomPositionForFood(imageRock); 
    // }

    ~Food(){
        UnloadTexture(texture); 
    }

    void Draw() {
        DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize , WHITE); 
    }

};

class Game {
    public: 

    Snake snake = Snake(); 
    Food food = Food(snake.body); 
    bool running = true; 
    int fruitsEaten = 0; 
    bool buttonTriggered = false; 
    bool showScore = false; 
    Sound eatFood; 
    Sound wallSound;

    Game()
    {
        InitAudioDevice(); 
        wallSound = LoadSound("sounds/wall.mp3"); 
        // collectFood = LoadSound("sounds/eatApple.mp3"); 
    }

    ~Game()
    {
        // UnloadSound(collectFood); 
        UnloadSound(wallSound); 
        CloseAudioDevice(); 
    }

    void Draw()
    {
        food.Draw(); 
        snake.Draw(); 
    }

    void Update()
    {
        if (buttonTriggered){
            if (running){
                snake.Update(); 
                checkColisionWithFood(); 
                checkColisionWithWall(); 
                checkCollisionWithBody(); 
            }
        }
    }

    void checkColisionWithFood()
    {
        if (Vector2Equals(snake.body[0], food.position)){
            food.position = food.generateRandomPositionForFood(snake.body);
            snake.addSegment = true; 
            fruitsEaten ++; 
        }
    }

    void checkColisionWithWall(){
        if (snake.body[0].x == cellCount || snake.body[0].x == -1){ 
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1){
            GameOver(); 
        }
    }

    void checkCollisionWithBody(){
        for (unsigned int i = 1; i < snake.body.size(); i++)
        {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
            {
                GameOver(); 
            }
        }
        
    }

    void startGame(){
        cout << "Test"; 
    }

    void GameOver(){
        snake.Reset(); 
        food.position = food.generateRandomPositionForFood(snake.body);
        running = false;  
        fruitsEaten = 0; 
        PlaySound(wallSound); 
        // TODO Implement Window, that works as a highscore displayer and start screen  
    }
};

int main () {

    InitWindow(2 * offset + cellSize*cellCount, 2 * offset + cellSize*cellCount, "Snake Game");  
    SetTargetFPS(60); 

    // Homescreen homescreen = Homescreen(); 
    Game game = Game();  

    while (WindowShouldClose() == false)
    {
        // if (game.buttonTriggered == false){
        //     BeginDrawing(); 
        //     ClearBackground(green);  
        //     DrawText("Welcome to Snake Game", offset - 50, 20, 80, darkGreen); 
        //     DrawText("Press ENTER to start the game", offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
        // }

        // if (IsKeyPressed(KEY_SPACE)){
        //     game.buttonTriggered = true; 
        //     // game.showScore = false; 
        // }

        BeginDrawing(); 

        if (game.buttonTriggered == true){
            if (eventTriggered(0.2)){
                game.Update(); 
            }
            if((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.snake.direction.y != 1){
                game.snake.direction = {0, -1}; 
                game.running = true; 
            }
            if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.snake.direction.y != -1){
                game.snake.direction = {0, 1}; 
                game.running = true; 
            }
            if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.snake.direction.x != 1){
                game.snake.direction = {-1, 0};
                game.running = true; 
            }
            if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.snake.direction.x != -1){
                game.snake.direction = {1, 0}; 
                game.running = true; 
            }
            if (IsKeyPressed(KEY_SPACE)){
                game.buttonTriggered = false; 
                game.GameOver(); 
            }   
            
            ClearBackground(green); 
            DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen); 
            DrawText("Snake Game", offset - 5, 20, 40, darkGreen); 
            DrawText(TextFormat("Score: %i", game.fruitsEaten), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
            game.Draw(); 
        }   
        EndDrawing(); 
    }



    CloseWindow(); 
    return 0;
}