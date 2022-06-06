
#include"../include/DTHuesped.h"
#include "DTUsuario.cpp"

//datatype
DTHuesped::DTHuesped():DTUsuario(){
    this->esFinger=false;
}

DTHuesped::DTHuesped(string Nombre,string Password, string Mail, bool esFinger):DTUsuario(Nombre, Password, Mail){
    this->esFinger=esFinger;
};

//gets 

bool DTHuesped::getEsFinger(){
    return this->esFinger;
};



//destructora 
DTHuesped::~DTHuesped(){

};

