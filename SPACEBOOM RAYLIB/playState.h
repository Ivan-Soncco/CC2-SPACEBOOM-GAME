#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "gameState.h"
#include <iostream>
#include "nave.h"
#include "enemy.h"
#include "colision.h"
#include <memory>


class MenuState;
class GameOverState;

class PlayState : public GameState {
public:
    PlayState(){};
    ~PlayState(){std::cout<<"Play Destruido"<<std::endl;};
    void handleInput(GameManager* context) override;
    void update() override;
    void render() override;
    bool drawOncePlay=false;
    double startTime = GetTime();
    double currentTime = startTime;
    double elapsedTime = 0.0;
    std::shared_ptr<Nave> player1;
    std::shared_ptr<Nave> player2;
    //Nave* player1=nullptr;
    //Nave* player2=nullptr;
    Camera camera = {0};
    bool firstUpdate=false;
    Enemy* arrayEnemy= new  Enemy[6]();
    Colision* objColision=nullptr;
    bool gameOver=false;
};


#endif