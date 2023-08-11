#include "menuState.h"
#include "raylib.h"
#include <iostream>
#include "GameManager.h"
#include "playState.h"

#define screenWidth 940
#define screenHeight 480

MenuState::MenuState(){
    menuSound=LoadSound("data/menuSound.mp3"); 
    buttonMenu=LoadSound("data/soundButton.mp3");
    PlaySound(menuSound);
    startTexture= LoadTexture("data/fondo1.png");
}


void MenuState::handleInput(GameManager* context) {
    if (IsKeyPressed(KEY_Q)) {
        PlaySound(buttonMenu);
        context->changeState(new PlayState()); // Cambiar al estado Play
    }
    
}

void MenuState::update(){
    
}

void MenuState::render() {
        ClearBackground(BLACK);
        DrawTexture(startTexture, screenWidth/2 - startTexture.width/2, screenHeight/2 - startTexture.height/2, WHITE);
        DrawText("SPACEBOOM", screenWidth / 2 - MeasureText("SPACEBOOM", 50) / 2, 100, 50, BLUE);
        DrawText("Press Q to start", screenWidth / 2 - MeasureText("Press Q to start", 20) / 2, screenHeight / 2 + 40, 20, BEIGE);
}