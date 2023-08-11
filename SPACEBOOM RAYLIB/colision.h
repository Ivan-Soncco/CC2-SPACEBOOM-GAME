#ifndef COLISION_H
#define COLISION_H
#include "nave.h"
#include "enemy.h"
#include "bala.h"
#include <iostream>
#include <mutex>

class Colision{
    public:
        Colision(){};
        ~Colision(){std::cout<<"Colision Destruido"<<std::endl;};
        void colisionanNave(std::shared_ptr<Nave>,Enemy*, int);
        void colisionanBala(std::shared_ptr<Nave>,Enemy*, int);
        Sound naveColision = LoadSound("data/naveColision.mp3");
        Sound balaColision = LoadSound("data/balaColision.mp3");
        std::mutex mutexColision;
};


#endif