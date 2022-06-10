
#include "../include/Habitacion.h"

Habitacion:: Habitacion(){

}

Habitacion:: Habitacion(int numero, int capacidad,float precio){
    this->Numero=numero;
    this->Capacidad=capacidad;
    this->Precio=precio;
}

int Habitacion::getNum(){
        return this->Numero;
 }

int Habitacion::getCap(){
    return this->Capacidad;
}

float Habitacion::getPrecio(){
        return this->Precio;
}

Reserva* Habitacion::getReserva(){
    return this->res;
}

void Habitacion::setNum(int numero){
    this->Numero=numero;
}

void Habitacion::setCap(int capacidad){
    this->Capacidad=capacidad;
}

void Habitacion::setPrecio(float precio){
    this->Precio=precio;
}

void Habitacion::setReserva(Reserva *res){
  this->res = res;
}


//hay que modificar cosas, falta implementar coleeciones
bool habitacionLibre(In,Out){
    int maxReservas = 0; //lo hago solo para que compile, representa el numero de reservas asociadas a una habitacion
    bool libre = true;
    int i = 0;
    while(i <= maxReservas && libre){ 
        if(this->res.getCheckIn() < Out || this->res.getCheckOut() > In){
            libre = false;
        }//pruebo esto para cada reserva de la habitacion
    }
    return libre;
}

DTHabitacion getDTHabitacion(){
    return DTHabitacion(this->Numero, this->Capacidad, this->Precio);
}

bool buscarReserva(cres){
    return this->res.getCodigo() == cres;
}

void eliminarLinkRes(){
    this->res == NULL;
}

Habitacion::~Habitacion(){
}