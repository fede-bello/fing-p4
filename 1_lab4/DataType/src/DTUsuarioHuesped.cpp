
#include"../include/DTUsuarioHuesped.h"

//datatype

DTHuesped::DTHuesped(string nombre, string email,string password, bool esFinger):DTUsuario(nombre, email,password){
    this->esFinger=esFinger;
};

//gets 

bool DTHuesped::getEsFinger(){
    return this->esFinger;
};



//destructora 
DTHuesped::~DTHuesped(){

};

