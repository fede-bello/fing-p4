
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

void Habitacion::setReserva(map<int, Reserva*> mapaReservas){
    this->mapaReservas = mapaReservas;
}

map<int, Reserva*> Habitacion::getReservas(){
    return mapaReservas;
}

bool Habitacion::habitacionLibre(DTFecha In,DTFecha Out){
    map<int, Reserva*>::iterator it;
    it = mapaReservas.begin();
    bool libre = true;
    while(it != mapaReservas.end() && libre){
        Reserva *r = it->second; 
        if(r->reservaDisponibleEntre(In, Out)){
            it++;
        } else{
            libre = false;
        }
    }
    return libre;
}

DTHabitacion Habitacion::getDTHabitacion(){
    DTHabitacion res = DTHabitacion(this->Numero, this->Capacidad, this->Precio);
    return res;
}

vector<DTReserva> Habitacion::darReservasHuespedHab(string email){
    vector<DTReserva> res;
    map<int, Reserva*>::iterator it; 
    EstadoReserva a = cancelada;
    for(it = mapaReservas.begin(); it != mapaReservas.end(); it++){
        Reserva *r = it->second;
        if(r->getEstado() != a && r->mismoHuesped(email)){
            res.push_back(r->getDTReserva());
        }
    }
    return res;
}

vector<DTReserva> Habitacion::darReservasHabitacion(){
    vector<DTReserva> res;
    map<int, Reserva*>::iterator it;
    for(it = mapaReservas.begin(); it != mapaReservas.end(); it++){
        Reserva *r = it->second;
        DTReserva nuevo = r->getDTReserva();
        res.push_back(nuevo);
    }
    return res;
}

bool Habitacion::mismoNumero(int nr){
    return (mapaReservas.find(nr) != mapaReservas.end());
}


vector<DTHuesped> Habitacion::obtenerHuesprResHab(int nr){ 
    map<int, Reserva*>::iterator it;
    vector<DTHuesped> res;
    it = mapaReservas.find(nr);
    Reserva *r = it->second;
    if(r->esGrupalReserva()){
        res = r->obtenerHuespedesReserva();
    }
    return res;
}

bool Habitacion::buscarReserva(int cres){
    map<int, Reserva*>::iterator it; 
    it = mapaReservas.begin();
    bool encontre = false;
    while(it != mapaReservas.end() && !encontre){
        Reserva *r = it->second;
        if(r->mismaReserva(cres)){
            encontre = true;
        } else{
            it++;
        }
    }
    return encontre;
}

void Habitacion::eliminarLinkRes(int cres){
    mapaReservas.erase(cres);
}

void Habitacion::AsociarReservaHabitacion(Reserva *r){
   this->mapaReservas[r->getCodigo()]=r;
}

Habitacion::~Habitacion(){
    map<int, Reserva*>::iterator it;
    for(it = mapaReservas.begin(); it != mapaReservas.end(); it++){
        it->second->~Reserva();  //llamo al destructor de habitacion
    }
}
