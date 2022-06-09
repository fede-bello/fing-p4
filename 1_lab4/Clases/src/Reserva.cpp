
#include"../include/Reserva.h"


//Constructoras Reserva

Reserva::Reserva(){
    this->checkIn = DTFecha();
    this->checkOut = DTFecha();
    this->estado = Abierta;
    this->codigo = 0;
}

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado){
    this->checkOut = checkOut;
    this->checkIn = checkIn;
    this->estado = estado;
    this->codigo = codigo;
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

Estadia* Reserva::getEstadia(){
    return this->est;
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

void Reserva::setEstadia(Estadia *estadia){
    this->est = estadia;
}

void Reserva::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

//Calcular Costo
// float Reserva::calcularCosto(){
//     float costo;
//     Habitacion *habitacion = this->hab;
//     int diasReserva = this->checkOut.diferenciasFechas(this->checkIn);

//     costo = habitacion->getPrecio() * diasReserva;

//     return costo;
// }

