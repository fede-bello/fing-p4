
#include"../include/Reserva.h"


//Constructoras Reserva

Reserva::Reserva(){
    this->checkIn = DTFecha();
    this->checkOut = DTFecha();
    this->estado = Abierta;
    this->codigo = 0;
}

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado){
    this->checkOut = checkOut;
    this->checkIn = checkIn;
    this->estado = estado;
    this->codigo = codigo;
}

//gets Reserva 

int Reserva::getCodigo(){
    return this->codigo;
}

DTFecha Reserva::getCheckIn(){
    return this->checkIn;
}

DTFecha Reserva::getCheckOut(){
    return this->checkOut;
}

map<int,Estadia*> Reserva::getEstadias(){
    return this->mapaEstadias; 
}

Huesped* Reserva::getHuesped(){
    return this->hues;
}

EstadoReserva Reserva::getEstado(){
    return this->estado;
}

float Reserva::getCosto(){
    return this->costo;
}

//sets Reserva 

void Reserva::setCodigo(int codigo){
    this->codigo = codigo;
}

void Reserva::setCheckIn(DTFecha checkIn){
    this->checkIn = checkIn;
} 

void Reserva::setCheckOut(DTFecha checkOut){
    this->checkOut = checkOut;
}

void Reserva::setEstado(EstadoReserva estado){
    this->estado = estado;
}

void Reserva::setEstadia(map<int,Estadia*> mapaEstadias){
    this->mapaEstadias=mapaEstadias;
}

void Reserva::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

//Destructora

Reserva::~Reserva(){
    map<int, Estadia*>::iterator it;
    for(it = mapaEstadias.begin(); it != mapaEstadias.end(); it++){
        it->second->~Estadia();  //llamo al destructor de habitacion
    }
}

//Calcular Costo
// float Reserva::calcularCosto(){
//     float costo;
//     Habitacion *habitacion = this->hab;
//     int diasReserva = this->checkOut.diferenciasFechas(this->checkIn);

//     costo = habitacion->getPrecio() * diasReserva;

//     return costo;
// }


bool Reserva::reservaDisponibleEntre(DTFecha In, DTFecha Out){
    bool res = false;
    if ((this->checkIn > Out) || (this->checkOut < In)){
        res = true;
    }
    return true;
}

float Reserva::calcularPromedioReserva(){
    float suma = 0;
    int i = 0; //cuenta la cantidad de calificaciones que tiene la reserva
    map<int,Estadia*>::iterator it =this-> mapaEstadias.begin();
    while (it != mapaEstadias.end()){
        Estadia *est = it->second;
        suma = suma + est->calcularPuntajeEstadia();
        i++;
        ++it;
        }
    if (i!=0){
        return suma/i; //Devuelvo el promedio
    }
    else {
        return 0; //Devuelvo 0 si no tiene calificaciones asociadas
    }
}

vector<DTCalificacion> Reserva::darCalificacionesReserva(){
    map<int,Estadia*>::iterator it=this->mapaEstadias.begin();
    vector<DTCalificacion> calificaciones;
    while (it!=mapaEstadias.end()){
        Estadia *est=it->second;
        DTCalificacion calificacion=est->darCalificacionesEstadia();
        calificaciones.push_back(calificacion);
        ++it; //Aumenta una posicion el iterador
        }
    return calificaciones;    
}

bool Reserva::mismoHuesped(string email){
    return (this->hues->getMail() == email);

}

DTReserva Reserva::getDTReserva(){
    return DTReserva(this->codigo, this->checkIn, this->checkOut, this->estado,this->costo);
}

DTEstadia Reserva::crearEstadiaNueva(DTFecha f){
    Estadia nueva = Estadia(0, f, DTFecha());// ver tema de que identificador poner
    Estadia* res = &nueva;
    this->mapaEstadias[res->getIdentificador()]= res;
    

    //ACA HABRIA QUE CREAR UNA NUEVA ESTADIA PERO NO SE MUY BIEN COMO HACER 
    //CON EL TEMA DEL IDENTIFICADO, NO PUEDE SER IGUAL AL CODIGO PORQUE UNA 
    //RESERVA PUEDE TENER MAS DE UNA ESTADIA ASOCIADA)
    return DTEstadia();
}
void Reserva::cerrarEstadoReserva(){
    this->estado=Cerrada;
}

vector<DTEstadia> Reserva::estadiasActivas(){
    map<int,Estadia*>::iterator it;
    vector<DTEstadia> estAc;
    for(it = mapaEstadias.begin(); it != mapaEstadias.begin(); it++){
        Estadia *est = it->second;
        if (est->estadiaActiva()){
            DTEstadia dtest = est->getDTEstadia();
            estAc.push_back(dtest);
        }
    }
    return estAc;
}

DTEstadia Reserva::mismaEstadia(int codigo){
    map<int,Estadia*>::iterator it;
    DTEstadia est = DTEstadia();
    for(it = mapaEstadias.begin(); it != mapaEstadias.begin(); it++){
        if (it->second->getIdentificador() ==codigo){
            est = it->second->getDTEstadia();
        }
    }
    return est;
}



void Reserva::actualizarCheckOut(DTFecha co,int codigo){
    map<int,Estadia*>::iterator it;
    for (it=mapaEstadias.begin(); it!=mapaEstadias.end(); ++it){
        Estadia *e=it->second;
        if (e->mismoCodigo(codigo)){
            e->setCheckOut(co);
        }
    }
}

vector<DTEstadia> Reserva::EstadiasFin(string mail){
    vector<DTEstadia> res;
    return res;
}

/*
vector<DTEstadia> Reserva::EstadiasFin(string mail){
    vector<DTEstadia> est;
    map<int,Estadia*>::iterator it;
    for(it = mapaEstadias.begin(); it != mapaEstadias.begin(); it++){
        Estadia *est=it->second;
        if(estaFinalizadaEstadia()){
            // crear una nueva operacion en estadia con otro nombre que no sea getDTEstadia, mirar diagrama de getEstadias para entender a que me refiero 
        }
    }



    vector<DTEstadia> estadias;
    map<int,Estadia*>::iterator it=this->mapaEstadias.begin();
    while (it!=mapaEstadias.end()){
        Estadia *est=it->second;
        Huesped *hues=est->getHuesped();
        if ((est->estaFinalizadaEstadia()) && (hues->getMail()==mail)){ //la agrego si esta finalizada y asociada a mail
            DTEstadia dtest=est->getDTEstadia();
            estadias.push_back(dtest);
        }
        ++it; //Aumenta una posicion el iterador
        }
    return estadias;

}*/

/*
vector<DTCalificacion> Reserva::getCalifSinResReserva(){
// crear una nueva operacion en estadia con otro nombre que no sea getDTEstadia, mirar diagrama de getEstadias para entender a que me refiero 


    map<int,Estadia*>::iterator it=this->mapaEstadias.begin();
    vector<DTCalificacion> calificaciones;
    while (it!=mapaEstadias.end()){
        Estadia *est=it->second;
        DTCalificacion calificacion=est->getCalifSinResEstadia();
        calificaciones.push_back(calificacion);
        ++it; //Aumenta una posicion el iterador
        
    }
    return calificaciones;
}
*/

/*
void Reserva::buscarCalificacion(string respuesta, int codigoCalif){

}
*/

//NO IMPLENTADA, PUSE ESO PARA QUE COMPILE ALGO DE HOSTAL (DANILO)
bool Reserva::esGrupalReserva(){
    return true;
}

vector<DTHuesped> Reserva::obtenerHuespedesReserva(){
    vector<DTHuesped> vec;
    return vec;
}
/*
vector<DTEstadia> Reserva::estadiasReserva(){

}*/

DTHuesped Reserva::esHuesped(){
    return this->hues->getDTHuesped();
}

int Reserva::esReserva(){
    return this->codigo;
}

bool Reserva::mismaReserva(int cres){
    return (this->codigo == cres);
}

/*
DTCalificacion Reserva::calificacionBuscada(int codigo){
    DTCalificacion res;
    map<int,Estadia*>::iterator it;
    for(it = mapaEstadias.begin(); it != mapaEstadias.end(); it++){
        if(it->second.mismaEstadia(codigo)){
            res = it->second.calificacionEstadia();
            break;
        }
    }
    return res;
}
*/

/*
DTReserva Reserva::reservaBuscada(int codigo){

}

void Reserva::eliminarLinksHuesEst(){}
*/

void Reserva::calificarEstadiaReserva(int codigo, int calif, string texto, Huesped *hues){

}
