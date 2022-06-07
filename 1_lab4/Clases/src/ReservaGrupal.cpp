#include"../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal():Reserva(){
    this->huespedes = new Huesped*[MAX_HUESPEDES];
    int i = 0;

    while(i < MAX_HUESPEDES){
        this->huespedes[i] = NULL;
        i++;
    }

}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int cantidad,Huesped **Arreglo):Reserva(codigo, checkIn, checkOut, estado, cantidad){
    
    this->huespedes = Arreglo;

}

int Reserva::getCantidad(){
    return this->Cantidad;
}

void Reserva::setCantidad(int cantidad){
    this->Cantidad = cantidad;
}

ReservaGrupal::~ReservaGrupal(){
}

Huesped** ReservaGrupal::getHuespedes(){
    return this->huespedes;
}

void ReservaGrupal::setHuespedes(Huesped** arreglo_huespedes){
    this->huespedes = arreglo_huespedes;
}

float ReservaGrupal::calcularCosto(){
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
}

