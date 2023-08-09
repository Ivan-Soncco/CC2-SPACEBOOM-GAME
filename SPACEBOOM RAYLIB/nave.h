#ifndef NAVE_H
#define NAVE_H
#include <raylib.h>
#include "entidad.h"
#include "bala.h"
#include <memory>
#include <iostream>

#define MAX_BULLETS 100

class Nave: public Entidad{
    public:
        Nave();
        Nave(Model);
        ~Nave(){std::cout<<"Nave Destruido"<<std::endl;};
        void movIzquierda();
        void movDerecha();
        void disparar();
        void moverBala();
        int bulletCount= MAX_BULLETS;
        bool bulletActive[MAX_BULLETS]{0};
        Bala arrayBalas[MAX_BULLETS];
        int score{0};
        bool bandera=false;
        float model = 0.2;
        void reiniciarNave();
        void draw();
};

#endif