#include "../include/Calificacion.h"


Calificacion::Calificacion(int num,string texto,DTFecha realizada){
    this->num=num;
    this->texto=texto;
    this->realizada=realizada;
}

int Calificacion::getNum(){
    return this->num;
}

string Calificacion::getTexto(){
    return this->texto;
}

DTFecha Calificacion::getFecha(){
    return this->realizada;
}

string Calificacion::getRespuesta(){
    return this->respuesta;
}

void Calificacion::setRespuesta(string respuesta){
    this->respuesta=respuesta;
}


Calificacion::~Calificacion(){
}