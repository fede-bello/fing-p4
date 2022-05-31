#include "../include/DTCalificacion.h"


DTCalificacion::DTCalificacion(int num,string texto,DTFecha realizada){
    this->num=num;
    this->texto=texto;
    this->realizada=realizada;
}

DTCalificacion::DTCalificacion(int num,string texto,DTFecha realizada,string respuesta){
    this->num=num;
    this->texto=texto;
    this->realizada=realizada;
    this->respuesta=respuesta;
}

int DTCalificacion::getNum(){
    return this->num;
}

string DTCalificacion::getTexto(){
    return this->texto;
}

void DTCalificacion::setRespuesta(string respuesta){
    this->respuesta=respuesta;
}

DTFecha DTCalificacion::getFecha(){
    return this->realizada;
}

DTCalificacion::~DTCalificacion(){
}