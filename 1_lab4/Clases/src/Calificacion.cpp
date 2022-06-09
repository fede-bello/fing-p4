#include "../include/Calificacion.h"



Calificacion::Calificacion(int Numero,string Comentario,string Respuesta, DTFecha Fecha,int Identificador){
    this->Numero=Numero;
    this->Comentario=Comentario;
    this->Respuesta=Respuesta;
    this->Fecha=Fecha;
    this->Identificador=Identificador;
    
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

int Calificacion::getIdentificador(){
    return this->Identificador;
}

Huesped* Calificacion::getHuesped(){
    return this->hues;
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

void Calificacion::setIdentificador(int identificador){
    this->Identificador = identificador;
}

void Calificacion::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

//operaciones

DTCalificacion Calificacion::getDTCalificacion(){
    return DTCalificacion(this->Numero, this->Comentario, this->Respuesta, this->Fecha, this->Identificador);
}

bool Calificacion::esCalificacion(int codigoCalif){
    return (this->Identificador==codigoCalif);
}

//destructora
Calificacion::~Calificacion(){
}