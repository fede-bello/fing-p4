

#include "../include/controladorFecha.h"




FechaControlador * FechaControlador::instancia = NULL;

FechaControlador * FechaControlador::getInstance() {
    if (instancia == NULL)
        instancia = new FechaControlador();
    return instancia;
}


void FechaControlador::ModificarFechaActual(DTFecha nuevo){
    int dia=nuevo.getDia();
    int Mes=nuevo.getMes();
    int Anio=nuevo.getAnio();
    if(this->fechaActual!=NULL)
        delete this->fechaActual;
    this->fechaActual=new DTFecha(dia,Mes,Anio);
}

FechaControlador::FechaControlador(){
} 

DTFecha* FechaControlador:: getFechaActual(){
    return this->fechaActual;
}

FechaControlador::~FechaControlador(){
    delete this->fechaActual;
}