#include "colision.h"


void Colision::colisionan(std::shared_ptr<Nave> player, Enemy* arrayEnemigos, int i){
    //Colision Nave Enemigos
    if (CheckCollisionBoxSphere((BoundingBox){(Vector3){player->getPosicionX() - 0.5f, player->getPosicionY() - 0.5f, player->getPosicionZ() - 0.5f},
                                (Vector3){player->getPosicionX() + 0.5f, player->getPosicionY() + 0.5f, player->getPosicionZ() + 0.5f}},
                                (Vector3){arrayEnemigos->getPosicionX(), arrayEnemigos->getPosicionY(), arrayEnemigos->getPosicionZ()}, 0.5f)){
            PlaySound(naveColision);
            player->bandera= true;
            player->model = 0.02;
            // bloquear movimiento y disparo del jugador 1
            player->setPosicionX(-120);
            player->bulletCount = 0;
            float x = GetRandomValue(-30, -10);
            float z = GetRandomValue(-6, 6);
            //player->bulletActive[i] = false;
            //player->arrayBalas[i].setPosicion((Vector3){-120, 0.0f, 0.0f});
            arrayEnemigos->setPosicion((Vector3){x, 0.0f, z});
            std::cout<<"Colision nave enemigo"<<std::endl;
    }
    //Colision Bala Enemigos
    if((CheckCollisionBoxSphere((BoundingBox){(Vector3){arrayEnemigos->getPosicionX()- 0.5f, arrayEnemigos->getPosicionY() - 0.5f, arrayEnemigos->getPosicionZ() - 0.5f},
                                                              (Vector3){arrayEnemigos->getPosicionX() + 0.5f, arrayEnemigos->getPosicionY() + 0.5f, arrayEnemigos->getPosicionZ() + 0.5f}},
                                                (Vector3){player->arrayBalas[i].getPosicionX(), player->arrayBalas[i].getPosicionY(), player->arrayBalas[i].getPosicionZ()}, 0.1f))
        ){
            PlaySound(balaColision);
            player->bulletActive[i] = false;

            float x = GetRandomValue(-30, -10);
            float z = GetRandomValue(-6, 6);
            arrayEnemigos->setPosicion((Vector3){x, 0.0f, z});

            player->score += arrayEnemigos->getEnemyPoints();
        }

}

