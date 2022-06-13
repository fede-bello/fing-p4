
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


//Destructora DTReserva
Reserva::~Reserva(){

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

map<int,Estadia> Reserva::getEstadias(){
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

void Reserva::setEstadia(map<int,Estadia> mapaEstadias){
    this->mapaEstadias=mapaEstadias;
}

void Reserva::setHuesped(Huesped *huesped){
    this->hues = huesped;    
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
    bool res=false;
    if ((this->checkIn>In) && (this->checkOut<Out)){
        res=true;
    }
    return true;
}

float Reserva::calcularPromedioReserva(){
    float res;
    //Aca hay que iterar por todas las estadias y promediar su puntaje
    //res=calcularPuntajeEstadia();
    return 0;
}

bool Reserva::mismoHuesped(string email){
    return (this->hues->getMail()==email);

}

DTReserva Reserva:: getDTReserva(){
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

/*DTEstadia mismaEstadia(int codigo){
    FEDE:FIJATE BIEN COMO USAR EL FIND, CAPAZ HAY QUE USAR DYNAMIC CAST
    Estadia est=this->mapaEstadias.find(codigo);
    return est->getDTEstadia();
}*/

void Reserva::actualizarCheckOut(DTFecha co){
    this->checkOut=co;
}

//set(DTEstadia) getEstadias();


//set(DTCalificacion) getCalifSinResReserva();


DTHuesped Reserva::esHuesped(){
    return this->hues->getDTHuesped();
}

int Reserva::esReserva(){
    return this->codigo;
}

bool Reserva::mismaReserva(int cres){
    return (this->codigo == cres);
}

//DTCalificacion Reserva::calificacionBuscada();

/*DTReserva Reserva::reservaBuscada(){

}*/

//void Reserva::eliminarLinksHuesEst(){}

//void Reserva::calificarEstadiaReserva(Huesped hues)