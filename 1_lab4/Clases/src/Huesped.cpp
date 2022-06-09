

#include"../include/Huesped.h"


//creadoras

Huesped::Huesped():Usuario(){
    this->esFinger = false;
};

Huesped::Huesped(string Nombre,string Password, string Mail, bool esFinger):Usuario(Nombre, Password, Mail){
    this->esFinger=esFinger;
};


//getter y setters

bool Huesped::getEsFinger(){
    return this->esFinger;
};

void Huesped::setEsFinger(bool finger){
    this->esFinger = finger;
}

DTHuesped Huesped::getDTHuesped(){
    return DTHuesped(this->Nombre, this->Password, this->Mail, this->esFinger);
}

bool Huesped::mismoMail(string email){
    return (this->Mail==email);
}
//destructoras

Huesped::~Huesped(){ 
};
