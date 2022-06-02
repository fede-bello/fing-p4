#include "../include/DTEstadia.h"


  
DTEstadia::DTEstadia(int identidicador,DTFecha CheckIn){
    this->CheckIn=CheckIn;
    this->identificador=identidicador;
}
DTEstadia::DTEstadia(int identidicador,DTFecha CheckIn,DTFecha CheckOut){
    this->CheckIn=CheckIn;
    this->identificador=identidicador;
    this->CheckOut=CheckOut;
}
int DTEstadia::getIdentificador(){
    return this->identificador;
}
DTFecha DTEstadia::getCheckIn(){
    return this->CheckIn;
}
DTFecha DTEstadia::getCheckOut(){
    return this->CheckOut;
}

DTEstadia::~DTEstadia(){

}
