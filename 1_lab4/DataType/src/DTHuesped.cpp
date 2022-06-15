
#include"../include/DTHuesped.h"


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

//imprimir
void DTHuesped::imprimir() {
    bool test=this->esFinger;
    if (test) {
        cout << "Nombre: " << this->getNombre() <<endl << "Email: " << this->getMail()<< endl<< "Finger: Si"<<endl;
    }
    else 
    cout << "Nombre: " << this->getNombre() <<endl << "Email: " << this->getMail()<< endl<< "Finger: No"<<endl;
};

//destructora 
DTHuesped::~DTHuesped(){

};

