#include "../include/DTReservaGrupal.h"
#include "DTReserva.cpp"



DTReservaGrupal::DTReservaGrupal():DTReserva(){

}

DTReservaGrupal::DTReservaGrupal(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float Costo, int Cantidad):DTReserva(Codigo, CheckIn, CheckOut, Estado, Costo){
    this->Cantidad=0;
}
//Destructora DTReservaGrupal

DTReservaGrupal::~DTReservaGrupal(){
}

//get DTReserva Grupal




/*  ESTO DE ACA ES SOLO SI VAN LAS ASOCIACIONES 

DTReservaGrupal::DTReservaGrupal():DTReserva(){
    this->huespedes = new DTHuesped*[MAX_HUESPEDES];
    int i = 0;
    while(i < (MAX_HUESPEDES)){
        this->huespedes[i] = NULL;
        i++;
    }
}



DTHuesped** DTReservaGrupal::getHuespedes(){
    return this->huespedes;
}

*/ 