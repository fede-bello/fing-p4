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
   /* DTFecha *deafault;
    if(!this->CheckOut.operator==(default)){
        DTEstadia res=DTEstadia(this->identificador, this->CheckIn);
        return res;
    } ERROR DE COPILACION AL LLAMAR AL OPERATOR== DE THIS->CHECKOUT*/
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
    bool res = false;
    
    if(this->getIdentificador() == codigo){
        res = true;
    }else{
        res = false;
    }

    return res;
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
    bool res = false;

    if(this->getIdentificador() == identificador){
        res = false;
    }

    return res;
}

DTHuesped Estadia::huesEs(){
    Huesped * huespedEstadia = this->getHuesped();

    DTHuesped DTa_devolver = huespedEstadia->getDTHuesped();

    return DTa_devolver;
}

DTCalificacion Estadia::calificacionEstadia(){
    Calificacion * calificacionEstadia = this->getCalificacion();

    DTCalificacion DTa_devolver = calificacionEstadia->getDTCalificacion();

    return DTa_devolver;
}

void Estadia::calificarEst(Huesped* hues, int calif, string texto){
    Calificacion *a_calificar = new Calificacion();

    a_calificar->setHuesped(hues);
    a_calificar->setNumero(calif);
    a_calificar->setComentario(texto);

    this->setCalificacion(a_calificar);

}

Estadia::~Estadia(){
    
}

