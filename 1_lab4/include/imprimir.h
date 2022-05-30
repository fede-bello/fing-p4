/*#ifndef IMPRIMIR
#define IMPRIMIR
#include"DTReservaGrupal.h"
#include"DTReservaIndividual.h"
using namespace std;
using namespace std::string_literals;

ostream &operator<< (ostream& o, DTHuesped * hues){
	if (hues->getEsFinger())
		return o<<"Nombre: "<< hues->getNombre()<<endl<< "Email: "<<hues->getEmail()<<endl<< "Finger: Si"<<endl;
	else
		return o<<"Nombre: "<< hues->getNombre()<<endl<< "Email: "<<hues->getEmail()<<endl <<"Finger: No"<<endl;
}

ostream &operator<< (ostream& o, DTHabitacion * hab){
	return o<<"Número habitación: "<< hab->getNum()<<endl<< "Capacidad habitación: " << hab->getCap() <<endl<< "Costo: $"<<hab->getPrecio()<<endl;
}

ostream &operator<< (ostream& o, DTReserva * res ){
    //if (esreservaindividual)
    if(res->getCantidad() == 1){
        
        DTReservaIndividual *pRIndividual = dynamic_cast<DTReservaIndividual*>(res); //transformo la Reserva en reservaIndividual para poder acceder al bool pagado
        
        bool pago = pRIndividual->getPagado();
        
        if(pago){
            
            int numero=pRIndividual->getHabitacion();           
            DTFecha checkIN= pRIndividual->getCheckIn();           
            DTFecha checkOut= pRIndividual->getCheckOut();           
            EstadoReserva estado= pRIndividual->getEstado();           
            float costo= pRIndividual->getCosto();            
            int codigo= pRIndividual->getCodigo();           
            int cantidad= pRIndividual->getCantidad();            
            bool pagado=pRIndividual->getPagado();
            
            return o<<"TipoReserva: "<< "Individual" << endl<< "FechaCheckIn: "<<
            checkIN.getDia()<< "/"<<checkIN.getMes()<< "/"<<
            checkIN.getAnio()<<endl<< "FechaCheckOut: "<<checkOut.getDia()<<
            "/" <<checkOut.getMes()<<"/"<<checkOut.getAnio()<<endl<<"Habitación: "<<
            numero<<endl<<"Costo: $"<<costo<<endl<< "Pagado: "<< "Si"<<endl;
        }else{

            int numero=pRIndividual->getHabitacion();
            DTFecha checkIN= pRIndividual->getCheckIn();            
            DTFecha checkOut= pRIndividual->getCheckOut();           
            EstadoReserva estado= pRIndividual->getEstado();          
            float costo= pRIndividual->getCosto();           
            int codigo= pRIndividual->getCodigo();            
            int cantidad= pRIndividual->getCantidad();            
            bool pagado=pRIndividual->getPagado();      

            return o<<"TipoReserva: "<< "Individual" << endl<< "FechaCheckIn: "<<
            checkIN.getDia()<< "/"<<checkIN.getMes()<< "/"<<
            checkIN.getAnio()<<endl<< "FechaCheckOut: "<<checkOut.getDia()<<
            "/" <<checkOut.getMes()<<"/"<<checkOut.getAnio()<<endl<<"Habitación: "<<
            numero<<endl<<"Costo: $"<<costo<<endl<< "Pagado: "<< "No"<<endl;
        }
    }else{
        
        DTReservaGrupal *pRGrupal = dynamic_cast<DTReservaGrupal*>(res); //transformo la Reserva en reservaIndividual para poder acceder al bool pagado
        int numero=pRGrupal->getHabitacion();
        DTFecha checkIN= pRGrupal->getCheckIn();            
        DTFecha checkOut= pRGrupal->getCheckOut();           
        EstadoReserva estado= pRGrupal->getEstado();          
        float costo= pRGrupal->getCosto();           
        int codigo= pRGrupal->getCodigo();            
        int cantidad= pRGrupal->getCantidad();   

        o<<"TipoReserva: "<< "Grupal" << endl<< "FechaCheckIn: "<<
        checkIN.getDia()<< "/"<<checkIN.getMes()<< "/"<<
        checkIN.getAnio()<<endl<< "FechaCheckOut: "<<checkOut.getDia()<<
        "/" <<checkOut.getMes()<<"/"<<checkOut.getAnio()<<endl<<"Habitación: "<<
        numero<<endl<<"Costo: $"<<costo<<endl<<  "Húespedes: ";

        int iter = 0;
        DTHuesped **huespedes = pRGrupal->getHuespedes();
        while(iter < cantidad){
            bool finger = huespedes[iter]->getEsFinger();

            if(finger){
                o <<huespedes[iter]->getNombre()<<" - "<<huespedes[iter]->getEmail()<<" - "<<" Es Finger, "<<endl;
            }else{
                o <<huespedes[iter]->getNombre()<<" - "<<huespedes[iter]->getEmail()<<endl;
            }
            delete huespedes[iter];
            iter++;
        }
        delete[] huespedes;
        return o;
    }
}

#endif
*/