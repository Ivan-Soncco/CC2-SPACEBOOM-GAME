#ifndef BALA_H
#define BALA_H
#include "entidad.h"
#include <raylib.h>
#include <iostream>

#define MAX_BULLETS 100

class Bala : public Entidad{
    private:
    public:
        Bala();
        ~Bala(){std::cout<<"Bala Destruido"<<std::endl;};
};


#endif