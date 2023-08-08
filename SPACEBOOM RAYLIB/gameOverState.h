#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "gameState.h"
#include "nave.h"
#include <iostream>

class PlayState;
class MenuState;

class GameOverState : public GameState {
public:
    GameOverState(std::shared_ptr<Nave> player1, std::shared_ptr<Nave> player2):play1(player1),play2(player2) {};
    ~GameOverState(){ std::cout<<"GAMEOVER Destruido"<<std::endl;};
    void handleInput(GameManager* context) override;
    void update() override;
    void render() override;
    bool drawOnceMenu=false;
private:
    std::shared_ptr<Nave> play1;
    std::shared_ptr<Nave> play2;
};

#endif