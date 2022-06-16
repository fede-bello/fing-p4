#include "../include/controladorUsuario.h"

controladorUsuario * controladorUsuario::instance=NULL;

//USO GENERAL, CREADORAS DESTRUCTORAS GETEMAIL etc
controladorUsuario::controladorUsuario (){
}; 

controladorUsuario * controladorUsuario::getInstance(){
    if (instance==NULL)
        instance= new controladorUsuario();
    return instance;
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

vector<string> controladorUsuario ::getEmail(){
    return ArregloEmail;
}

void controladorUsuario:: setEmail(string EmailGuardado){
    ArregloEmail.push_back(EmailGuardado);
    //ArregloEmail.emplace_back(EmailGuardado);
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

void controladorUsuario::ConfimarAltaEmpleado(DTEmpleado *empleado){
    Empleado *nuevo=new Empleado(empleado->getNombre(),empleado->getPassword(),empleado->getMail(),empleado->getCargo());
    MapaEmpleado[nuevo->getMail()]=nuevo;
    delete empleado;
}

void controladorUsuario::ConfimarAltaHuesped(DTHuesped *huesped){
    Huesped *nuevo=new Huesped(huesped->getNombre(),huesped->getPassword(),huesped->getMail(),huesped->getEsFinger());
    MapaHuesped[nuevo->getMail()]=nuevo;
    delete huesped;
}
//FIN ALTA USUARIO

//ASiGNAR EMPLEADO A HOSTAL
vector<DTEmpleado> controladorUsuario::obtenerEmpleadoHostal(){
    vector<DTEmpleado> res;
    for (auto &it:MapaEmpleado){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Empleado
        //it.first es la clave de MapaEmpleado
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Empleado> MapaEmpleado
        //const es para no repetir el valor
        Empleado *empleado=it.second;
        if(empleado->getHostal()==NULL){
            DTEmpleado dtempleado=DTEmpleado(empleado->getNombre(),empleado->getPassword(),empleado->getMail(),empleado->getCargo());
            res.push_back(dtempleado);
        }
    }
    return res;
}

void controladorUsuario::actualizarCargo(string mail,CargoEmp cargo){
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

void controladorUsuario::asignarEmpleado(){
    string mail=ArregloEmail.front();
    Empleado *empleado=MapaEmpleado[mail];
    controladorHostal *controlHostal=controladorHostal::getInstance();
    string nombreHostal=controlHostal->getHostal()->getNombre();
    Hostal *hostal=controlHostal->getMapaHostal()[nombreHostal];
    //empleado.setHostal(hostal); esto tendria que ser un puntero
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


DTUsuario controladorUsuario::elegirUsuario(string email){
    if(MapaHuesped.find(email)!=MapaHuesped.end()){
        //Lo hallé y es Huesped
        DTHuesped hues;
        hues= MapaHuesped.find(email)->second->getDTHuesped();
        return hues;
    }
    else { //es Empleado
    DTEmpleado emp=MapaEmpleado.find(email)->second->getDTEmpleado();
        return emp;
    }

   }


void controladorUsuario::informacionUsuario(DTUsuario usuarioInfo){
    DTUsuario * puntdt= &usuarioInfo;
    puntdt->imprimir();
    puntdt=NULL;
}



