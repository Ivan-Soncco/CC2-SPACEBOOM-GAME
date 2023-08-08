#ifndef COLISION_H
#define COLISION_H
#include "nave.h"
#include "enemy.h"
#include "bala.h"
#include <iostream>

class Colision{
    public:
        Colision(){};
        ~Colision(){std::cout<<"Colision Destruido"<<std::endl;};
        void colisionan(std::shared_ptr<Nave>,Enemy*, int);
        
};


#endif