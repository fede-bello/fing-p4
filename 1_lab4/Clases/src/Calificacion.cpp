#include "../include/Calificacion.h"


Calificacion::Calificacion(int Numero,string Comentario,DTFecha Fecha){
    this->Numero = Numero;
    this->Comentario = Comentario;
    this->Fecha = Fecha;
}

int Calificacion::getNumero(){
    return this->Numero;
}

string Calificacion::getComentario(){
    return this->Comentario;
}

string Calificacion::getRespuesta(){
    return this->Respuesta;
}

DTFecha Calificacion::getFecha(){
    return this->Fecha;
}

void Calificacion::setNumero(int numero){
    this->Numero = numero;
}

void Calificacion::setComentario(string comentario){
    this->Comentario = comentario;
}

void Calificacion::setRespuesta(string respuesta){
    this->Respuesta = respuesta;
}

void Calificacion::setFecha(DTFecha fecha){
    this->Fecha = fecha;
}

Calificacion::~Calificacion(){
}