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
    Habitacion hab=Habitacion(dthab.getNumero(),dthab.getCapacidad(),dthab.getPrecio());
    this->mapaHabitaciones.insert(pair<int, Habitacion>(dthab.getNumero(), hab));

}

//Operaciones
DTHostal Hostal::getDTHostal(){
    DTHostal res = DTHostal(this->Nombre,this->Direccion,this->Telefono);
    return res;
}

DTReserva Hostal::darReservasHuespedHos(){

}

vector<Reserva> Hostal::getReservasHostal(){
    vector<Reserva> res;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        Habitacion *nuevo = it->second;
        map<int, Reserva>::iterator iter;
        for(iter = nuevo.mapaReservas.begin(); iter != nuevo.mapaReservas.end(); ++iter){
            // poner cada elemento de las reservas en el vector reservas
        }
    }
}

vector<DTHabitacion> Hostal::darInfoHabs(){
    vector<DTHabitacion> res;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        Habitacion *nuevo = it->second;
        res.push_back(DTHabitacion(nuevo.getNum(), nuevo.getCap(), nuevo.getPrecio()));
    }
    return res;
}


int Hostal::darNumHab(Reserva nr){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        if(it->second.buscarReserva(nr)){
            int res = it->second.getNum();
            break;
        }
    }
    return res;
}

DTHuesped Hostal::huespedes(Reserva nr){

}

DTHabitacion Hostal::infoHab(int cres){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        if(it->second.buscarReserva(nr)){
            DTHabitacion res = DTHabitacion(it->second.getNum(), it->second.getCap(), it->second.getPrecio());
            break;
        }
    }
    return res;
}

void Hostal::eliminarLinkReserva(int cres){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        if(it->second.buscarReserva(nr)){
            it->second.eliminarLinkRes(cres);// operacion de habitaciones.h
            break;
        }
    }
}

void Hostal::AsociarReservaHostal(int r,int habitacion){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); ++it){
        if(it->second.getNum() == habitacion){
            setReserva(r);//operacion de habitaicon.h
            break;
        }
    }
}

//Destructora
Hostal::~Hostal(){
    for(auto &codigo:mapaHabitaciones){
        Habitacion hab = codigo.second;
        hab.~Habitacion();
    }
}
