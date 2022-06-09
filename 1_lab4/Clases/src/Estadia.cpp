#include "../include/Estadia.h"
#include"../../DataType/src/DTFecha.cpp"
 
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
    ControladorFecha * controladorFecha = new ControladorFecha->getInstance(); //no logro que haga bien la asociacion con el .h...
    DTFecha* fechaActual = controladorFecha->getFechaActual();
    bool res = false;

    DTFecha a_comparar = DTFecha(); //Si la fecha de checkout es distinta a la fecha definida en la constructora DTFecha es porque le cargaron una fecha de checkout (que se hace al finalizar la estadia)

    if(checkinEstadia < !(checkoutEstadia == a_comparar)){ //acá tengo que ver si la fecha de checkIn es menor a fechaActual y si todavía no tiene checkOut la estadía
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



Estadia::~Estadia(){
    

}

