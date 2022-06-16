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
    int c=this->codigoRes;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha f= cf->getFechaActual();
    ReservaIndividual *r=new ReservaIndividual(c,f, DTFecha(), Cerrada);
    r->setHuesped(u); //En vez de usar el create llamo al creador y despues le seteo el Huesped;
    MapaReserva[c]=r;
    this->codigoRes++; //Agrego uno al codigo para que sea unico
    return r; //Devuelve la instancia de reserva creada
}

//Aca capaz falta algun dynamic cast
Reserva* controladorReserva::getReservaGrup(map<string,Huesped*> huespedes){
    int c=this->codigoRes;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha f= cf->getFechaActual();
    ReservaGrupal *r=new ReservaGrupal(c,f, DTFecha(), Cerrada, huespedes.size());
    
    r->setHuespedes(huespedes); //En vez de usar el create llamo al creador y despues le seteo los Huespedes;
    MapaReserva[c]=r;
    this->codigoRes++; //Agrego uno al codigo para que sea unico
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


DTEstadia controladorReserva::registrarEstadia(int res){
    Reserva *r=MapaReserva.find(res)->second;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha f=cf->getFechaActual();
    return r->crearEstadiaNueva(f);

}

void controladorReserva::actualizarEstadoReservaCerrada(int res){
    Reserva *r=MapaReserva.find(res)->second;
    r->cerrarEstadoReserva();
}

vector<DTEstadia> controladorReserva::obtenerEstadias(vector<Reserva> resA){
    vector<DTEstadia> res;
    for(int i=0; i<resA.size();i++){
        Reserva r=resA[i];
        vector<DTEstadia> ea=r.estadiasActivas();
        for( int j=0; j<ea.size(); j++){ //Agrega todas las estadias de ea a la coleccion a devolver
            res.push_back(ea[j]);
        }
    }
    return res;
}


DTEstadia controladorReserva::elegirEstadia(int codigo){
    map<int,Reserva*>::iterator it;
    this->codigoEst=codigo;
    DTEstadia res;
    for(it=MapaReserva.begin(); it!=MapaReserva.end(); ++it){
        Reserva *r=it->second;
        DTEstadia est=r->mismaEstadia(codigo);
        if (est.getIdentificador() !=DTEstadia().getIdentificador()){
            res=est; //si la estadia que devuelve mismaEstadia es distinta a la constructora por defecto entonces encontra la estadia que busco
        }
    }
    return res;
}

void controladorReserva::actualizarCheckOutEstadia(){
    int codigo=this->codigoEst;
    controladorFecha *cf=controladorFecha::getInstance();
    DTFecha co=cf->getFechaActual();
    map<int,Reserva*>::iterator it;
    for(it=MapaReserva.begin();it!=MapaReserva.end();++it){
        Reserva *r=it->second;
        r->actualizarCheckOut(co, codigo);
    }

}

vector<DTEstadia> controladorReserva::darEstadiaFinHuespedRes(string email,vector<Reserva> res){
    map<int,Reserva*>::iterator it;
    vector<DTEstadia> estadias;
    for (it=MapaReserva.begin(); it!=MapaReserva.end(); ++it){
        Reserva *re=it->second;
        vector<DTEstadia> est=re->EstadiasFin(email);
        for(int i=0; i<est.size();i++){
           estadias.push_back(est[i]);
        }
    }
    return estadias;
}

void controladorReserva::estadiaReservaCalificada(int codigo, int calif, string texto,Huesped *hues){
    map<int,Reserva*>::iterator it;
    for (it=MapaReserva.begin(); it!=MapaReserva.end(); ++it){
        Reserva *r=it->second;
        r->calificarEstadiaReserva( codigo, calif, texto, hues);
    }
}