#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "gameState.h"
#include "raylib.h"
#include <iostream>
#include <thread>

    

class GameManager{
    public:
    
    GameManager();
    
    ~GameManager(){std::cout<<"GameManager Destruido"<<std::endl;};
    
    void changeState(GameState*);
    
    void runGameLoop();
    private:
    GameState* estadoActual=nullptr;
};



#endif