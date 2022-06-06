#include "../include/DTUsuario.h"


//Constructoras
DTUsuario::DTUsuario(){
    this->Nombre:='.';
    this->Password:='.';
    this->Mail:='.';
    
}
DTUsuario::DTUsuario(string Nombre, string Password, string Mail){
    this->Nombre:=Nombre;
    this->Password:=Password;
    this->Mail:=Mail;
}

//Getters
string getNombre(){
    return this->Nombre;
}

string getPassword(){
    return this->Password;
}

string getMail(){
    return this->Mail;
}

//Destructora
DTUsuario:: ~DTUsuario(){

}