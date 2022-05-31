#include "../include/DTCalificacion.h"


DTCalificacion::DTCalificacion(int num,string texto){
    this->num=num;
    this->texto=texto;
}

int DTCalificacion::getCodigo(){
    return this->num;
}

string DTCalificacion::getTexto(){
    return this->texto;
}

string DTCalificacion::getRespuesta(){
    return this->respuesta;
}

DTCalificacion::~DTCalificacion(){
}