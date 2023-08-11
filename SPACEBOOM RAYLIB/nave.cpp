#include "nave.h"
#include <raylib.h>
#include "bala.h"
#include <iostream>
#include <memory>
#define MAX_BULLETS 100

Nave::Nave(){}

Nave::Nave(Model m1)
{
    setModelo(m1);
}
void Nave::movIzquierda(){
    //std::lock_guard<std::mutex> lock(mutexNave);
    std::unique_lock<std::mutex> guard(mutexNave, std::defer_lock);
    guard.lock();
    getPosicionZ()-= 0.2f;
    guard.unlock();
    //restriccion
    if(getPosicionZ() < -6.0f){
        setPosicionZ(-6.0f);
    }
}
void Nave::movDerecha(){
    //std::lock_guard<std::mutex> lock(mutexNave);
    std::unique_lock<std::mutex> guard(mutexNave, std::defer_lock);
    guard.lock();
    getPosicionZ()+= 0.2f;
    guard.unlock();
    //restriccion
    if(getPosicionZ() > 6.0f){
        setPosicionZ(6.0f);
    }
}

void Nave::disparar(){
            bool bulletFired = false;
            std::unique_lock<std::mutex> guard(mutexNave, std::defer_lock);
            for (int i = 0; i < MAX_BULLETS; i++)
            {
                if (!bulletActive[i])
                {
                    
                    guard.lock();
                    arrayBalas[i].setPosicion(getPosicion());
                    bulletActive[i] = true;
                    bulletFired = true;
                    guard.unlock();
                    break;
                }
            }
            
            if (bulletFired)
            {
                bulletCount--;
            }
}
void Nave::moverBala(){

    const int screenWidth = 940;
    std::unique_lock<std::mutex> guard(mutexNave, std::defer_lock);
    for (int i = 0; i < MAX_BULLETS; i++)
            {
                if (bulletActive[i])
                {   
                    guard.lock();
                    arrayBalas[i].getPosicionX()+= 0.2f;

                    if (arrayBalas[i].getPosicionX() > screenWidth)
                    {
                        bulletActive[i] = false;
                    }
                    guard.unlock();
                }
            }        
}

void Nave::reiniciarNave(){
    for (int i = 0; i < MAX_BULLETS; i++)
        {
            bulletActive[i] = false;
        }

    bulletCount= MAX_BULLETS;
    score = 0;
    model=0.2;
    bandera=false;
    //setPosicion((Vector3){-99.0f, 0.0f, -1.0f});
}

void Nave::draw(){
    DrawModel(getModelo(), getPosicion(), model, WHITE);
}

