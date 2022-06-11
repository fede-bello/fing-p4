#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

controladorUsuario::controladorUsuario (){
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}

controladorUsuario::~controladorUsuario(){
}

void controladorUsuario::liberar(){
    ArregloEmail.clear();
}

vector<string> controladorUsuario ::getEmail(){
    return ArregloEmail;
}

void controladorUsuario:: setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
}

DTEmpleado* controladorUsuario::NuevoEmpleado(string email,string password,string nombre,CargoEmp cargo){
    DTEmpleado *res=new DTEmpleado(nombre,password,email,cargo);
    return res;
}

DTHuesped* controladorUsuario::NuevoHuesped(string email,string password,string nombre,bool esFinger){
    DTHuesped *res=new DTHuesped(nombre,password,email,esFinger);
    return res;
}

void controladorUsuario::ActualizarMail(DTUsuario *usuario,string mail){
    usuario->setMail(mail);
}

void controladorUsuario::CancelarUsuario(DTUsuario *usuario){
    delete usuario;
}

void controladorUsuario::ConfimarAltaEmpleado(DTEmpleado *empleado){
    Empleado nuevo=Empleado(empleado->getNombre(),empleado->getPassword(),empleado->getMail(),empleado->getCargo());
    MapaEmpleado[nuevo.getMail()]=nuevo;
    delete empleado;
}

void controladorUsuario::ConfimarAltaHuesped(DTHuesped *huesped){
    Huesped nuevo=Huesped(huesped->getNombre(),huesped->getPassword(),huesped->getMail(),huesped->getEsFinger());
    MapaHuesped[nuevo.getMail()]=nuevo;
    delete huesped;
}

void confirarAltaHostal(DTHostal *dthostal){
    delete dthostal;
}