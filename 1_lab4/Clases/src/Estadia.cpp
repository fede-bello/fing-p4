#include "../include/Estadia.h"

Estadia::Estadia(){
    this->CheckIn=DTFecha();
    this->identificador=0;
    this->CheckOut=DTFecha();
    this->calif=NULL;
}
Estadia::Estadia(int identificador,DTFecha CheckIn,DTFecha CheckOut){
    this->identificador=identificador;
    this->CheckIn=CheckIn;
    this->CheckOut=CheckOut;
    this->calif=NULL;
}

int Estadia::getIdentificador(){
    return this->identificador;
}

DTFecha Estadia::getCheckIn(){
    return this->CheckIn;
}
DTFecha Estadia::getCheckOut(){
    return this->CheckOut;
}

Calificacion* Estadia::getCalificacion(){
    return this->calif;
}

DTEstadia Estadia::getDTEstadia(){
    return DTEstadia(this->identificador, this->CheckIn,this->CheckOut);
}

Huesped* Estadia::getHuesped(){
    return this->hues;
}

void Estadia::setIdentificador(int identificador){
    this->identificador = identificador;
}

void Estadia::setCheckIn(DTFecha checkIn){
    this->CheckIn = checkIn;
}

void Estadia::setCheckOut(DTFecha checkOut){
    this->CheckOut = checkOut;
}

 void Estadia::setCalificacion(Calificacion *calif){
     this->calif = calif;
 }

void Estadia::setHuesped(Huesped *huesped){
    this->hues = huesped;    
}

float Estadia::calcularPuntajeEstadia(){
    return this->calif->getNumero();
}

DTCalificacion Estadia::darCalificacionesEstadia(){ //Devuelve las calificaciones con respusta
    return this->calif->getDTCalificacion();
}

bool Estadia::estadiaActiva(){
    DTFecha checkoutEstadia = this->getCheckOut();
    DTFecha checkinEstadia = this->getCheckIn();
    controladorFecha * controladorDeFecha = controladorDeFecha->getInstance();
    DTFecha fechaActual = controladorDeFecha->getFechaActual();
    bool res = false;
    DTFecha a_comparar = DTFecha(); //Si la fecha de checkout es distinta a la fecha definida en la constructora DTFecha es porque le cargaron una fecha de checkout (que se hace al finalizar la estadia)
    if((checkinEstadia < fechaActual) && !(checkoutEstadia == a_comparar)){ //acá tengo que ver si la fecha de checkIn es menor a fechaActual y si todavía no tiene checkOut la estadía
        res = true;
    }
    return res;
}

bool Estadia::mismoCodigo(int codigo){
    return (this->getIdentificador() == codigo);
}


bool Estadia::estaFinalizadaEstadia(){
    bool res = false;
    controladorFecha * controladorDeFecha = controladorDeFecha->getInstance();
    DTFecha fechaActual = controladorDeFecha->getFechaActual();
    DTFecha checkinEstadia = this->getCheckIn();
    if((checkinEstadia < fechaActual) && !(this->estadiaActiva())){ //Si la fecha de checkin es anterior y la estadia no esta mas activa es porque está finalizada.
        res = true;
    }
    return res;
}

void Estadia::registrarRespuesta(string respuesta, int codigoCalif){
    if(this->calif->esCalificacion(codigoCalif)){
        this->calif->setRespuesta(respuesta);
    }
}

bool Estadia::mismaEstadia(int identificador){
    return (this->getIdentificador() == identificador);
}

DTHuesped Estadia::huesEs(){
    return this->hues->getDTHuesped();
}

DTCalificacion Estadia::calificacionEstadia(){
    return this->calif->getDTCalificacion();
}


void Estadia::calificarEst(Huesped* hues, int calif, string texto){
    Calificacion *a_calificar = new Calificacion();
    a_calificar->asociarHuesped(hues);
    a_calificar->setNumero(calif);
    a_calificar->setComentario(texto);
    this->setCalificacion(a_calificar);
}

DTEstadia Estadia::EstadiaResFin(string mail){
    DTEstadia res;
    if(this->hues->mismoMail(mail)){
        res = getDTEstadia();
    }
    return res;
}

DTCalificacion Estadia::CalifSinRes(){
    DTCalificacion res;
    if(this->calif->estaSinResponderCal()){
        res = this->calif->getDTCalificacion();
    }
    return res;
}

Estadia::~Estadia(){
    
}

