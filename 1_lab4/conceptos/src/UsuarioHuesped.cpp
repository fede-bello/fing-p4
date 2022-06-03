

#include"../include/UsuarioHuesped.h"
using namespace std;



//creadoras

Huesped::Huesped(){
    string nom = "NombrePorDefecto";
    string mail = "MailPorDefecto@gmail.com";
    this->nombre = nom;
    this->email = mail;
    this->esFinger = false;
};
Huesped::Huesped(string nombre,string email,bool esFinger){
    this->nombre=nombre;
    this->email=email;
    this->esFinger=esFinger;
};
string Huesped::getNombre(){
    return this->nombre;
}
string Huesped::getEmail(){
    return this->email;
};
bool Huesped::getEsfinger(){
    return  this->esFinger;
};

void Huesped::setNombre(string nombre){
    this->nombre = nombre;
};

void Huesped:: setEmail(string email){
     this->email = email;
};
void Huesped::setEsFinger(bool esFinger){
    this->esFinger = esFinger;
};

Huesped::~Huesped(){
    
};
