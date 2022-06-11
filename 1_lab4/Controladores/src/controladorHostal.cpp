#include"../include/controladorHostal.h"

controladorHostal * controladorHostal::instancia = NULL;

controladorHostal * controladorHostal::getInstance() {
    if (instancia == NULL)
        instancia = new controladorHostal();
    return instancia;
}



controladorHostal::controladorHostal(){
} 


DTHostal* controladorHostal:: NuevoHostal(string nombre,string direccion,int telefono){
    DTHostal *res=new DTHostal(nombre,direccion,telefono);
    return res;
}

void controladorHostal::confirarAltaHostal(DTHostal *dthostal){
    Hostal res=Hostal(dthostal->getNombre(),dthostal->getDireccion(),dthostal->getTelefono());
    MapaHostal[res.getNombre()]=res;
    delete dthostal;
}

DTHostal controladorHostal::elegirHostal(string nombre){
    bool salir=true;
    while(salir){
        try {//antes de llamar a esta funcion se debe hacer un cin>>nombre;
            if(!salir){
                cout<<"Digite el nombre del hostal"<<endl;
                cin>>nombre;
            }
            if(MapaHostal.find(nombre)==MapaHostal.end()){
                throw "invalid_argument";
            }
            Hostal hostal=MapaHostal[nombre];
            DTHostal res=DTHostal(hostal.getNombre(),hostal.getDireccion(),hostal.getTelefono());
            return res;//solo salgo por esta condicion
        }
        catch(...){
            cout<<"No existe un hostal con ese nombre";
        }
    }
    

}



