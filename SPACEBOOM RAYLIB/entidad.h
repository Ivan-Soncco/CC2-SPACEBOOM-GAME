#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <raylib.h>
#include <iostream>
#define MAX_BULLETS 100

class Entidad{
    public:
        Entidad();
        Entidad(Model);
        ~Entidad(){std::cout<<"Entidad Destruido"<<std::endl;};
        void setPosicion(Vector3);
        void setPosicionX(float);
        void setPosicionY(float);
        void setPosicionZ(float);
        Vector3 getPosicion();
        float& getPosicionX();
        float& getPosicionY();
        float& getPosicionZ();
        void setModelo(Model);
        Model getModelo();    
    private:
        Vector3 playerPosition;
        Model modelPlayer;
};

#endif
