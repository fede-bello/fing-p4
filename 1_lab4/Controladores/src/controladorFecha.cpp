

#include "../include/controladorFecha.h"



controladorFecha * controladorFecha::instancia = NULL;

controladorFecha * controladorFecha::getInstance() {
    if (instancia == NULL)
        instancia = new controladorFecha();
    return instancia;
}


void controladorFecha::ModificarFechaActual(DTFecha nuevo){
    int dia=nuevo.getDia();
    int Mes=nuevo.getMes();
    int Anio=nuevo.getAnio();
    int Hora = nuevo.getHora();
    
    this->fechaActual =DTFecha(dia,Mes,Anio, Hora);
}

controladorFecha::controladorFecha(){
} 

DTFecha controladorFecha:: getFechaActual(){
    return this->fechaActual;
}

controladorFecha::~controladorFecha(){
}