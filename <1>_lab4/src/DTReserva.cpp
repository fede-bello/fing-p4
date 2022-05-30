#include "../include/DTReserva.h"
#include "../include/DTReservaIndividual.h"
#include "../include/DTReservaGrupal.h"

using namespace std;

DTReserva::DTReserva(){
    this->cantidad=0;
    this->habitacion = 0;
    this->checkIn = DTFecha();
    this->checkOut = DTFecha();
    this->estado = Abierta;
    this->costo = 0;
    this->codigo = 0;
}

DTReserva::DTReserva(int habitacion , DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo , int codigo, int cantidad){
    this->habitacion = habitacion;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
    this->codigo = codigo;
    this->cantidad=cantidad;
}

//Destructoras

DTReserva::~DTReserva(){
}

//gets

int DTReserva::getCodigo(){
    return this->codigo;
}

DTFecha DTReserva::getCheckIn(){
    return this->checkIn;
}

DTFecha DTReserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva DTReserva::getEstado(){
    return this->estado;
}

float DTReserva::getCosto(){
    return this->costo;
}

int DTReserva::getHabitacion(){
    return this->habitacion;
}

int DTReserva::getCantidad(){
    return this->cantidad;
}

// operator
bool DTReserva:: operator== (const DTReserva &r1) const{
    return (this->codigo==r1.codigo);
}
