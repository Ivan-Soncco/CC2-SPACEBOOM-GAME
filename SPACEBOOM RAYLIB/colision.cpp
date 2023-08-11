#include "colision.h"


void Colision::colisionanNave(std::shared_ptr<Nave> player, Enemy* arrayEnemigos, int i){
    //Colision Nave Enemigos
    std::unique_lock<std::mutex> guard(mutexColision, std::defer_lock);
    guard.lock();
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
            arrayEnemigos->setPosicion((Vector3){x, 0.0f, z});
            std::cout<<"Colision nave enemigo"<<std::endl;
    }
    guard.unlock();
}

void Colision::colisionanBala(std::shared_ptr<Nave> player, Enemy* arrayEnemigos, int i){
    //Colision Bala Enemigos
    std::unique_lock<std::mutex> guard(mutexColision, std::defer_lock);
    guard.lock();
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
            std::cout<<"Colision BALA enemigo"<<std::endl;
        }
    guard.unlock();    

}

