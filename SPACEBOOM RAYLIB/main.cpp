#include <iostream>
#include <raylib.h>
#include "menuState.h"
#include "playState.h"
#include "gameManager.h"
#define screenWidth 940
#define screenHeight 480

using namespace std;

int main () {

    InitWindow(screenWidth, screenHeight, "SpaceBoom");
    SetTargetFPS(60);
    GameManager gameManager;
    gameManager.runGameLoop();
    
    return 0;
}