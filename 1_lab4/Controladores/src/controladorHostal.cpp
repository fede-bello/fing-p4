#include"../include/controladorHostal.h"

controladorHostal * controladorHostal::instancia = NULL;

//USO GENERAL 
controladorHostal * controladorHostal::getInstance() {
    if (instancia == NULL)
        instancia = new controladorHostal();
    return instancia;
}

controladorHostal::controladorHostal(){
    this->HostalGuardado=NULL;
} 

void controladorHostal::liberar(){
    if(HostalGuardado!=NULL) delete HostalGuardado;
}

string controladorHostal::getNombre(){
    return this->nombreGuardado;
}


//Dijeron que consumos no van
// void controladorHostal::agregarConsumo(int codigo){
    
// }

DTHabitacion* controladorHostal::nuevaHabitacion(int numH, int precioH, int capH){
    DTHabitacion* res = new DTHabitacion(numH, capH, precioH);

    return res;
}

controladorHostal::~controladorHostal(){  
    if(HostalGuardado==NULL) delete HostalGuardado;
    for (auto &it:MapaHostal){
        string nombreHostal=it.first;//
        Hostal *hostal=it.second;
        hostal->~Hostal();
        MapaHostal.erase(nombreHostal);
    }
    MapaHostal.clear();
}

DTHostal* controladorHostal::getHostal(){
    return this->HostalGuardado;
}

map<string,Hostal*> controladorHostal::getMapaHostal(){
    return this->MapaHostal;
}
//ALTA HOSTAL
DTHostal* controladorHostal:: nuevoHostal(string nombre,string direccion,string telefono){
    DTHostal *res=new DTHostal(nombre,direccion,telefono);
    return res;
}

void controladorHostal::confirmarAltaHostal(DTHostal *dthostal){
    bool excepcion;
    
    map<string,Hostal*>::iterator it = this->MapaHostal.find(dthostal->getNombre());

    if(it != this->MapaHostal.end()){
        throw "Ya existe otro Hostal con el mismo nombre";//acá tiene que haber un throw de la exception porque quiere decir que ya hay un empleado con ese mail
    }else{
        Hostal *nuevo=new Hostal(dthostal->getNombre(),dthostal->getDireccion(),dthostal->getTelefono());
        this->MapaHostal[dthostal->getNombre()]=nuevo;
    }
}


void controladorHostal::cancelarAltaHostal(DTHostal *dthostal){
    delete dthostal;
}
//FIN ALTA HOSTAL

//ALTA HABITACION
vector<DTHostal>controladorHostal::obtenerHostales(){
    bool excepcion;
    vector<DTHostal> res;

    //Reviso si hay Hostales registrados, si no hay lanzo excepcion
    if(!this->MapaHostal.empty()){ 
        map<string,Hostal*>::iterator it;
        for (it = this->MapaHostal.begin(); it!=this->MapaHostal.end();++it){//Asi itera en el teorico
                Hostal *hostal=it->second;
            res.push_back(DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono()));
        }

    }
    else {
        throw "No hay hostales en el sistema";
    }

    return res;
}

 

    //  VERSION FEDE ELEGIR HOSTAL
DTHostal *controladorHostal::elegirHostal(string nombre){  
    DTHostal *res;
    if(MapaHostal.find(nombre)!=MapaHostal.end()){
        Hostal *hostal=MapaHostal.find(nombre)->second;
        res=new DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono());
        this->HostalGuardado = res;
    }
    else{
        throw "No existe ningun hostal con ese nombre";
    }
    return res;
}


void controladorHostal::confirmarAltaHabitacion(DTHabitacion *habitacion){
    string nombre=this->HostalGuardado->getNombre();
    Hostal *hostal=MapaHostal.find(nombre)->second;
    hostal->agregarHabitacionAHostal(*habitacion);
}

void controladorHostal::cancelarAltaHabitacion(DTHabitacion *habitacion){
    delete habitacion;
    if(HostalGuardado!=NULL) delete this->HostalGuardado;
}
//Fin Alta Habitacion 

//Realizar Reserva

float controladorHostal::obtenerPromedioCalificaciones(){
    string nombre=this->nombreGuardado;
    Hostal *hos=this->MapaHostal.find(nombre)->second;
    vector<Reserva> reservas=hos->reservasAsociadas();
    controladorReserva* cr= controladorReserva::getInstance();
    return cr->darPromedio(reservas);
}


vector<DTHabitacion> controladorHostal::obtenerHabitaciones(DTFecha checkIn, DTFecha checkOut){
    string nombre=this->nombreGuardado;
    Hostal *hos=this->MapaHostal.find(nombre)->second;
    this->inGuardado=checkIn;
    this->outGuardado=checkOut;
    return hos->habitacionesDisponibles(checkIn, checkOut);
}

DTHabitacion controladorHostal::elegirHabitacion(int numero){
    map<string,Hostal*>::iterator it;
    DTHabitacion ha;
    this->numHabGuardado=numero;
    for(it=MapaHostal.begin(); it!=MapaHostal.end(); ++it){
        Hostal *hos=it->second;
        ha=hos->buscarHabitacion(numero);
    }
    DTHabitacion res;
    return res;
}

void controladorHostal::reservaAHostalInd(Huesped *u){
    DTFecha In=this->inGuardado;
    DTFecha Out=this->outGuardado;
    int habitacion=this->numHabGuardado;
    string hostal=this->nombreGuardado;
    controladorReserva *cr=controladorReserva::getInstance();
    Reserva *r= cr->getReservaInd(u);
    Hostal *h=this->MapaHostal.find(hostal)->second;
    h->AsociarReservaHostal(r,habitacion);
}


void controladorHostal::reservaAHostalGrup(map<string,Huesped*> huespedes){
    DTFecha In=this->inGuardado;
    DTFecha Out=this->outGuardado;
    int habitacion=this->numHabGuardado;
    string hostal=this->nombreGuardado;
    controladorReserva *cr=controladorReserva::getInstance();
    Reserva *r= cr->getReservaGrup(huespedes);
    Hostal *h=this->MapaHostal.find(hostal)->second;
    h->AsociarReservaHostal(r,habitacion);
}

void controladorHostal::liberarHos(){
    this->HostalGuardado->~DTHostal();
    this->HostalGuardado=NULL;
    controladorReserva *cr=controladorReserva::getInstance();
    cr->liberarRes();

}




//funcion auxiliar para mejoresTresHostales

string menorPromedio(map<string,int> Mapa){
    map<string,int>::iterator it;
    string res=Mapa.begin()->first;
    int min=Mapa.begin()->second;
    for(it=Mapa.begin(); it!=Mapa.end(); ++it){
        if (it->second<min){//Si el promedo del actual es menor que el guardado, guardo el nombre en res
            res=it->first;
        }
    }
    return res;
}

vector<string> controladorHostal::mejoresTresHostales(){
    controladorReserva* cr= controladorReserva::getInstance();
    map<string,int> mejores3;//En este map voy a ir guardando los hostales, es para no tener que calcular el promedio cada vez
    map<string,Hostal*>::iterator it;
    map<string,int>::iterator it2;
    for (it=MapaHostal.begin(); it!=MapaHostal.end(); ++it){
        Hostal *hos=it->second;
        vector<Reserva> reservas=hos->reservasAsociadas();
        controladorReserva* cr= controladorReserva::getInstance();
        int PromedioHostal=cr->darPromedio(reservas);
        if (mejores3.size()<3){ //Si hay menos de 3 guardados lo agrego
            mejores3[hos->getNombre()]=PromedioHostal;
        }
        else { //Si hay 3 o mas guardados lo comparo al de menor promedio, si es mayor los intercambio
            string menor=menorPromedio(mejores3);
            if (it2->second>mejores3[menor]){//Si el actual es mayor que el menor de los mejores 3
                mejores3.erase(menor); //elimino el peor de los 3
                mejores3[it2->first]=it2->second;//agrego el actual
            }
        }
    }
    //Agrego los nombres al vector y retorno
    vector<string> res;
    for (it2=mejores3.begin(); it2!=mejores3.end(); ++it2){
        res.push_back(it->first);
     }
     return res;

}

vector<DTCalificacion> controladorHostal::detallesHostal(string hostal){
    Hostal *hos=MapaHostal.find(hostal)->second;
    vector<Reserva> res=hos->reservasAsociadas();
    controladorReserva* cr= controladorReserva::getInstance();
    return cr->darCalificaciones(res);

}

vector<DTReserva> controladorHostal::obtenerReservasHuesped(string email, string hostal){
    Hostal *hos=MapaHostal.find(hostal)->second;
    return hos->darReservasHuespedHos(email);
    }

vector<DTEstadia> controladorHostal::estadiasHuespedActivas(string email){
    string hostal=this->nombreGuardado;
    Hostal *h=MapaHostal.find(hostal)->second;
    vector<Reserva> resA=h->reservasAsociadas();
    controladorReserva *cr=controladorReserva::getInstance();
    return cr->obtenerEstadias(resA);
}

void controladorHostal::finalizarEstadia(){
    controladorReserva *cr=controladorReserva::getInstance();
    cr->liberar();
}

//Fin Finalizar Estadia

//Calificar Estadia

vector<DTEstadia> controladorHostal::estadiasHuespedFinalizadas(string email, string hos){
    Hostal *h= MapaHostal.find(hos)->second;
    vector<Reserva> res=h->getReservasHostal(); 
    controladorReserva *cr=controladorReserva::getInstance();
    return cr->darEstadiaFinHuespedRes(email,res);

}

void controladorHostal::estadiaHostalCalificada (int codigo, int calif, string texto, Huesped *hues){
    controladorReserva *cr=controladorReserva::getInstance();
    cr->estadiaReservaCalificada(codigo, calif, texto, hues);
}

//Fin Calificar Estadia

//Comentar Calificacion

vector<DTCalificacion> controladorHostal::califSinResponderHos(Hostal *hos){
    vector<Reserva> res=hos->getReservasHostal();
    controladorReserva* cr=controladorReserva::getInstance();
    return cr->califSinResponderRes(res);
    
}

//Fin Comentar Calificacion


//Consulta de Hostal

vector<DTCalificacion> controladorHostal::obtenerCalificaciones(){
    string hostal = this->nombreGuardado;
    Hostal *h = MapaHostal.find(hostal)->second;
    vector<Reserva> resA = h->reservasAsociadas();
    controladorReserva *cr=controladorReserva::getInstance();
    vector<DTCalificacion> darC = cr->darCalificaciones(resA);
    return darC;
}

vector<DTHabitacion> controladorHostal::obtenerInfoHabitaciones(){
    string hostal = this->nombreGuardado;
    Hostal *h = MapaHostal.find(hostal)->second;
    vector<DTHabitacion> res = h->darInfoHabs();
    return res;
}

vector<DTReserva> controladorHostal::obtenerReservasHostal(){
    string hostal = this->nombreGuardado;
    Hostal *h = MapaHostal.find(hostal)->second;
    vector<DTReserva> res = h->darReservasHostal();
    return res;
}

void controladorHostal::liberarMemoria(){
    this->nombreGuardado = ".";
}

//Fin Consulta de Hostal



//Consulta de Reserva
int controladorHostal::habitacionDeReserva(string hostal, DTReserva res){
    controladorReserva *cr=controladorReserva::getInstance();
    int nr=cr->getNumero(res);
    Hostal *hos=this->MapaHostal.find(hostal)->second;
    return hos->darNumHab(nr);
}

vector<DTHuesped> controladorHostal::huespedesReserva(string hostal, DTReserva res){
    controladorReserva *cr=controladorReserva::getInstance();
    int nr=cr->getNumero(res);
    Hostal *hos=this->MapaHostal.find(hostal)->second;
    return hos->huespedes(nr);
}

//Fin Consulta de reserva

//Consulta de Estadia

vector<DTEstadia> controladorHostal::obtenerEstadias(string hostal){
    Hostal *h=this->MapaHostal.find(hostal)->second;
    vector<Reserva> resA=h->reservasAsociadas();
    this->nombreGuardado=hostal;
    controladorReserva* cr=controladorReserva::getInstance();
    return cr->estadiasHostal(resA);
}

DTHostal controladorHostal::hostalEstadia(){
    string hostal = this->nombreGuardado;
    Hostal *h = MapaHostal.find(hostal)->second;
    DTHostal res = h->getDTHostal();
    return res;
}

DTHuesped controladorHostal::huespedEstadia(){
    DTHuesped res;
    return res;
}

DTHabitacion controladorHostal::habitacionEstadia(){
    DTHabitacion res;
    return res;
}

DTEstadia controladorHostal::informacionEstadia(){
    DTEstadia res;
    return res;
}

DTCalificacion controladorHostal::calificacionEstadia(){
    DTCalificacion res;
    return res;
}

DTReserva controladorHostal::reservaAsociadaAEstadia(){
    DTReserva res;
    return res;
}

void controladorHostal::finalizarConsultaEstadia(){

}

//Baja de Reserva

void controladorHostal::bajaReserva(int codigo){
    string hostal = this->nombreGuardado;
    Hostal *h = MapaHostal.find(hostal)->second;
    h->eliminarLinkReserva(codigo);
    controladorReserva *cr=controladorReserva::getInstance();
    cr->eliminarLinksHuesEst(codigo);
    this->nombreGuardado = ".";
}

void controladorHostal::cancelarBajaReserva(int codigo){
    this->nombreGuardado = ".";
}
