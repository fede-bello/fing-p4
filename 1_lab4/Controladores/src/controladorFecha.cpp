

#include "../include/controladorFecha.h"



ControladorFecha * ControladorFecha::instancia = NULL;

ControladorFecha * ControladorFecha::getInstance() {
    if (instancia == NULL)
        instancia = new ControladorFecha();
    return instancia;
}


void ControladorFecha::ModificarFechaActual(DTFecha nuevo){
    int dia=nuevo.getDia();
    int Mes=nuevo.getMes();
    int Anio=nuevo.getAnio();
    int Hora = nuevo.getHora();
    if(this->fechaActual!=NULL)
        delete this->fechaActual;
    this->fechaActual = new DTFecha(dia,Mes,Anio, Hora);
}

ControladorFecha::ControladorFecha(){
} 

DTFecha* ControladorFecha:: getFechaActual(){
    return this->fechaActual;
}

ControladorFecha::~ControladorFecha(){
    delete this->fechaActual;
}