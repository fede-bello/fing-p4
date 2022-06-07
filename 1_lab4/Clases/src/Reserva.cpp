
#include"../include/Reserva.h"

//Constructoras Reserva

Reserva::Reserva(){
    this->checkIn = DTFecha();
    this->checkOut = DTFecha();
    this->estado = Abierta;
    this->codigo = 0;
    this->cantidad=0;
}

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad){
    this->checkOut = checkOut;
    this->checkIn = checkIn;
    this->estado = estado;
    this->codigo = codigo;
    this->cantidad=cantidad;
}


//Destructora DTReserva
Reserva::~Reserva(){

}

//gets Reserva 

int Reserva::getCodigo(){
    return this->codigo;
}

DTFecha Reserva::getCheckIn(){
    return this->checkIn;
}

DTFecha Reserva::getCheckOut(){
    return this->checkOut;
}

Habitacion* Reserva::getHabitacion(){
    return this->hab;
}

Huesped* Reserva::getHuesped(){
    return this->hues;
}

EstadoReserva Reserva::getEstado(){
    return this->estado;
}

//sets Reserva 

void Reserva::setCodigo(int codigo){
    this->codigo = codigo;
}

void Reserva::setCheckIn(DTFecha checkIn){
    this->checkIn = checkIn;
} 

void Reserva::setCheckOut(DTFecha checkOut){
    this->checkOut = checkOut;
}

void Reserva::setEstado(EstadoReserva estado){
    this->estado = estado;
}

void Reserva::setHabitacion(Habitacion *habitacion){
    this->hab = habitacion;
}

void Reserva::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

//Calcular Costo
float Reserva::calcularCosto(){
    float costo;
    Habitacion *habitacion = this->hab;
    int diasReserva = this->checkOut.diferenciasFechas(this->checkIn);

    costo = habitacion->getPrecio() * diasReserva;

    return costo;
}

//Constructora ReservaIndividual
