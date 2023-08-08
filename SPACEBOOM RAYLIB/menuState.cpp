#include "menuState.h"
#include "raylib.h"
#include <iostream>
#include "GameManager.h"
#include "playState.h"

#define screenWidth 940
#define screenHeight 480

void MenuState::handleInput(GameManager* context) {
    if (IsKeyPressed(KEY_Q)) {
        context->changeState(new PlayState()); // Cambiar al estado Play
    }
    
}

void MenuState::update(){
    
}

void MenuState::render() {
        ClearBackground(BLACK);
        DrawTexture(startTexture, screenWidth/2 - startTexture.width/2, screenHeight/2 - startTexture.height/2, WHITE);
        DrawText("GAME MENUSTATE", screenWidth / 2 - MeasureText("GAME MENUSTATE", 20) / 2, screenHeight / 2 + 20, 20, GRAY);
        DrawText("Press Q to start", screenWidth / 2 - MeasureText("Press Q to start", 20) / 2, screenHeight / 2 + 40, 20, GRAY);
}