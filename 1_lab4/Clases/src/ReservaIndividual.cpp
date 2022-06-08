#include"../include/ReservaIndividual.h"
#include"Reserva.cpp"

ReservaIndividual::ReservaIndividual():Reserva(){
    
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado):Reserva(codigo, checkIn, checkOut, estado){

}

//Destructora ReservaIndividual

ReservaIndividual::~ReservaIndividual(){
}
