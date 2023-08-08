#include "entidad.h"
#include <raylib.h>
#include <iostream>

Entidad::Entidad(){}

Entidad::Entidad(Model m1)
{
    setModelo(m1);
}

void Entidad::setPosicion(Vector3 pos){
    playerPosition=pos;
}
void Entidad::setPosicionX(float valor)
{
    playerPosition.x=valor;
}
void Entidad::setPosicionY(float valor)
{
    playerPosition.y=valor;
}
void Entidad::setPosicionZ(float valor)
{
    playerPosition.z=valor;
}
float& Entidad::getPosicionX()
{
    return playerPosition.x;
}
float& Entidad::getPosicionY()
{
    return playerPosition.y;
}
float& Entidad::getPosicionZ()
{
    return playerPosition.z;
}
void Entidad::setModelo(Model modelo){
    modelPlayer=modelo;
}
Model Entidad::getModelo(){
    return modelPlayer;
}
Vector3 Entidad::getPosicion(){
    return playerPosition;
}