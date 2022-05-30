
#include "../include/Sistema.h"
Sistema::Sistema(){
	Huesped **ArrHuesped=new Huesped*[MAX_HUESPEDES];
	for(int i=0;i<MAX_HUESPEDES;i++)
		ArrHuesped[i]=NULL;
	Habitacion **ArrHabitacion= new Habitacion*[MAX_HABITACIONES];
	for (int i = 0; i < MAX_HABITACIONES; i++)
		ArrHabitacion[i]= NULL;	
	Reserva **ArrReserva=new Reserva*[MAX_RESERVAS];
	for (int i = 0; i < MAX_RESERVAS; i++)
		ArrReserva[i]= NULL;
	
	this->ArrHuesped=ArrHuesped;
	this->ArrHabitacion=ArrHabitacion;
	this->ArrReserva=ArrReserva;
}

Sistema:: ~Sistema(){
	for(int i=0; i<this->indHuesped;i++)
		delete this->ArrHuesped[i];
	for(int i=0;i<this->indHabitacion;i++)
		delete this->ArrHabitacion[i];
	for(int i=0;i<this->indReserva;i++){
		if(this->ArrReserva[i]->getCantidad()>1){
			ReservaGrupal *pRGrupal = dynamic_cast<ReservaGrupal*>(this->ArrReserva[i]); 
			Huesped **arreglo= pRGrupal->getHuespedes();
			for(int i=0;i<pRGrupal->getCantidad();i++){
				delete arreglo[i];
			}
			delete[] arreglo;
		}
		delete this->ArrReserva[i];
	}
		
	
	delete[] this->ArrHabitacion;
	delete[] this->ArrHuesped;
	delete[] this->ArrReserva;
}

void Sistema::agregarHuesped(string nombre, string email, bool esFinger){
	Huesped *nuevo=new Huesped(nombre,email,esFinger);
	this->ArrHuesped[this->indHuesped]=nuevo;
	cout<<"Usuario "<<nombre<<" Agregado"<<endl;
	cout << endl;
	this->indHuesped++;	
}

void Sistema::agregarHabitacion(int numero, int capacidad, float precio){
	Habitacion *nuevo = new Habitacion(numero,capacidad,precio);
	this->ArrHabitacion[this->indHabitacion]=nuevo;
	cout<<"Habitacion agregada "<<numero<<endl;
	cout << endl;
	this->indHabitacion++;
}	

DTHuesped** Sistema::obtenerHuespedes(int &cantHuespedes){
	int i = 0;
	DTHuesped **arreglo_dtHuesped = new DTHuesped*[this->indHuesped];
	while(i < indHuesped){
		DTHuesped *huesped_i = new DTHuesped(this->ArrHuesped[i]->getNombre(), this->ArrHuesped[i]->getEmail(), this->ArrHuesped[i]->getEsfinger());
		arreglo_dtHuesped[i] = huesped_i;
		i++;
	}
	cantHuespedes=this->indHuesped;
	return arreglo_dtHuesped;
}

DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){
	int i = 0;
	DTHabitacion **arreglo_dthabitaciones = new DTHabitacion*[this->indHabitacion];
	while(i < this->indHabitacion){
		DTHabitacion *habitacion_i = new DTHabitacion(this->ArrHabitacion[i]->getNum(), this->ArrHabitacion[i]->getCap(), this->ArrHabitacion[i]->getPrecio());		
		arreglo_dthabitaciones[i] = habitacion_i;
		i++;
	}
	cantHabitaciones=this->indHabitacion;
	return arreglo_dthabitaciones;
}

DTReserva** Sistema::obtenerReservas(DTFecha fecha, int& cantReservas){
	int i=0;
	DTReserva **res = new DTReserva*[this->indReserva];

	while(i < this->indReserva){
		res[i] = NULL;

		i++;
	}

	i = 0;

	int contador_reservas = 0;

	while (i < this->indReserva){

		DTFecha checkIn=this->ArrReserva[i]->getCheckIn();
		DTFecha checkOut=this->ArrReserva[i]->getCheckOut();

		if (checkIn == fecha){ //este es el checkeo que hay que hacer segun el foro (Lab 0 - Ejercicio 1.2 - parte e 15/03/2022)
			if(this->ArrReserva[i]->getCantidad()>1){
				//*********RESERVA GRUPAL*********
				ReservaGrupal *pRGrupal = dynamic_cast<ReservaGrupal*>(this->ArrReserva[i]); //transformo la Reserva en reservaGrupal para poder acceder al arreglo de huéspedes
				
				Huesped **arregloHuespedes = pRGrupal->getHuespedes();
				
				int iter1 = 0;
				DTHuesped **arregloDTHuespedes = new DTHuesped*[this->indHuesped];
				while(iter1 < pRGrupal->getCantidad()){

					string nombreagrego = arregloHuespedes[iter1]->getNombre();
					string mailagrego = arregloHuespedes[iter1]->getEmail();
					bool esFingerAgrego = arregloHuespedes[iter1]->getEsfinger();

					DTHuesped *a_agregar = new DTHuesped(nombreagrego, mailagrego, esFingerAgrego);

					arregloDTHuespedes[iter1] = a_agregar;
					iter1++;
				}

				int numero = pRGrupal->getHabitacion()->getNum();
				DTFecha checkIN = pRGrupal->getCheckIn();            
				DTFecha checkOut = pRGrupal->getCheckOut();           
				EstadoReserva estado = pRGrupal->getEstado();          
				float costo = pRGrupal->calcularCosto();           
				int codigo = pRGrupal->getCodigo();            
				int cantidad = pRGrupal->getCantidad(); 

				res[contador_reservas] = new DTReservaGrupal(numero, checkIN, checkOut, estado, costo, codigo, cantidad,arregloDTHuespedes);
				contador_reservas++;

			}else{
				//******RESERVA INDIVIDUAL********
				ReservaIndividual *pRIndividual = dynamic_cast<ReservaIndividual*>(this->ArrReserva[i]); //transformo la Reserva en reservaIndividual para poder acceder al bool pagado

				int numero = pRIndividual->getHabitacion()->getNum();

				DTFecha checkIN = pRIndividual->getCheckIn();
				DTFecha checkOut = pRIndividual->getCheckOut();

				EstadoReserva estado = pRIndividual->getEstado();

				float costo = pRIndividual->calcularCosto();
				int codigo = pRIndividual->getCodigo();
				int cantidad = pRIndividual->getCantidad();
				bool pagado = pRIndividual->getPagado();

				DTReservaIndividual *nueva = new DTReservaIndividual(numero,checkIN,checkOut,estado,costo,codigo,cantidad,pagado);

				res[contador_reservas] = nueva;
				contador_reservas++;
			}
		}
		i++;
	}


	cantReservas=contador_reservas;
	return res;
}

void Sistema::registrarReserva(string email, DTReserva *reserva){
	bool encontre=false;//Inicio Habitacion Asociada
	int i=0;
	while((!encontre) && (i<this->indHabitacion)){
		if(reserva->getHabitacion()==this->ArrHabitacion[i]->getNum()){
			encontre=true;
		}
		i++; //se asocia despues de crear ReservaAgregada
	} 
	i--;
	Habitacion *habitacion=this->ArrHabitacion[i];//Fin Habitacion Asociada
	if(reserva->getCantidad()==1){
		//***RESERVA INDIVIDUAL***
		DTReservaIndividual *pRIndividual = dynamic_cast<DTReservaIndividual*>(reserva); 
		Reserva *ReservaAgregada=new ReservaIndividual(reserva->getCodigo(),reserva->getCheckIn(),reserva->getCheckOut(),reserva->getEstado(),1,pRIndividual->getPagado());
		ReservaAgregada->setHabitacion(habitacion);
		encontre=false;//Inicio Huesped asociado
		i=0;
		while(!encontre && i<this->indHuesped){
			if(email==this->ArrHuesped[i]->getEmail())
				encontre=true;
			i++;
		}
		i--;
		Huesped *huesped = this->ArrHuesped[i];
		ReservaAgregada->setHuesped(huesped);//Fin Huesped Asociado
		this->ArrReserva[this->indReserva] = ReservaAgregada;
	}else{
		//***RESERVA Grupal***
		DTReservaGrupal *pRGrupal = dynamic_cast<DTReservaGrupal*>(reserva);
		DTHuesped **DT_Huespedes=pRGrupal->getHuespedes();
		
		Huesped **arreglodehuespedes=new Huesped*[reserva->getCantidad()];
		i=0;
		while(i < reserva->getCantidad()){
			string nombre = DT_Huespedes[i]->getNombre();
			string email = DT_Huespedes[i]->getEmail();
			bool esFinger = DT_Huespedes[i]->getEsFinger();
			Huesped *nuevo = new Huesped(nombre,email,esFinger);
			arreglodehuespedes[i] = nuevo;
			delete DT_Huespedes[i];
			i++;
		}
		delete[] DT_Huespedes;
		Reserva *ReservaAgregada = new ReservaGrupal(reserva->getCodigo(),reserva->getCheckIn(),reserva->getCheckOut(),reserva->getEstado(),reserva->getCantidad(), arreglodehuespedes);
		ReservaAgregada->setHabitacion(habitacion);
		
		this->ArrReserva[this->indReserva] = ReservaAgregada;
	}	
	delete reserva;
	this->indReserva++;	
}

