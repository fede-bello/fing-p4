#include "../include/DTReservaIndividual.h"



DTReservaIndividual:: DTReservaIndividual():DTReserva(){   
}

DTReservaIndividual::DTReservaIndividual(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float Costo):DTReserva(Codigo, CheckIn, CheckOut, Estado, Costo){

}

//Destructora DTReserva Individual

DTReservaIndividual :: ~DTReservaIndividual(){

}
