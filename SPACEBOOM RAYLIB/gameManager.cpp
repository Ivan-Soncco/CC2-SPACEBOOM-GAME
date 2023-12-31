#include "gameManager.h"
#include "menuState.h"
#include "raylib.h"
#include <thread>


GameManager::GameManager() {
    InitAudioDevice();
    estadoActual = new MenuState();
    //InitWindow(800, 600, "State Pattern with Raylib");
}

void GameManager::changeState(GameState* nuevoEstado){
        if (estadoActual != nullptr) {
            delete estadoActual; // Liberamos la memoria del estado actual
        }
        estadoActual = nuevoEstado; // Cambiamos al nuevo estado
}



void GameManager::runGameLoop(){
    
    while (!WindowShouldClose()) {
        estadoActual->handleInput(this);
        
        estadoActual->update();
        BeginDrawing();
        estadoActual->render();
        EndDrawing();
    }
    CloseAudioDevice();
}
