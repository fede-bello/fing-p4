#include "../include/DTReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal():DTReserva(){
    this->huespedes = new DTHuesped*[MAX_HUESPEDES];
    int i = 0;
    while(i < (MAX_HUESPEDES)){
        this->huespedes[i] = NULL;
        i++;
    }
}

DTReservaGrupal::DTReservaGrupal(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad,DTHuesped **Arreglo):DTReserva( habitacion ,  checkIn,  checkOut,  estado,  costo ,  codigo, cantidad){

    this->huespedes = Arreglo;
}

//Destructora DTReservaGrupal

DTReservaGrupal::~DTReservaGrupal(){
}

//get DTReserva Grupal

DTHuesped** DTReservaGrupal::getHuespedes(){
    return this->huespedes;
}