#include "../include/Estadia.h"
 
Estadia::Estadia(int identidicador,DTFecha CheckIn){
    this->CheckIn=CheckIn;
    this->identificador=identidicador;
    this->CheckOut=DTFecha();
    this->calificacion=NULL;
}
Estadia::Estadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut){
    this->identificador=identidicador;
    this->CheckIn=CheckIn;
    this->CheckOut=CheckOut;
    this->calificacion=NULL;
}
int Estadia::getidentificador(){
    return this->identificador;
}
DTFecha Estadia::getCheckIn(){
    return this->CheckIn;
}
DTFecha Estadia::getCheckOut(){
    return this->CheckOut;
}

Calificacion* Estadia::getCalificacion(){
    return this->calif;
}

DTEstadia Estadia::getDTEstadia(){
   /* DTFecha *deafault;
    if(!this->CheckOut.operator==(default)){
        DTEstadia res=DTEstadia(this->identificador, this->CheckIn);
        return res;
    } ERROR DE COPILACION AL LLAMAR AL OPERATOR== DE THIS->CHECKOUT*/
    return DTEstadia(this->Identificador, this->CheckIn,this->CheckOut);
}

Huesped* Reserva::getHuesped(){
    return this->hues;
}

void Estadia::setidentificador(int identificador){
    this->identificador = identificador;
}

void Estadia::setCheckIn(DTFecha checkIn){
    this->CheckIn = checkIn;
}

void Estadia::setCheckOut(DTFecha checkOut){
    this->CheckOut = checkOut;
}

 void Estadia::setCalificacion(Calificacion calif){
     this->calif = calif;
 }

void Reserva::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

Estadia::~Estadia(){
    this->calificacion->~Calificacion();

}

