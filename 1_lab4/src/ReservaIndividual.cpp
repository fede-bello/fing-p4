#include"../include/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual():Reserva(){
    this->pagado=false;
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad,bool pagado):Reserva(codigo, checkIn, checkOut, estado, cantidad){
    this->pagado=pagado;

}

//Destructora ReservaIndividual

ReservaIndividual::~ReservaIndividual(){
}

//gets Reserva Individual

bool ReservaIndividual::getPagado(){
    return this->pagado;
}

//sets

void ReservaIndividual::setPagado(bool pagado){
    this->pagado = pagado;
}


//Constructor para reservaGrupal
