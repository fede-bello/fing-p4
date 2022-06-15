
#include "../include/ReservaGrupal.h"


ReservaGrupal::ReservaGrupal():Reserva(){
    map<string,Huesped*> huespedes;

}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad):Reserva(codigo, checkIn, checkOut, estado){
    
    this->Cantidad=cantidad;

}

int ReservaGrupal::getCantidad(){
    return this->Cantidad;
}

void ReservaGrupal::setCantidad(int cantidad){
    this->Cantidad = cantidad;
}

ReservaGrupal::~ReservaGrupal(){
}

map<string,Huesped*> ReservaGrupal::getHuespedes(){
    return this->huespedes;
}

void ReservaGrupal::setHuespedes(map<string,Huesped*> huespedes){
    this->huespedes = huespedes;
}

/*float ReservaGrupal::calcularCosto(){
    float costo;

    int i = 0;
    int contador_fingers = 0;

    while((i < (this->cantidad)) && (contador_fingers < 2)){
        if(this->huespedes[i]->getEsfinger() == 1){
            contador_fingers++;
        }
        i++;
    }

    if(contador_fingers >= 2){
        Habitacion *habitacion = this->hab;
        int diasReserva = this->checkOut.diferenciasFechas(this->checkIn);

        costo = 0.7*habitacion->getPrecio() * diasReserva;
    }else{
        Habitacion *habitacion = this->hab;
        int diasReserva = this->checkOut.diferenciasFechas(this->checkIn);

        costo = habitacion->getPrecio() * diasReserva;
    }

    return costo;
}*/

