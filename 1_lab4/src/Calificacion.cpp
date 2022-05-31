#include "../include/Calificacion.h"


Calificacion::Calificacion(int num,string texto,DTFecha realizada){
    this->num=num;
    this->texto=texto;
    this->realizada=realizada;
}

int Calificacion::getCodigo(){
    return this->num;
}

string Calificacion::getRespuesta(){
    return this->respuesta;
}




Calificacion::~Calificacion(){
}