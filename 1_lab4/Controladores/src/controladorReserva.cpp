#include"../include/controladorReserva.h"

controladorReserva * controladorReserva::instancia = NULL;

controladorReserva * controladorReserva::getInstance() {
    if (instancia == NULL)
        instancia = new controladorReserva();
    return instancia;
}

controladorReserva::controladorReserva(){
    this->ReservaGuardada=NULL;
} 

void controladorReserva::liberar(){
    if(ReservaGuardada!=NULL) delete ReservaGuardada;
}

controladorReserva::~controladorReserva(){
    for (auto &it:MapaReserva){//Como Iterar En un Mapa, se Asocia it a cada elemento del Mapa Reserva
        //it.first es la clave de MapaReserva
        //it.second es el objeto asociado a it.first
        //todo esto sale de la creacion del Mapa, map<int,Reserva> MapaReserva
        //const es para no repetir el valor
        int nombreReserva=it.first;
        Reserva *reserva=it.second;
        reserva->~Reserva();
        MapaReserva.erase(nombreReserva);
    }
    MapaReserva.clear();
}


float controladorReserva::darPromedio(vector<Reserva> reservas){
    for (int i=0; i=reservas.size(); i++){
        reservas[i].calcularPromedioReserva();
    }

    return 0; 
}

//Aca capaz falta algun dynamic cast
Reserva* controladorReserva::getReservaInd(Huesped *u){
    int c=this->codigo;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha f= cf->getFechaActual();
    ReservaIndividual *r=new ReservaIndividual(c,f, DTFecha(), Cerrada);
    r->setHuesped(u); //En vez de usar el create llamo al creador y despues le seteo el Huesped;
    MapaReserva[c]=r;
    this->codigo++; //Agrego uno al codigo para que sea unico
    return r; //Devuelve la instancia de reserva creada
}

//Aca capaz falta algun dynamic cast
Reserva* controladorReserva::getReservaGrup(map<string,Huesped*> huespedes){
    int c=this->codigo;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha f= cf->getFechaActual();
    ReservaGrupal *r=new ReservaGrupal(c,f, DTFecha(), Cerrada, huespedes.size());
    
    r->setHuespedes(huespedes); //En vez de usar el create llamo al creador y despues le seteo los Huespedes;
    MapaReserva[c]=r;
    this->codigo++; //Agrego uno al codigo para que sea unico
    return r; //Devuelve la instancia de reserva creada
}

void controladorReserva::liberarRes(){
    this->ReservaGuardada->~DTReserva();
    this->ReservaGuardada=NULL;
}

vector<DTCalificacion> controladorReserva::darCalificaciones(vector<Reserva> reservas){
    vector<DTCalificacion> res;
    for (int i=0; i<reservas.size(); i++){ //Para cada reserva
        vector<DTCalificacion> cres=reservas[i].darCalificacionesReserva();
        for (int j=0; j<cres.size();j++){ //Agergo cada calificacion anterior al set a devolver
            res.push_back(cres[j]);
        }
    }
    return res;
}