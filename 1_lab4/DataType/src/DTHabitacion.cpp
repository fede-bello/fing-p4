
#include"../include/DTHabitacion.h"
#include"../../conceptos/include/Habitacion.h"
using namespace std;


//creadoras
DTHabitacion::DTHabitacion(){
}

DTHabitacion::DTHabitacion(int numero, int capacidad, float precio){
    this->numero=numero;
    this->capacidad=capacidad;
    this->precio=precio;
}

//destructoras
DTHabitacion::~DTHabitacion(){
}


//gets 
int DTHabitacion::getNum(){
        return this->numero;
}

float DTHabitacion::getPrecio(){
        return this->precio;
 }

int DTHabitacion::getCap(){
    return this->capacidad;
}

//Sobrecarga de operador == en habitaciones
bool DTHabitacion:: operator== (const DTHabitacion &h2) const{
    return this->numero==h2.numero;
}

