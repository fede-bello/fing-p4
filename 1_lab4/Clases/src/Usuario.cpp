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
string getNombre(){
    return this->Nombre;
}

string getPassword(){
    return this->Password;
}

string getMail(){
    return this->Mail;
}

void setNombre(string Nombre){
    this->Nombre = Nombre;
}

void setPassword(string Password){
    this->Password = Password;
}

void setMail(string Mail){
    this->Mail = Mail;
}

//Destructora
Usuario:: ~Usuario(){

}