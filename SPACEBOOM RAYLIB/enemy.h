#ifndef ENEMY_H
#define ENEMY_H
#include <raylib.h>
#include <iostream>
#include "entidad.h"
#include "nave.h"
#define MAX_ENEMIES 6



class Enemy : public Entidad{
    public:
        Enemy(){};
        ~Enemy(){std::cout<<"Enemy Destruido"<<std::endl;};
        Enemy(const Enemy& otro)= default;
        Enemy(Model);
        Enemy& operator=(const Enemy& otro);
        int getEnemyPoints();
        void msj(int);
        void move(double);
        
        void reiniciarEnemy();
        void draw();
    private:
        const int enemyPoints= 10;
        
};
#endif