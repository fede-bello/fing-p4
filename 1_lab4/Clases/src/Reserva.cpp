
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
    return mapaEstadias; 
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

//Destructora DTReserva

Reserva::~Reserva(){
/*no me funciona con el puntero a estadia
    for(auto &codigo:mapaEstadias){
        Estadia est = codigo.second;
        est.~Estadia();
    }
    */
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

/*DTEstadia Reserva::crearEstadiaNueva(DTFecha f){
    //ACA HABRIA QUE CREAR UNA NUEVA ESTADIA PERO NO SE MUY BIEN COMO HACER 
    //CON EL TEMA DEL IDENTIFICADO, NO PUEDE SER IGUAL AL CODIGO PORQUE UNA 
    //RESERVA PUEDE TENER MAS DE UNA ESTADIA ASOCIADA)

}*/

void Reserva::cerrarEstadoReserva(){
    this->estado=Cerrada;
}


vector<DTEstadia> Reserva::estadiasActivas(){
    map<int,Estadia*>::iterator it=this->mapaEstadias.begin();
    vector<DTEstadia> estAc;
    while (it!=mapaEstadias.end()){
        Estadia *est=it->second;
        if (est->estadiaActiva()){
            DTEstadia dtest=est->getDTEstadia();
            estAc.push_back(dtest);
        }
        ++it; //Aumenta una posicion el iterador
        }
    return estAc;
}


DTEstadia Reserva::mismaEstadia(int codigo){//aca no se si habra que usar algun iterator
    DTEstadia est=DTEstadia();
    if (this->mapaEstadias.find(codigo)!=this->mapaEstadias.end()){
        Estadia *esta=this->mapaEstadias.find(codigo)->second;
        est=esta->getDTEstadia();
    }
    return est;
    
}



void Reserva::actualizarCheckOut(DTFecha co){
    this->checkOut=co;
}

vector<DTEstadia> Reserva::getDTEstadias(){
    vector<DTEstadia> estadias;
    map<int,Estadia*>::iterator it=this->mapaEstadias.begin();
    while (it!=mapaEstadias.end()){
        Estadia *est=it->second;
        DTEstadia dtest=est->getDTEstadia();
        estadias.push_back(dtest);
        ++it; //Aumenta una posicion el iterador
        }
    return estadias;

}/*

vector<DTCalificacion> Reserva::getCalifSinResReserva(){

}

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

void Reserva::calificarEstadiaReserva(Huesped hues){}
*/