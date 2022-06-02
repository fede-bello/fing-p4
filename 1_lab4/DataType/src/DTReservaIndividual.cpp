#include "../include/DTReservaIndividual.h"

DTReservaIndividual:: DTReservaIndividual():DTReserva(){
    this->pagado=false;
}

DTReservaIndividual:: DTReservaIndividual(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad,bool pagado):DTReserva( habitacion ,  checkIn,  checkOut,  estado,  costo ,  codigo, cantidad){
    this->pagado=pagado;
}

//Destructora DTReserva Individual

DTReservaIndividual :: ~DTReservaIndividual(){

}

bool DTReservaIndividual::getPagado(){
    return this->pagado;
}