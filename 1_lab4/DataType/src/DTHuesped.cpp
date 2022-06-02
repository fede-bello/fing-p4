
#include"../include/DTHuesped.h"

using namespace std;



//datatype
DTHuesped::DTHuesped(){
    string nom = "NombrePorDefecto";
    string mail = "MailPorDefecto@gmail.com";
    this->nombre = nom;
    this->email = mail;
    this->esFinger = false;
};

DTHuesped::DTHuesped(string nombre, string email, bool esFinger){
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
};

//gets 
string DTHuesped::getNombre(){
    return this->nombre;
};

string DTHuesped::getEmail(){
    return this->email;
};

bool DTHuesped::getEsFinger(){
    return this->esFinger;
};

bool DTHuesped:: operator==(DTHuesped &otro) const{
    return (this->email ==otro.email);
}

//destructora 
DTHuesped::~DTHuesped(){

};

