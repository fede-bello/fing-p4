#include "../include/DTReserva.h"



using namespace std;

DTReserva::DTReserva(){
    this->Codigo = 0;
    this->CheckIn = DTFecha();
    this->CheckOut = DTFecha();
    this->Estado = Abierta;
    this->Costo = 0;
    
}

DTReserva::DTReserva(int Codigo , DTFecha CheckIn, DTFecha CheckOut, EstadoReserva Estado, float Costo){
    this->Codigo = Codigo;
    this->CheckIn = CheckIn;
    this->CheckOut = CheckOut;
    this->Estado = Estado;
    this->Costo = Costo;
}

//gets

int DTReserva::getCodigo(){
    return this->Codigo;
}

DTFecha DTReserva::getCheckIn(){
    return this->CheckIn;
}

DTFecha DTReserva::getCheckOut(){
    return this->CheckOut;
}

EstadoReserva DTReserva::getEstado(){
    return this->Estado;
}

float DTReserva::getCosto(){
    return this->Costo;
}

// operator

bool DTReserva:: operator== (const DTReserva &r1) const{
    return (this->Codigo==r1.Codigo);
}

void DTReserva::imprimir(){
    cout<< "el codigo de la reserva es: ";
    cout<< this->Codigo<<endl;
    cout<< "La fecha de checkIn es: ";
    this->CheckIn.imprimir();
    cout<<endl;
    if (this->Estado==Cerrada){
        cout<< "La fecha de checkout es: ";
        this->CheckOut.imprimir(); 
        cout <<endl;
        cout<< "El estado de la reserva es: Abierta";
    }
    else {    
        cout<< "El estado de la reserva es: Cerrada";
    }    
    cout<< "El costo de la reserva es: ";
    cout<< this->Costo <<endl;
}

//Destructoras

DTReserva::~DTReserva(){
}
