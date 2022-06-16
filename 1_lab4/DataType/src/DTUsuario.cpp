#include "../include/DTUsuario.h"


//Constructoras
DTUsuario::DTUsuario(){
    this->Nombre='.';
    this->Password='.';
    this->Mail='.';
    
}

DTUsuario::DTUsuario(string Nombre, string Password, string Mail){
    this->Nombre=Nombre;
    this->Password=Password;
    this->Mail=Mail;
}

//Getters
string DTUsuario::getNombre(){
    return this->Nombre;
}

string DTUsuario::getPassword(){
    return this->Password;
}

string DTUsuario::getMail(){
    return this->Mail;
}
//set 
void DTUsuario::setMail(string Mail){
    this->Mail=Mail;
}
void DTUsuario::imprimir(){
    
}

//Destructora
DTUsuario:: ~DTUsuario(){

}