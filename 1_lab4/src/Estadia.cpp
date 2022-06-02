#include "../include/Estadia.h"
 
Estadia::Estadia(int identidicador,DTFecha CheckIn){
    this->CheckIn=CheckIn;
    this->identificador=identidicador;
    this->CheckOut=DTFecha();
    this->calificacion=NULL;
}
Estadia::Estadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut){
    this->identificador=identidicador;
    this->CheckIn=CheckIn;
    this->CheckOut=CheckOut;
    this->calificacion=NULL;
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
DTEstadia Estadia::getDTEstadia(){
   /* DTFecha *deafault;
    if(!this->CheckOut.operator==(default)){
        DTEstadia res=DTEstadia(this->identificador, this->CheckIn);
        return res;
    } ERROR DE COPILACION AL LLAMAR AL OPERATOR== DE THIS->CHECKOUT*/
    return DTEstadia(this->identificador, this->CheckIn,this->CheckOut);
    
}

Estadia::~Estadia(){
    this->calificacion->~Calificacion();

}

