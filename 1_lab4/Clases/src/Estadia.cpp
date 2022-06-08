#include "../include/Estadia.h"
#include"../../DataType/src/DTFecha.cpp"
 
Estadia::Estadia(){
    this->CheckIn=DTFecha();
    this->identificador=0;
    this->CheckOut=DTFecha();
    this->calif=NULL;
}
Estadia::Estadia(int identificador,DTFecha CheckIn,DTFecha CheckOut){
    this->identificador=identificador;
    this->CheckIn=CheckIn;
    this->CheckOut=CheckOut;
    this->calif=NULL;
}
int Estadia::getIdentificador(){
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
    return DTEstadia(this->identificador, this->CheckIn,this->CheckOut);
}

Huesped* Estadia::getHuesped(){
    return this->hues;
}

void Estadia::setIdentificador(int identificador){
    this->identificador = identificador;
}

void Estadia::setCheckIn(DTFecha checkIn){
    this->CheckIn = checkIn;
}

void Estadia::setCheckOut(DTFecha checkOut){
    this->CheckOut = checkOut;
}

 void Estadia::setCalificacion(Calificacion *calif){
     this->calif = calif;
 }

void Estadia::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

Estadia::~Estadia(){
    

}

