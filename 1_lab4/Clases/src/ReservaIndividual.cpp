#include"../include/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual():Reserva(){
    
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float Costo):Reserva(codigo, checkIn, checkOut, estado, Costo){

}

//Destructora ReservaIndividual

ReservaIndividual::~ReservaIndividual(){
}
