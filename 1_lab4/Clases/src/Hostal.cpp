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
/*
vector<DTReserva> Hostal::darReservasHuespedHos(string email){
    vector<DTReserva> res;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        vector<DTReserva> nuevo = it->second.darReservasHuespedHab(email); // operacion de habitacion.h
        for(auto iter = nuevo.begin(); iter != nuevo.end(); iter++){
            res.push_back(iter);
        }
    }
    return res;
} */
//  for(iter = nuevo.begin(); iter != nuevo.end(); iter++){
//             res.push_back(iter);
//         }
        // while(!nuevo.empty()){// agrego los huespedes del vector a res
        //     DTReserva agregar = nuevo.begin();
        //     res.push_back(agregar);
        //     nuevo.erase(nuevo.begin());
        // }

vector<Reserva> Hostal::getReservasHostal(){
    vector<Reserva> res;
    Habitacion nuevo;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        nuevo = it->second;
        map<int, Reserva>::iterator iter;
        for(iter = nuevo.getReservas().begin(); iter != nuevo.getReservas().end(); iter++){
            Reserva nuevo = iter->second;
            res.push_back(nuevo);
        }
    }
    return res;
}

vector<DTHabitacion> Hostal::darInfoHabs(){
    vector<DTHabitacion> res;
    Habitacion nuevo;
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        nuevo = it->second;
        res.push_back(DTHabitacion(nuevo.getNum(), nuevo.getCap(), nuevo.getPrecio()));
    }
    return res;
}


int Hostal::darNumHab(int nr){
    map<int, Habitacion>::iterator it;
    int res = 0;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.buscarReserva(nr)){
            res = it->second.getNum();
            break;
        }
    }
    return res;
}

/*DTHuesped Hostal::huespedes(int nr){
    map<int, Habitacion>::iterator it;
    DTHuesped hues = DTHuesped();
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.buscarReserva(nr)){//operaciones de habitacion.h
            hues =  it->second.obtenerHuesprResHab(nr);
            break;
        }
    }
    return hues;
}*/

DTHabitacion Hostal::infoHab(int cres){
    map<int, Habitacion>::iterator it;
    DTHabitacion res = DTHabitacion();
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.buscarReserva(cres)){
            res = DTHabitacion(it->second.getNum(), it->second.getCap(), it->second.getPrecio());
            break;
        }
    }
    return res;
}

void Hostal::eliminarLinkReserva(int cres){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.buscarReserva(cres)){
            it->second.eliminarLinkRes(cres);// operacion de habitaciones.h
            break;
        }
    }
}

void Hostal::AsociarReservaHostal(Reserva r,int habitacion){
    map<int, Habitacion>::iterator it;
    for(it = mapaHabitaciones.begin(); it != mapaHabitaciones.end(); it++){
        if(it->second.getNum() == habitacion){
            it->second.setReserva(r);//operacion de habitaicon.h
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
