#include "gameOverState.h"
#include "raylib.h"
#include <iostream>
#include "GameManager.h"
#include "playState.h"
#include "menuState.h"

#define screenWidth 940
#define screenHeight 480

void GameOverState::handleInput(GameManager* context) {
    if (IsKeyPressed(KEY_R)) {
        context->changeState(new PlayState()); // Cambiar al estado Play
    }
    if (IsKeyPressed(KEY_Q)) {
        context->changeState(new MenuState()); // Cambiar al estado Play
    }
}

void GameOverState::update(){
    
}

void GameOverState::render() {
    ClearBackground(BLACK);

            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));

            DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 40) / 2, screenHeight / 2 - 80, 40, RED);

            if (play1->score > play2->score)
            {
                DrawText("JUGADOR 1 GANA", screenWidth / 2 - MeasureText("JUGADOR 1 GANA", 30) / 2, screenHeight / 2 - 20, 30, GRAY);
                
            }
            else if (play1->score < play2->score)
            {
                DrawText("JUGADOR 2 GANA", screenWidth / 2 - MeasureText("JUGADOR 2 GANA", 30) / 2, screenHeight / 2 - 20, 30, GRAY);
            }
            else
            {
                DrawText("EMPATE", screenWidth / 2 - MeasureText("EMPATE", 30) / 2, screenHeight / 2 - 20, 30, GRAY);
            }

            DrawText("Press R to restart", screenWidth / 2 - MeasureText("Press R to restart", 20) / 2, screenHeight / 2 + 40, 20, GRAY);
            DrawText("Press Q to back MENU", screenWidth / 2 - MeasureText("Press R to back MENU", 20) / 2, screenHeight / 2 + 60, 20, GRAY);
            //scores
            DrawText(TextFormat("Puntaje P1: %04i", play1->score), screenWidth / 2 - MeasureText(TextFormat("Score: %04i", play1->score), 30) / 2, screenHeight / 2 + 80, 20, GRAY);
            DrawText(TextFormat("Puntaje P2: %04i", play2->score), screenWidth / 2 - MeasureText(TextFormat("Score: %04i", play2->score), 30) / 2, screenHeight / 2 + 100, 20, GRAY);
    

}