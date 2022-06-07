

#include"../include/UsuarioHuesped.h"
using namespace std;

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

void setEsFinger(bool finger){
    this->esFinger = finger;
}

//destructoras

Huesped::~Huesped(){ 
};
