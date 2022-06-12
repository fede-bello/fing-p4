#include"../include/controladorReserva.h"

controladorReserva * controladorReserva::instancia = NULL;

controladorReserva * controladorReserva::getInstance() {
    if (instancia == NULL)
        instancia = new controladorReserva();
    return instancia;
}

controladorReserva::controladorReserva(){
    this->ReservaGuardada=NULL;
} 

void controladorReserva::liberar(){
    if(ReservaGuardada!=NULL) delete ReservaGuardada;
}

controladorReserva::~controladorReserva(){
        for (auto &it:MapaReserva){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Reserva
        //it.first es la clave de MapaReserva
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<int,Reserva> MapaReserva
        //const es para no repetir el valor
        const int &nombreReserva=it.first;//
        Reserva &Reserva=it.second;
        Reserva.~Reserva();
    }
    MapaReserva.clear();
}