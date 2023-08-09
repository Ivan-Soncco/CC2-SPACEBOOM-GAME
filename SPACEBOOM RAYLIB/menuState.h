#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "gameState.h"
#include <iostream>
#include "raylib.h"
#define NUM_FRAMES 3
#define screenWidth 940
#define screenHeight 480

class PlayState;

class MenuState : public GameState {
public:
    MenuState(){PlaySound(menuSound);};
    ~MenuState(){ std::cout<<"Menu Destruido"<<std::endl;};
    void handleInput(GameManager* context) override;
    void update() override;
    void render() override;
    Sound menuSound=LoadSound("data/menuSound.mp3"); 
    Texture2D startTexture= LoadTexture("data/fondo1.png");    
};
#endif