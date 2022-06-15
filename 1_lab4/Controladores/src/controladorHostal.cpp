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

controladorHostal::~controladorHostal(){  
    if(HostalGuardado==NULL) delete HostalGuardado;
    for (auto &it:MapaHostal){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Hostal
        //it.first es la clave de MapaHostal
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<string,Hostal> MapaHostal
        //const es para no repetir el valor
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
    Hostal *res=new Hostal(dthostal->getNombre(),dthostal->getDireccion(),dthostal->getTelefono());
    MapaHostal[res->getNombre()]=res;
    delete dthostal;
}

void controladorHostal::cancelarAltaHostal(DTHostal *dthostal){
    delete dthostal;
}
//FIN ALTA HOSTAL

//ALTA HABITACION
vector<DTHostal>controladorHostal::obtenerHostales(){
    vector<DTHostal> res;
    map<string,Hostal*>::iterator it;
    for (it=this->MapaHostal.begin(); it!=this->MapaHostal.end();++it){//Asi itera en el teorico
        Hostal *hostal=it->second;
        res.push_back(DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono()));
    }
    return res;//Luego de esta Funcion habria que res.clear();
}

DTHostal *controladorHostal::elegirHostal(string nombre){
    bool pedirNombre=false;//antes de llamar a esta funcion se debe hacer un cin>>nombre;
    do{
        try {
            if(pedirNombre){
                cout<<"Digite el nombre del hostal"<<endl;
                cin>>nombre;
            }
            if(MapaHostal.find(nombre)==MapaHostal.end()){
                throw "invalid_argument";
            }
            Hostal *hostal=MapaHostal[nombre];
            DTHostal *res=new DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono());
            this->HostalGuardado=res;
            return res;//solo salgo por esta condicion
        }
        catch(...){
            cout<<"No existe un hostal con ese nombre";
            pedirNombre=true;
        }
    }while(true);
}   
/*
     VERSION FEDE ELEGIR HOSTAL
DTHostal *controladorHostal::elegirHostal(string nombre){
    
    DTHostal *res;
    if(MapaHostal.find(nombre)==MapaHostal.end()){
        Hostal *hostal=MapaHostal.find(nombre)->second;
        res=new DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono());
    }
    return res;
}
*/







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