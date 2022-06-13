
#include "../include/Habitacion.h"

Habitacion:: Habitacion(){

}

Habitacion:: Habitacion(int numero, int capacidad,float precio){
    this->Numero=numero;
    this->Capacidad=capacidad;
    this->Precio=precio;
}

int Habitacion::getNum(){
        return this->Numero;
 }

int Habitacion::getCap(){
    return this->Capacidad;
}

float Habitacion::getPrecio(){
        return this->Precio;
}

void Habitacion::setNum(int numero){
    this->Numero=numero;
}

void Habitacion::setCap(int capacidad){
    this->Capacidad=capacidad;
}

void Habitacion::setPrecio(float precio){
    this->Precio=precio;
}

void Habitacion::setReserva(Reserva res){
    this->mapaReservas.insert(pair<int, Reserva>(res.getCodigo(), res));
}


map<int, Reserva> Habitacion::getReservas(){
    return this->mapaReservas;
}

bool Habitacion::habitacionLibre(DTFecha In,DTFecha Out){
    map<int, Reserva>::iterator it;
    it = mapaReservas.begin();
    bool libre = true;
    while(it != mapaReservas.end()  && libre){ 
        if((it->second.getCheckIn().operator<(Out) &&  it->second.getCheckIn().operator>(In)) || (it->second.getCheckOut().operator>(In))){
            libre = false;
        } else{
            it++;
        }
    }
    return libre;
}

DTHabitacion Habitacion::getDTHabitacion(){
    DTHabitacion res = DTHabitacion(this->Numero, this->Capacidad, this->Precio);
    return res;
}
/*
vector<DTReserva> Habitacion::darReservasHuespedHab(string email){
    vector<DTReserva> res;
    map<int, Reserva>::iterator it; 
    EstadoReserva a = cancelada;
    for(it = mapaReservas.begin(); it != mapaReservas.end(); ++it){
        if(it->second.getEstado() != a && it->second.getHuesped().getNombre() == email){
            Reserva *nuevo = it->second;
            res.push_back(DTReserva(nuevo.getCodigo(), nuevo.getCheckIn(), nuevo.getCheckOut(), nuevo.getEstado()));
        }
    }
    return res;
}

bool Habitacion::mismoNumero(int nr){
    return mapaReservas.find(nr) != mapaReservas.end();
}

//mal devolver un DTHuesped
vector<DTHuesped> Habitacion::obtenerHuesprResHab(int nr){ 
    //asumo que la reserva esta asociada a esta habitacion
    map<int, Reserva>::iterator it;
    it = mapaReservas.find(nr);
    vector<DTHuesped> res;
    Huesped h = it->second.getHuesped();
    return res;
}
*/
bool Habitacion::buscarReserva(int cres){
    return mapaReservas.find(cres) != mapaReservas.end();
}

void Habitacion::eliminarLinkRes(int cres){
    mapaReservas.erase(cres);
}

Habitacion::~Habitacion(){
    for(auto &codigo:mapaReservas){
        Reserva res = codigo.second;
        res.~Reserva();
    }
}
