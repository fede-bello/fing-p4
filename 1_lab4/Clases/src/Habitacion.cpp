
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

map<int, Reserva> Habitacion::getReservas(){
    return this->Reservas;
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

void Habitacion::setReserva(Reserva res){
    this->Reservas.insert(pair<int, Reserva>(res.getCodigo(), res));
}


//hay que modificar cosas, falta implementar coleeciones
bool Habitacion::habitacionLibre(DTFecha In,DTFecha Out){
    /*int maxReservas = 0; //lo hago solo para que compile, representa el numero de reservas asociadas a una habitacion
    bool libre = true;
    int i = 0;
    while(i <= maxReservas && libre){ 
        if(this->res.getCheckIn() < Out || this->res.getCheckOut() > In){
            libre = false;
        }//pruebo esto para cada reserva de la habitacion
    }
    return libre;*/
    return false;
}

DTHabitacion Habitacion::getDTHabitacion(){
    DTHabitacion res=DTHabitacion(this->Numero, this->Capacidad, this->Precio);
    return res;
}

bool Habitacion:: buscarReserva(int cres){
    //return this->res.getCodigo() == cres;
    return false;
}

void Habitacion::eliminarLinkRes(int cres){
    Reservas.erase(cres);
}

Habitacion::~Habitacion(){
}