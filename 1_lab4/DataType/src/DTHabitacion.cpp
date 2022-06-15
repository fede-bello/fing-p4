
#include"../include/DTHabitacion.h"

using namespace std;


//creadoras
DTHabitacion::DTHabitacion(){
    this->Numero=0;
    this->Capacidad=0;
    this->Precio=0;
}

DTHabitacion::DTHabitacion(int Numero, int Capacidad, float Precio){
    this->Numero=Numero;
    this->Capacidad=Capacidad;
    this->Precio=Precio;
}


//gets 
int DTHabitacion::getNumero(){
        return this->Numero;
}

float DTHabitacion::getPrecio(){
        return this->Precio;
 }

int DTHabitacion::getCapacidad(){
    return this->Capacidad;
}

//Sobrecarga de operador == en habitaciones
bool DTHabitacion:: operator== (const DTHabitacion &h2) const{
    return this->Numero==h2.Numero;
}
void DTHabitacion::Imprimir(){
    cout<<"Número: "<<this->getNumero()<<endl<<"Precio: $"<<this->getPrecio()<<endl<<"Capacidad: "<<this->getCapacidad()<<endl;
}

//destructoras
DTHabitacion::~DTHabitacion(){

}


