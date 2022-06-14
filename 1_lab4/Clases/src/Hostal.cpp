#include "../include/Hostal.h"

Hostal::Hostal(){
    this->Nombre='.';
    this->Direccion='.';
    this->Telefono=0;
}

Hostal::Hostal(string Nombre,string Direccion,int Telefono){
    this->Direccion=Direccion;
    this->Nombre=Nombre;
    this->Telefono=Telefono;
}

string Hostal::getNombre(){
    return this->Nombre;
}

string Hostal::getDireccion(){
    return this->Direccion;
}

int Hostal::getTelefono(){
    return this->Telefono;
}

void Hostal::setNombre(string nombre){
    this->Nombre = nombre;
}

void Hostal::setDireccion(string direccion){
    this->Direccion = direccion;
}

void Hostal::setTelefono(int telefono){
    this->Telefono = telefono;
}

void Hostal::agregarHabitacionAHostal(DTHabitacion dthab){
    Habitacion *hab=new Habitacion(dthab.getNumero(),dthab.getCapacidad(),dthab.getPrecio());
    this->mapaHabitaciones[dthab.getNumero()]=hab;

}

//Operaciones
DTHostal Hostal::getDTHostal(){
    DTHostal res = DTHostal(this->Nombre,this->Direccion,this->Telefono);
    return res;
}

vector<DTReserva> Hostal::darReservasHuespedHos(string email){
    vector<DTReserva> res;
    map<int, Habitacion*>::iterator it;
    for(it = this->mapaHabitaciones.begin(); it != this->mapaHabitaciones.end(); ++it){
        vector<DTReserva> a = it->second->darReservasHuespedHab(email);
        vector<DTReserva>::iterator iter;
        for(iter = a.begin(); iter != a.end(); iter++){
            res.push_back(*iter);
        }
    }
    return res;
}
/*
vector<Reserva> Hostal::getReservasHostal(){
    vector<Reserva> res;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        map<int, Reserva*> nuevo = it->second.getReservas(); 
        map<int, Reserva*>::iterator iter;
        for(iter = nuevo.begin(); iter != nuevo.end(); iter++){
            res.push_back(iter->second);
        }
    }
    return res;
}*/

vector<DTHabitacion> Hostal::darInfoHabs(){
    vector<DTHabitacion> res;
    map<int, Habitacion*>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        res.push_back(it->second->getDTHabitacion());
    }
    return res;
}

int Hostal::darNumHab(int nr){
    map<int, Habitacion*>::iterator it;
    int res;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second->mismoNumero(nr)){
            res = it->second->getNum();
            break;
        }
    }
    return res;
}

vector<DTHuesped> Hostal::huespedes(int nr){
    map<int, Habitacion*>::iterator it;
    vector<DTHuesped> hues;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second->buscarReserva(nr)){
            hues = it->second->obtenerHuesprResHab(nr);
        }
    }
    return hues;
}

DTHabitacion Hostal::infoHab(int cres){
    map<int, Habitacion*>::iterator it;
    DTHabitacion res = DTHabitacion();
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second->buscarReserva(cres)){
            res = it->second->getDTHabitacion();
            break;
        }
    }
    return res;
}

void Hostal::eliminarLinkReserva(int cres){
    map<int, Habitacion*>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second->buscarReserva(cres)){
            it->second->eliminarLinkRes(cres);// operacion de habitaciones.h
            break;
        }
    }
}
/*
void Hostal::AsociarReservaHostal(Reserva r,int habitacion){
    map<int, Habitacion*>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.getNum() == habitacion){
            map<int, Reserva*> res = it->second.getReservas();
            res[r.getCodigo()] = r;
            it->second.setReserva(res);//operacion de habitaicon.h
            break;
        }
    }
}*/

//Destructora
Hostal::~Hostal(){
    map<int, Habitacion*>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        it->second->~Habitacion();
    }
}
