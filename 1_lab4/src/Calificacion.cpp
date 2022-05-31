#include "../include/Calificacion.h"


Calificacion::Calificacion(int num,string texto){
    this->num=num;
    this->texto=texto;
}

int Calificacion::getCodigo(){
    return this->num;
}

string Calificacion::getTexto(){
    return this->texto;
}

string Calificacion::getRespuesta(){
    return this->respuesta;
}

Calificacion::~Calificacion(){
}