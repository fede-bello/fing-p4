#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

//USO GENERAL, CREADORAS DESTRUCTORAS GETEMAIL etc
controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
}

controladorUsuario::controladorUsuario(){
        vector<string> ArregloEmail;
        map<string,Empleado*> MapaEmpleado;
        map<string,Huesped*> MapaHuesped;
}


controladorUsuario::~controladorUsuario(){
    for (auto &it:MapaEmpleado){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Empleado
        //it.first es la clave de MapaEmpleado
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Empleado> MapaEmpleado
        //const es para no repetir el valor
        string nombreEmpleado=it.first;//
        Empleado *empleado=it.second;
        empleado->~Empleado();
        MapaEmpleado.erase(nombreEmpleado);
    }
    MapaHuesped.clear();
    for (auto &it:MapaHuesped){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Huesped
        //it.first es la clave de MapaHuesped
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Huesped> MapaHuesped
        //const es para no repetir el valor
        string nombreHuesped=it.first;//
        Huesped *huesped=it.second;
        huesped->~Huesped();
        MapaHuesped.erase(nombreHuesped);
    }
    MapaEmpleado.clear();
}

void controladorUsuario::liberar(){
    ArregloEmail.clear();
}


Hostal controladorUsuario::find(string nombre){
    Hostal hos;

    return hos;
}

vector<string> controladorUsuario::getEmail(){
    return ArregloEmail;
}

void controladorUsuario::setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
    //ArregloEmail.emplace_back(EmailGuardado);
}

map<string,DTEmpleado> controladorUsuario::getEmpleados(){
    map<string,DTEmpleado> res;
    for(auto &it:MapaEmpleado){
        string mail=it.first;
        DTEmpleado dt=DTEmpleado(it.second->getNombre(),it.second->getPassword(),it.second->getMail(),it.second->getCargo());
        res.insert({mail,dt});
    }
    return res;
}

map<string,DTHuesped> controladorUsuario::getHuespedes(){
    map<string,DTHuesped> res;
    for(auto &it:MapaHuesped){
        string mail=it.first;
        DTHuesped dt=DTHuesped(it.second->getNombre(),it.second->getPassword(),it.second->getMail(),it.second->getEsFinger());
        res.insert({mail,dt});
    }
    return res;
}
//FIN USO GENERAL
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
    //ACA CAPAZ EN VEZ DE HACER EL SET ES MEJOR CREAR UN NUEVO DT Y MATAR EL VIEJO
}

void controladorUsuario::CancelarUsuario(DTUsuario *usuario){
    delete usuario;
}

void controladorUsuario::ConfirmarAltaEmpleado(DTEmpleado *empleado){
    map<string,Huesped*>::iterator it = this->MapaHuesped.find(empleado->getMail());   

    if(it != this->MapaHuesped.end()){
        throw "Ya existe un usuario con ese mail";
    }
    map<string,Empleado*>::iterator it2 = this->MapaEmpleado.find(empleado->getMail());   
    if(it2 != this->MapaEmpleado.end()){
        throw "Ya existe un usuario con ese mail";
    }else{
        Empleado *nuevo=new Empleado(empleado->getNombre(),empleado->getPassword(),empleado->getMail(),empleado->getCargo());
        this->MapaEmpleado[empleado->getNombre()]=nuevo;
    }
}

void controladorUsuario::ConfirmarAltaHuesped(DTHuesped *huesped){
    map<string,Empleado*>::iterator it = this->MapaEmpleado.find(huesped->getMail());   
    if(it != this->MapaEmpleado.end()){
        throw "Ya existe un usuario con ese mail";
    }    
    map<string,Huesped*>::iterator it2 = this->MapaHuesped.find(huesped->getMail());
    if(it2 != this->MapaHuesped.end()){
        throw "Ya existe un usuario con ese mail";//acá tiene que haber un throw de la exception porque quiere decir que ya hay un huesped con ese mail
    }else{
        Huesped *nuevo= new Huesped(huesped->getNombre(),huesped->getPassword(),huesped->getMail(),huesped->getEsFinger());
        this->MapaHuesped.insert({huesped->getMail(), nuevo});
    }
}
//FIN ALTA USUARIO

//ASiGNAR EMPLEADO A HOSTAL
vector<DTEmpleado> controladorUsuario::obtenerEmpleadoHostal(){//Devuelve los empleados no asignados a ningun hostal
    vector<DTEmpleado> res;
    map<string,Empleado*>::iterator it;
    for (it=this->MapaEmpleado.begin(); it!=this->MapaEmpleado.end(); ++it){
        Empleado *empl=it->second;
        if (!empl->empleadoAsignadoAHostal()){
            DTEmpleado agregar=empl->getDTEmpleado();
            res.push_back(agregar);
        } 
        
    }
    return res;
}

void controladorUsuario::ActualizarCargo(string mail,CargoEmp cargo){
    bool pedirMail=false;//antes de llamar a esta funcion se debe hacer un cin>>mail;
    do{
        try {
            if(pedirMail){
                cout<<"Digite el mail del usuario"<<endl;
                cin>>mail;
            }
            if(MapaEmpleado.find(mail)==MapaEmpleado.end()){
                throw "invalid_argument";
            }//el mail esta asociado a un empleado
            this->setEmail(mail);
            Empleado *usuario=MapaEmpleado[mail];
            usuario->setCargo(cargo);
            return;
        }
        catch(...){
            cout<<"No existe un usuario con ese mail";
            pedirMail=true;
        }
    }while(true);
}

void controladorUsuario::AsignarEmpleado(){
    string mail=ArregloEmail.front();
    Empleado *empleado=MapaEmpleado[mail];
    controladorHostal *controlHostal=controladorHostal::getInstance();
    string nombreHostal=controlHostal->getHostal()->getNombre();
    Hostal *hostal=controlHostal->getMapaHostal()[nombreHostal];
    //empleado.setHostal(hostal); esto tendria que ser un puntero
}

void controladorUsuario::cancelarAsignacionEmpleado(){
    this->ArregloEmail.clear();
    controladorHostal*ch=controladorHostal::getInstance();
    ch->liberar();
}
//FIN ASIGNAR EMPLEADO A HOSTAL

//Realizar Reserva

vector<DTHuesped> controladorUsuario::obtenerHuespedes(){
    map<string,Huesped*>::iterator it;
    vector<DTHuesped> huespedes;
    for (it=MapaHuesped.begin(); it!=MapaHuesped.end(); ++it){
        DTHuesped hues=it->second->getDTHuesped();
        huespedes.push_back(hues);
    }
    return huespedes;

}

DTHuesped controladorUsuario::elegirHuesped(string Mail){
    DTHuesped hues=MapaHuesped.find(Mail)->second->getDTHuesped();
   
    ArregloEmail.push_back(Mail);
    return hues;
}

void controladorUsuario::confirmarAltaReservaIndividual(){
    string email=this->ArregloEmail[0];//Si hay solo un mail esta guardado en la posicion 0
    Huesped *u=MapaHuesped.find(email)->second;
    controladorHostal *cu=controladorHostal::getInstance();
    cu->reservaAHostalInd(u);
}

void controladorUsuario::confirmarAltaReservaGrupal(){
    vector<string> cemail=this->ArregloEmail;
    map<string,Huesped*> huespedes;
    for(int i=0; i < cemail.size(); i++){
        Huesped *u=MapaHuesped.find(cemail[i])->second;
        huespedes[u->getMail()]=u;
    }
    controladorHostal *cu=controladorHostal::getInstance();
    cu->reservaAHostalGrup(huespedes);
}

void controladorUsuario::cancelarReserva(){
    ArregloEmail.clear(); //Libera la memoria del vector
    controladorHostal *cu=controladorHostal::getInstance();
    cu->liberarHos();
}

void controladorUsuario::calificarEstadia(int codigo, int calif, string texto){
    string email=this->ArregloEmail[0]; //Hay un mail recordado??? Chequear
    Huesped *hues=MapaHuesped.find(email)->second;
    controladorHostal *ch=controladorHostal::getInstance();
    ch->estadiaHostalCalificada(codigo,calif,texto,hues);
}

//Comentar Calificacion

vector<DTCalificacion> controladorUsuario::calificacionesSinResponder(string mail){
    if(MapaEmpleado.find(mail)==MapaEmpleado.end())
        throw "No hay empleado con ese mail";
    Empleado* empl=this->MapaEmpleado.find(mail)->second;
    Hostal *hos=empl->getHostal();
    controladorHostal* ch=controladorHostal::getInstance();
    return ch->califSinResponderHos(hos);
}


//Consulta de Usuario

vector<DTEmpleado> controladorUsuario::obtenerEmpleados(){
    map<string,Empleado*>::iterator it;
    vector<DTEmpleado> empleados;
    for (it=MapaEmpleado.begin(); it!=MapaEmpleado.end(); ++it){
        DTEmpleado empl=it->second->getDTEmpleado();
        empleados.push_back(empl);
    }
    return empleados;
}




DTUsuario* controladorUsuario::elegirUsuario(string email){
    if(MapaHuesped.find(email)!=MapaHuesped.end()){
        //Lo hallé y es Huesped
        DTHuesped hues;
        hues= MapaHuesped.find(email)->second->getDTHuesped();
        DTHuesped *h=new DTHuesped(hues.getNombre(), hues.getPassword(), hues.getMail(), hues.getEsFinger());
        return h;
    }
    else if (MapaEmpleado.find(email)!=MapaEmpleado.end()){//es Empleado
        DTEmpleado emp=MapaEmpleado.find(email)->second->getDTEmpleado();
        DTEmpleado *e=new DTEmpleado(emp.getNombre(), emp.getPassword(), emp.getPassword(), emp.getCargo());
        return e;
    }
    else {//no lo encontre
        throw "El email no corresponde a ningun usuario";
    }

   }


void controladorUsuario::informacionUsuario(DTUsuario usuarioInfo){
    DTUsuario * puntdt= &usuarioInfo;
    puntdt->imprimir();
    puntdt=NULL;
}



