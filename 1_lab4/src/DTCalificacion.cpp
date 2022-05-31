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