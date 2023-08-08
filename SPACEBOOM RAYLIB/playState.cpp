#include "playState.h"
#include "raylib.h"
#include <iostream>
#include "GameManager.h"
#include "menuState.h"
#include "enemy.h"
#include "nave.h"
#include "gameOverState.h"
#include <memory>

#define MAX_ENEMIES 6
#define MAX_BULLETS 100
#define screenWidth 940
#define screenHeight 480

void PlayState::handleInput(GameManager* context) {
    if (IsKeyPressed(KEY_U)) {
        context->changeState(new MenuState()); // Cambiar al estado Play
    }
    if (gameOver==true){
        context->changeState(new GameOverState(player1,player2));

    }
}

void PlayState::update(){
    
    if(firstUpdate==false){
        camera.position = (Vector3){-110.0f, 1.0f, 0.0f};
        //camera.position = (Vector3){120.0f, 120.0f, 120.0f};
        camera.target = (Vector3){0.0f, 0.0f, 0.0f};
        camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        camera.fovy = 35.0f;
        camera.projection = CAMERA_PERSPECTIVE;

        player1 = std::make_shared<Nave>(LoadModel("data/nave.gltf"));
        //player1 =new  Nave(LoadModel("data/nave.gltf"));
        player1->setPosicion((Vector3){-99.0f, 0.0f, -1.0f});

        player2 = std::make_shared<Nave>(LoadModel("data/nave.gltf"));
        //player2 =new  Nave(LoadModel("data/nave.gltf"));
        player2->setPosicion((Vector3){-99.0f, 0.0f, 1.0f});
        objColision=new Colision();
        for (int i = 0; i < MAX_ENEMIES; i++)
        {
        arrayEnemy[i].setModelo(LoadModel("data/asteroideCua.gltf"));
        }

        firstUpdate=true;
    }
    //Movimiento player1
    if (IsKeyDown(KEY_A))
        {
            player1->movIzquierda();
        }
    else if (IsKeyDown(KEY_D))
        {
            player1->movDerecha();
        }
    // Player 1 shoot bullet
    if (IsKeyPressed(KEY_SPACE) && player1->bulletCount > 0)
    {       
            player1->disparar();
    }

    // Player 2 movement
    if (IsKeyDown(KEY_LEFT))
    {
        player2->movIzquierda();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        player2->movDerecha();
    }

    // Player 2 shoot bullet
    if (IsKeyPressed(KEY_UP) && player2->bulletCount > 0)
    {    
        player2->disparar();
    }

    // Move bullets 1
    player1->moverBala();

    // Move bullets 2
    player2->moverBala();

    //Movimiento enemigo
    for (int i = 0; i < MAX_ENEMIES; i++){
            arrayEnemy[i].move(elapsedTime);
            //objColision->colisionan(player1,&arrayEnemy[i],i);
        }
    //Colision nave enemigo
    
    for (int i = 0; i < MAX_ENEMIES; i++)
        {
            objColision->colisionan(player1,&arrayEnemy[i],i);
            objColision->colisionan(player2,&arrayEnemy[i],i);
        }
    if (player1->bandera && player2->bandera)
        {
            gameOver = true;
            player1->bandera = false;
            player2->bandera = false;
            return;
        }   

    //Colision Bala Enemigo
    
    for (int i = 0; i < MAX_BULLETS; i++)
        {
            if (player1->bulletActive[i])
            {
                for (int j = 0; j < MAX_ENEMIES; j++)
                {
                    //arrayEnemy[j].colisionConBala(player1,i);
                    objColision->colisionan(player1,&arrayEnemy[j],i);
                }
            }
            if (player2->bulletActive[i])
            {
                for (int j = 0; j < MAX_ENEMIES; j++)
                {
                    //arrayEnemy[j].colisionConBala(player2,i);
                    objColision->colisionan(player2,&arrayEnemy[j],i);
                }
            }
        }    
}

void PlayState::render(){
        
        ClearBackground(BLACK);

        BeginMode3D(camera);

        // Draw player 1 ship
        player1->draw();
        player2->draw();
        // Draw arrayEnemy
        for (int i = 0; i < MAX_ENEMIES; i++)
        {   
            if (arrayEnemy[i].getPosicionX() != -30.0f){
                arrayEnemy[i].draw();
            }
        }
        // Draw bala
        
        for (int i = 0; i < MAX_BULLETS; i++)
        {
            if (player1->bulletActive[i]){
                DrawSphere(player1->arrayBalas[i].getPosicion(), 0.1f, BLUE);
            }
            
                //DrawSphere(player1->arrayBalas[i].getPosicion(), 0.1f, BLUE);
        }
        for (int i = 0; i < MAX_BULLETS; i++){
            if (player2->bulletActive[i]){
                DrawSphere(player2->arrayBalas[i].getPosicion(), 0.1f, RED);
            }
        }
        EndMode3D();
        // Draw UI
        DrawText("JUGADOR 1", 10, 10, 20, RED);
        DrawText(TextFormat("Score: %04i", player1->score), 10, 30, 20, GREEN);
        DrawText(TextFormat("Bullets: %02i", player1->bulletCount), 10, 50, 20, MAROON);
        DrawText(TextFormat("PLAYER 1: Muevete con A y D ; dispara con ESPACIO"), 10, 70, 20, WHITE);

        DrawText("JUGADOR 2", screenWidth - 150, 10, 20, RED);
        DrawText(TextFormat("Score: %04i", player2->score), screenWidth - 150, 30, 20, GREEN);
        DrawText(TextFormat("Bullets: %02i", player2->bulletCount), screenWidth - 150, 50, 20, MAROON);
        DrawText("PLAYER 2: Muevete con 4 y 6 ; dispara con ENTER", 10, 90, 20, WHITE);
}
