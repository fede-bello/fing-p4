#include "../include/DTEstadia.h"


DTEstadia::DTEstadia(){
    this->CheckIn=DTFecha();
    this->CheckOut=DTFecha();
    this->identificador=0;
}

DTEstadia::DTEstadia(int identidicador, DTFecha CheckIn,DTFecha CheckOut){
    this->CheckIn=CheckIn;
    this->CheckOut=CheckOut;
    this->identificador=identidicador;    
}

DTFecha DTEstadia::getCheckIn(){
    return this->CheckIn;
}

DTFecha DTEstadia::getCheckOut(){
    return this->CheckOut;
}

int DTEstadia::getIdentificador(){
    return this->identificador;
}

DTEstadia::~DTEstadia(){

}

void DTEstadia::imprimir(){
    cout<<"CheckIn: ";
    this->CheckIn.imprimir();
    cout<<endl;
    cout<<"CheckOut: ";
    this->CheckOut.imprimir();
    cout<<endl;
    cout<<"Identificador: ";
    cout<< this->identificador<<endl;
}



