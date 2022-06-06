

#include "../include/DTUsuario.h"


DTUsuario::DTUsuario(string nombre, string email, string contra){
    this->nombre = nombre;
    this->email = email;
    this->contra=contra;
};

//gets 
string DTUsuario::getNombre(){
    return this->nombre;
};

string DTUsuario::getEmail(){
    return this->email;
};
string DTUsuario::getContra(){
    return this->contra;
};



//destructora 
DTUsuario::~DTUsuario(){

};

