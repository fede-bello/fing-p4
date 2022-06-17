#include "../include/DTCalificacion.h"

   
DTCalificacion::DTCalificacion(){
    this->Numero=0;
    this->Comentario=".";
    this->Respuesta=".";
    this->Fecha=DTFecha();
    this->Identificador=0;
    
}

DTCalificacion::DTCalificacion(int Numero,string Comentario,string Respuesta, DTFecha Fecha,int Identificador){
    this->Numero=Numero;
    this->Comentario=Comentario;
    this->Respuesta=Respuesta;
    this->Fecha=Fecha;
    this->Identificador=Identificador;
    
}

int DTCalificacion::getNumero(){
    return this->Numero;
}

string DTCalificacion::getComentario(){
    return this->Comentario;
}

string DTCalificacion::getRespuesta(){
    return this->Respuesta;
}

DTFecha DTCalificacion::getFecha(){
    return this->Fecha;
}

int DTCalificacion::getIdentificador(){
    return this->Identificador;
}

void DTCalificacion::imprimir(){
    cout<< "Numero: ";
    cout<< this->Numero<<endl;
    cout<< "Comentario: ";
    cout<< this->Comentario <<endl;
    cout<< "Respuesta: ";
    cout<< this->Respuesta<<endl;
    cout<<"Fecha: ";
    this->Fecha.imprimir();

}

DTCalificacion::~DTCalificacion(){

}