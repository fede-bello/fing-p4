#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

//CREADORAS, DESTRUCTORAS, LIBERAR MAPA
controladorUsuario::controladorUsuario (){
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}

controladorUsuario::~controladorUsuario(){
    MapaEmpleado.clear();
    for (auto &it:MapaEmpleado){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Empleado
        //it.first es la clave de MapaEmpleado
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Empleado> MapaEmpleado
        //const es para no repetir el valor
        const string &nombreEmpleado=it.first;//
        Empleado &empleado=it.second;
        empleado.~Empleado();
    }
    MapaHuesped.clear();
    for (auto &it:MapaHuesped){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Huesped
        //it.first es la clave de MapaHuesped
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Huesped> MapaHuesped
        //const es para no repetir el valor
        const string &nombreHuesped=it.first;//
        Huesped &huesped=it.second;
        huesped.~Huesped();
    }
    MapaEmpleado.clear();
}

void controladorUsuario::liberar(){
    ArregloEmail.clear();
}
//FIN CREADORAS, DESTRUCTORAS, LIBERAR MAPA

//AÑADIR/CONSEGUIR MAILS
vector<string> controladorUsuario ::getEmail(){
    return ArregloEmail;
}

void controladorUsuario:: setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
    //ArregloEmail.emplace_back(EmailGuardado);
}
//FIN AÑADIR/CONSEGUIR MAILS
//ALTA USUARIO
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
//FIN ALTA USUARIO
