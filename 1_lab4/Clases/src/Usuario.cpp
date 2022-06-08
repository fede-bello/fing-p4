#include"../include/Usuario.h"

//Constructoras
Usuario::Usuario(){
    this->Nombre = '.';
    this->Password = '.';
    this->Mail = '.';
    
}

Usuario::Usuario(string Nombre, string Password, string Mail){
    this->Nombre = Nombre;
    this->Password = Password;
    this->Mail = Mail;
}

//Setters y getters
string Usuario::getNombre(){
    return this->Nombre;
}

string Usuario::getPassword(){
    return this->Password;
}

string Usuario::getMail(){
    return this->Mail;
}

void Usuario::setNombre(string Nombre){
    this->Nombre = Nombre;
}

void Usuario::setPassword(string Password){
    this->Password = Password;
}

void Usuario::setMail(string Mail){
    this->Mail = Mail;
}

//Destructora
Usuario:: ~Usuario(){

}