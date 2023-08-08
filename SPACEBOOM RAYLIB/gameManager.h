#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "gameState.h"
#include <iostream>

    

class GameManager{
    public:
    GameManager();
    ~GameManager(){std::cout<<"GameManager Destruido"<<std::endl;};
    void changeState(GameState*);
    //void handleInpu();
    //void updat();
    void render();
    void runGameLoop();
    private:
    GameState* estadoActual;
};



#endif