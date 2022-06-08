
#include "../include/Habitacion.h"

Habitacion:: Habitacion(){

}

Habitacion:: Habitacion(int numero, int capacidad,float precio){
    this->numero=numero;
    this->capacidad=capacidad;
    this->precio=precio;
}

int Habitacion::getNum(){
        return this->numero;
 }

int Habitacion::getCap(){
    return this->capacidad;
}

float Habitacion::getPrecio(){
        return this->precio;
}

Reserva* Habitacion::getReserva(){
    return this->res;
}

void Habitacion::setNum(int numero){
    this->numero=numero;
}

void Habitacion::setCap(int capacidad){
    this->capacidad=capacidad;
}

void Habitacion::setPrecio(float precio){
    this->precio=precio;
}

  void Habitacion::setReserva(Reserva *res){
      this->res = res;
  }

Habitacion::~Habitacion(){
}