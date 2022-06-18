#include "Interfaces/include/Factory.h"

void ImprimirOpciones()
{   
    cout << endl;
    cout << "Ingresa la opción deseada" << endl;
    cout << "0 -> Salir" << endl;
    cout << "1 -> Alta de Usuario " << endl;
    cout << "2 -> Alta de Hostal" << endl;
    cout << "3 -> Alta de Habitacion" << endl;
    cout << "4 -> Asignar empleado a hostal" << endl;
    cout << "5 -> Realizar Reserva" << endl;
    cout << "6 -> Consultar top 3 de hostales" << endl;
    cout << "7 -> Registrar Estadia" << endl;
    cout << "8 -> Finalizar Estadia" << endl;
    cout << "9 -> Calificar Estadia" << endl;
    cout << "10 -> Comentar Calificacion" << endl;
    cout << "11 -> Consulta de Usuario" << endl;
    cout << "12 -> Consulta de Hostal" << endl;
    cout << "13 -> Consulta de Reserva" << endl;
    cout << "14-> Consulta de Estadia" << endl;
    cout << "15 -> Baja de Reserva" << endl<<endl;
}

DTFecha digiteFecha(){
        int dia;
        cout<<"Digite el numero del dia en el que vendra"<<endl;
        cin >>dia;
        if(dia>31 && dia<1)
            throw "El dia digitado es erroneo";
        int mes;
        cout<<"Digite el numero del mes en el que vendra"<<endl;
        cin >>mes;
        if(mes>12 && mes<1)
            throw "El mes digitado es erroneo";
        int anio;
        cout<<"Digite el numero del año en el que vendra"<<endl;
        cin >>anio;
        if( anio<1900)
            throw "El anio digitado es erroneo";
        int hora;
        cout<<"Digite la hora en la que vendra"<<endl;
        cout<<"Formato militar, sin coma ni puntos"<<endl;
        cin >>hora;
        if( hora<0 && hora>2400)
            throw "La Hora digitada es erronea";
        DTFecha res=DTFecha(dia,mes,anio,hora);
        return res;  
}



int main()
{   
    Factory* fabrica = fabrica->getInstancia();
    IcontroladorFecha * IFecha=fabrica->getIcontroladorFecha();
    IcontroladorHostal *IHostal=fabrica->getIcontroladorHostal();
    IcontroladorReserva *IReserva=fabrica->getIcontroladorReserva();
    IcontroladorUsuario *IUsuario=fabrica->getIcontroladorUsuario();
    bool iterarWhile=true;
    cout << "Bienvenido" << endl;
	while(iterarWhile){
        principiowhile:
        ImprimirOpciones();
		int FuncionSelecionada = 0; 
		cin >> FuncionSelecionada;
		switch (FuncionSelecionada) {
                case 1:{  //ALTA USUARIO
                    cout << "Alta Usuario"  << endl;        
                    cout<< "Digite su nombre"<<endl;
                    string nombre;
                    cin.ignore();
                    cin>>nombre;
                    cout<< "Digite su contraseña"<<endl;
                    string password;
                    cin>>password;
                    cout<< "Digite su mail"<<endl;
                    string mail;
                    cin>>mail;
                    cout<< "Digite 1 si es un Empleado, de lo contrario 0"<<endl;
                    int esEmpleado;
                    cin>>esEmpleado;
                    if(esEmpleado){
                        int TrabajoSeleccionado;
                        cout<< "Digite la Funcion a realizar por el empleado:"<<endl;
                        cout<< "1 Limpieza"<<endl;
                        cout<< "2 Administracion"<<endl;
                        cout<< "3 Recepcion"<<endl;
                        cout<< "4 Infraestructura"<<endl;
                        cin>> TrabajoSeleccionado;
                        CargoEmp cargoEmpleado;
                        switch(TrabajoSeleccionado){
                            case 1:
                                cargoEmpleado=Limpieza;
                                break;
                            case 2:
                                cargoEmpleado=Administracion;
                                break;
                            case 3:
                                cargoEmpleado=Recepcion;
                                break;
                            case 4:
                                cargoEmpleado=Infraestructura;
                                break;}
                            //EMPIEZO A LLAMAR A LAS FUNCIONES DEL CONTROLADOR
                             DTEmpleado *dtusuario=IUsuario->NuevoEmpleado(mail,password,nombre,cargoEmpleado);
                            // bool salir=true,pedirDatos=false;
                            // while(salir){
                            //     map<string,Empleado*>mEmpleado=IUsuario->getEmpleados();
                            //     map<string,Huesped*>mHuesped=IUsuario->getHuespedes();
                            //     if(mEmpleado.find(mail)==mEmpleado.end() && mHuesped.find(mail)==mHuesped.end())
                               
                            //  }

                            bool excepcion = false;
                            
                            try{
                                IUsuario->ConfirmarAltaEmpleado(dtusuario); 
                                cout<<"Se dio de alta el empleado:"<<endl;
                                dtusuario->imprimir();                               
                            }catch(...){

                                cout<< "Hay otro usuario con ese mail, digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
                                int booleano;
                                cin>>booleano;

                                while((booleano != 1) && (booleano != 0)){
                                    cout<< "Por favor digite 1 o 0:"<<endl;
                                    cin>>booleano;
                                }

                                if(booleano == 1){

                                    bool actualizacionExitosa = false; //flag para salir del while siguiente

                                    while(!actualizacionExitosa){
                                        cout<<"Escriba el nuevo mail:"<<endl;
                                        cin>>mail;
                                        try{
                                            IUsuario->ActualizarMail(dtusuario, mail);
                                            actualizacionExitosa = true; //salgo del while
                                            IUsuario->ConfirmarAltaEmpleado(dtusuario);
                                            cout<<"Se dio de alta el empleado:"<<endl;
                                            dtusuario->imprimir();
                                        }catch(...){
                                            cout<< "Hay otro usuario con ese mail, digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
                                            cin>>booleano;

                                            while((booleano != 1) && (booleano != 0)){
                                                cout<< "Por favor digite 1 o 0:"<<endl;
                                                cin>>booleano;
                                            }

                                            if(booleano == 1){
                                                actualizacionExitosa = false;//vuelvo a intentar actualizar el mail
                                            }else{
                                                actualizacionExitosa = true; //salgo del while
                                                IUsuario->CancelarUsuario(dtusuario);
                                            }
                                        }
                                    }
                                }else{
                                    IUsuario->CancelarUsuario(dtusuario);
                                }
                            }
                        } 
                        else{
                            int esFinger;
                            bool finger;
                            cout<< "Digite 1 si estudia en la FING, de lo contrario 0"<<endl;
                            cin>>esFinger;
                            if(esFinger==1)
                                finger=true;
                            else   
                                finger=false;
                            DTHuesped *dtusuario=IUsuario->NuevoHuesped(mail,password,nombre,finger);

                            try{
                                IUsuario->ConfirmarAltaHuesped(dtusuario); 
                                cout<<"Se dio de alta el huesped:"<<endl;
                                dtusuario->imprimir();                               
                            }catch(...){

                                cout<< "Hay otro usuario con ese mail, digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
                                int booleano;
                                cin>>booleano;

                                while((booleano != 1) && (booleano != 0)){
                                    cout<< "Por favor digite 1 o 0:"<<endl;
                                    cin>>booleano;
                                }

                                if(booleano == 1){

                                    bool actualizacionExitosa = false; //flag para salir del while siguiente

                                    while(!actualizacionExitosa){
                                        cout<<"Escriba el nuevo mail:"<<endl;
                                        cin>>mail;
                                        try{
                                            IUsuario->ActualizarMail(dtusuario, mail);
                                            actualizacionExitosa = true; //salgo del while
                                            IUsuario->ConfirmarAltaHuesped(dtusuario);
                                            cout<<"Se dio de alta el huesped:"<<endl;
                                            dtusuario->imprimir();
                                        }catch(...){
                                            cout<< "Hay otro usuario con ese mail, digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
                                            cin>>booleano;

                                            while((booleano != 1) && (booleano != 0)){
                                                cout<< "Por favor digite 1 o 0:"<<endl;
                                                cin>>booleano;
                                            }

                                            if(booleano == 1){
                                                actualizacionExitosa = false;//vuelvo a intentar actualizar el mail
                                            }else{
                                                actualizacionExitosa = true; //salgo del while
                                                IUsuario->CancelarUsuario(dtusuario);
                                            }
                                        }
                                    }
                                }else{
                                    IUsuario->CancelarUsuario(dtusuario);
                                }
                            }
                        }
                }
                break;//FIN ALTA USUARIO 
                case 2:{ //ALTA DE HOSTAL
                    cout << "Alta de Hostal"  << endl;
                    cout<< "Digite el nombre del Hostal"<<endl;
                    string nombre;
                    cin>>nombre;
                    cout<< "Digite la direccion del Hostal"<<endl;
                    string direccion;
                    cin>>direccion;
                    cout<< "Digite el Telefono del Hostal"<<endl;
                    string Telefono;
                    cin>>Telefono;
                    bool excepcion = false;
                    
                    DTHostal *nuevo = IHostal->nuevoHostal(nombre,direccion,Telefono);
                    
                    try {
                        
                        IHostal->confirmarAltaHostal(nuevo);
                        cout<< "Se registro el nuevo hostal"<<endl;
                    } catch(const char* msj){
                        cout<< msj <<endl;
                        IHostal->cancelarAltaHostal(nuevo);
                    }
                    
                        
                    
                }//FIN ALTA HOSTAL
                break;
                case 3:{//ALTA DE HABITACION
                    cout<<"Alta de Habitacion"<<endl;
                    vector<DTHostal> listaHostales = IHostal->obtenerHostales();

                    if(listaHostales.empty()){
                        cout<<"No hay hostales registrados en el sistema para hacer el alta."<<endl;
                    }else{
                        cout<<"Digite el nombre del Hostal de la lista al que le registrará una nueva Habitacion:"<<endl;

                        int i = 0;

                        while(i < listaHostales.size()){
                            string direccionHos = listaHostales[i].getDireccion();
                            string nombreHos = listaHostales[i].getNombre();
                            string telefonoHos = listaHostales[i].getTelefono();

                            cout<<"Hostal "<<i<<": \n"<<endl;
                            cout<<"Nombre: "<<nombreHos<<endl;
                            cout<<"Direccion: "<<direccionHos<<endl;
                            cout<<"Telefono: "<<telefonoHos<<"\n"<<endl;

                            i = i + 1;
                            
                        }
                        

                        string nombreHos;
                        cout<<"Hostal elegido: "<<endl;
                        cin>>nombreHos;
                        
                        DTHostal* DThostalElegido = IHostal->elegirHostal(nombreHos);
                        
                        

                        string nombreElegido = DThostalElegido->getNombre();

                        //necesito los objetos Hostal para recorrerlos y conseguir el hostal con el nombre nombreElegido
                        map<string, Hostal *> mapaHostales = IHostal->getMapaHostal();
                        
                        //consigo el hostalElegido en el mapaHostales
                        Hostal * hostalElegido = mapaHostales.find(nombreElegido)->second;

                        cout<<"Ingrese el numero de habitacion a agregar: "<<endl;
                        int numH; 
                        cin>>numH; 
                        //tengo que revisar que el numero de habitacion a agregar no esté registrado ya
                        map<int, Habitacion*> mapaHabitacionesHostal = hostalElegido->getMapaHabitaciones();

                        while(mapaHabitacionesHostal.find(numH) != mapaHabitacionesHostal.end()){
                            cout<<"Ya hay una habitacion con ese numero registrada en el hostal, ingrese otro numero: "<<endl;
                            cin>>numH; 
                        }

                        int precioH, capH;
                        cout<<"Precio de la habitacion: "<<endl;
                        cin>>precioH;
                        cout<<"Capacidad de la habitacion: "<<endl;
                        cin>>capH;

                        DTHabitacion* room = IHostal->nuevaHabitacion(numH, precioH, capH); 

                        
                        cout<<"¿Confirma el alta de la nueva habitacion? Digite 1 en caso de que si, 0 si no."<<endl;
                        room->imprimir();

                        int booleano = 4;

                        while((booleano != 1) && (booleano != 0)){
                            cin>>booleano;
                            if((booleano != 1) && (booleano != 0)){
                                cout<<"Digite 1 en caso de que si, 0 si no. No se acepta otro numero."<<endl;
                            }
                        }

                        if(booleano == 1){
                            IHostal->confirmarAltaHabitacion(room);
                            cout<<"Alta de habitacion confirmada."<<endl;
                        }else{
                            IHostal->cancelarAltaHabitacion(room);
                            cout<<"Alta de habitacion cancelada."<<endl;
                        }
                    }

                    
                    
                }//FIN ALTA HABITACION
                    break;
                case 4:{//ASIGNAR EMPLEADO A HOSTAL
                        bool excepcion=false;
                        vector<DTHostal> impHos;
                        try{
                            impHos=IHostal->obtenerHostales();
                            for (int i=0; i<impHos.size(); i++){
                                impHos[i].imprimir();
                                cout<<endl; 
                            }
                            cout<<"Ingrese el nombre del hostal al que quiere asignar el empleado" <<endl;
                            string hostal;
                        elegirHostal:  //label   
                            cin>>hostal; //Nombre del hostal
                            try{                            
                                IHostal->elegirHostal(hostal); //esto lo unico que hace es que el sistema se acuerda del nombre del hostal
                                try{
                                    vector<DTEmpleado> impEmpl=IUsuario->obtenerEmpleadoHostal(); //Devuelve los empleados que no esten asignados a un hostal
                                    for (int i=0; i<impEmpl.size(); i++){
                                        impEmpl[i].imprimir();
                                        cout<<endl; 
                                    }
                                    int repetir=1;
                                    while (repetir==1){
                                        cout<<"Ingrese el mail del empleado que desea asignar al hostal"<<endl;
                                        string mail;
                                        cin>>mail;

                                        int TrabajoSeleccionado;
                                        cout<< "Digite la Funcion a realizar por el empleado:"<<endl;
                                        cout<< "1 Limpieza"<<endl;
                                        cout<< "2 Administracion"<<endl;
                                        cout<< "3 Recepcion"<<endl;
                                        cout<< "4 Infraestructura"<<endl;
                                        cin>> TrabajoSeleccionado;
                                        CargoEmp cargoEmpleado;
                                        switch(TrabajoSeleccionado){
                                            case 1:
                                                cargoEmpleado=Limpieza;
                                                break;
                                            case 2:
                                                cargoEmpleado=Administracion;
                                                break;
                                            case 3:
                                                cargoEmpleado=Recepcion;
                                                break;
                                            case 4:
                                                cargoEmpleado=Infraestructura;
                                                break;}
                                        IUsuario->ActualizarCargo(mail,cargoEmpleado);
                                        cout<<"Presione 1 si quiere confirmar la asignacion o 0 en caso de querer cancelarla"<<endl;
                                        int conf;
                                        cin>>conf;
                                        if (conf==1){
                                            IUsuario->AsignarEmpleado();
                                        }
                                        else {
                                            IUsuario->cancelarAsignacionEmpleado();
                                        }

                                        cout<<"Ingrese 1 si quiere seguir asignando empleados al hostal o 0 en caso contrario"<<endl;
                                        
                                        cin>>repetir;
                                    }
                                }catch(const char* msj){
                                    cout<<msj<<endl; //Si estoy en esta opcion salgo si o si                                    
                                }
                            }catch (const char* msj){
                                cout<<msj<<endl;
                                cout <<"Presione 1 si desea volver a ingresar el nombre o 0 si desea salir:" <<endl;
                                int seguir;
                                cin>>seguir;
                                if(seguir==1){ //Doy la opcion de reingresar el mail del hostal
                                    cout<<"Ingrese nuevamente el nombre del hostal"<<endl;
                                    goto elegirHostal;                                    
                                }
                                
                            } 

                        }catch(const char* msj){
                            cout<<msj<<endl;                        
                            }                                              
                        
                       
                    
                    cout<<"debug"<<endl;
                }//FIN ASIGNAR EMPLEADO A HOSTAL
                    break;
                case 5:{//REALIZAR RESERVA
                    cout<<"Ha digitado realizar Reserva"<<endl<<endl; 
                    string mail;    //elegirUsuario
                    cout<<"Digite su mail"<<endl;
                    cin>>mail;
                    elegirUsuarioRR1://
                    try{
                        map<string,DTHuesped> mHuesped=IUsuario->getHuespedes();
                        if(mHuesped.find(mail)==mHuesped.end())
                            throw "No hay huesped con ese mail";
                        IUsuario->setEmail(mail);
                    }
                    catch(...){
                        cout<<"No hay ningun huesped con ese nombre"<<endl;
                        goto elegirUsuarioRR1;
                    }//obtenerCalificaciones
                    vector<DTCalificacion>vCalificacion=IHostal->obtenerCalificaciones();
                    for(size_t it=0;it<vCalificacion.size();it++){
                        DTCalificacion cal=vCalificacion.at(it);
                        cal.imprimir();
                        cal.~DTCalificacion();
                    }
                    vCalificacion.clear();
                    vector<DTHostal>vHostales=IHostal->obtenerHostales();//obtenerHostales
                    for(size_t it=0;it<vHostales.size();it++){
                        DTHostal ItHostal=vHostales.at(it);
                        ItHostal.imprimir();
                        ItHostal.~DTHostal();
                    }
                    vHostales.clear();
                    string nHostal;
                    cout<<"Digite el nombre del hostal"<<endl;//elegirHostal
                    cin>>nHostal;
                    bool pedirFecha=true;//obtenerHabitaciones
                    DTFecha in;
                    DTFecha out;
                    while(pedirFecha){
                        try{
                            DTFecha in=digiteFecha();
                            DTFecha out=digiteFecha();
                            pedirFecha=false;
                        }
                        catch(...){
                            cout<<"La fecha digitada es erronea"<<endl;
                        }
                    }
                    vector<DTHabitacion>vHabitacion=IHostal->obtenerHabitaciones(in,out);
                    int nHabitacion;//elegirHabitacion
                    cout<<"Digite la habitacion deseada"<<endl;
                    cin>>nHabitacion;
                    DTHabitacion room=IHostal->elegirHabitacion(nHabitacion);
                    int esGrupal;
                    cout<<"Digite 1 si desea realizar una reserva grupal, 0 en otro caso"<<endl;
                    cin>>esGrupal;
                    if(esGrupal==1)//CASO RESERVA GRUPAL
                        goto grupalRR;
                    int confirmar;
                    cout<<"Digite uno si quiere confirmar la reserva"<<endl;
                    cin>>confirmar;
                    if(confirmar==1)
                        IUsuario->confirmarAltaReservaIndividual();
                    else
                        IUsuario->cancelarReserva();
                    grupalRR:
                    int cantidad;
                    cout<<"Digite la cantidad de huespedes que desea ingresar"<<endl;
                    cin>>cantidad;
                    for(int i=0;i<cantidad;i++){
                        elegirUsuarioRR2:
                        try{
                            cout<<"Digite el mail de otro huesped"<<endl;
                            cin>>mail;
                            IUsuario->elegirHuesped(mail);
                        }catch(...){
                            cout<<"No hay un huesped con ese mail"<<endl;
                        }
                    }
                    cout<<"Digite uno si quiere confirmar la reserva"<<endl;
                    cin>>confirmar;
                    if(confirmar==1)
                        IUsuario->confirmarAltaReservaIndividual();
                    else
                        IUsuario->cancelarReserva();
                }//FIN REALIZAR RESERVA
                    break;
                case 6:{//CONSULTA TOP 3 HOSTALES
                    vector<string> mejores3;
                    try{
                        mejores3=IHostal->mejoresTresHostales();
                        for (int i=0; i<mejores3.size(); i++){
                            cout<<(i+1);
                            cout<< ". "; 
                            cout<< mejores3[i] <<endl;
                        }
                        cout<<endl;
                        cout<<"Presione 1 si desea ver los detalles de algun hostal"<<endl;
                        int i;
                        cin>>i;
                        if (i==1){
                            cout<<"Digite su nombre: "<<endl;
                            nombre_existente:
                            string hostal;
                            cin>>hostal;
                            try{
                                vector<DTCalificacion> califs=IHostal->detallesHostal(hostal);
                                for (int j=0; j<califs.size(); j++){
                                    califs[j].imprimir();
                                }
                            }catch (const char* msj){
                                cout<< msj <<endl;
                                cout<< "Si desea volver a ingresar el nombre presione 1"<<endl;
                                int repetir;
                                cin>>repetir;
                                if (repetir==1){
                                    cout<< "Ingrese el nombre nuevamente"<<endl;
                                    goto nombre_existente;
                                }
                            }
                        }

                    }catch(const char* msj){
                        cout<< msj <<endl;
                    }
                }//FIN CONSULTA TOP 3 HOSTALES
                    break;
                case 7:{// REGISTRAR ESTADIA
                }//FIN REGISTRAR ESTADIA
                    break;
                case 8:{// FINALIZAR ESTADIA
                }//FIN FINALIZAR ESTADIA
                    break;
                case 9:{// CALIFICAR ESTADIA
                }//FIN CALIFICAR ESTADIA
                    break;
                case 10:{// COMENTAR CALIFICACION
                }//FIN COMENTAR CALIFICACION
                    break;
                case 11:{// CONSULTA USUARIO
                    vector<DTEmpleado> empleados;
                    vector<DTHuesped> huespedes;
                    try{
                        empleados=IUsuario->obtenerEmpleados();
                        huespedes=IUsuario->obtenerHuespedes();
                        for(int i=0; i<empleados.size(); i++){
                            cout<< empleados[i].getMail() <<endl;
                        }
                        for (int i=0; i<huespedes.size(); i++){
                            cout<< huespedes[i].getMail() <<endl;
                        }
                        cout<<endl;
                        cout<<"Digite el mail del usuario del que quiera ver los detalles"<<endl;
                        string mail;
                        cin>>mail;
                        DTUsuario *u=IUsuario->elegirUsuario(mail);
                        DTEmpleado *empl=dynamic_cast<DTEmpleado* >(u);                        
                        if (empl!=NULL){
                            empl->imprimir();
                        }
                        DTHuesped *hues=dynamic_cast<DTHuesped* >(u);
                        if (hues!=NULL){
                            hues->imprimir();
                        }
                        

                    }catch(const char* c){

                    }
                }//FIN CONSULTA USUARIO
                    break;
                case 12:{// CONSULTA DE HOSTAL
                    vector<DTHostal> impHos;
                    vector<DTCalificacion> impCalif;
                    vector<DTHabitacion> impHab;
                    vector<DTReserva> impRes;
                    try{
                        impHos=IHostal->obtenerHostales();
                        for (int i=0; i<impHos.size(); i++){
                            impHos[i].imprimir();
                            cout<<endl; 
                        };
                        cout<<"Ingrese el nombre del hostal del que quiere ver la informacion" <<endl;
                        string hostal;
                        cin>>hostal; //Nombre del hostal
                        try{                            
                            IHostal->elegirHostal(hostal); //esto lo unico que hace es que el sistema se acuerda del nombre del hostal
                        }catch(const char* msj){
                            cout<< msj <<endl;
                        }
                        int prom;
                        try{
                            impCalif=IHostal->obtenerCalificaciones();
                            for (int i=0; i<impCalif.size(); i++){
                                impCalif[i].imprimir();
                                cout<<endl; 
                            };
                            prom=IHostal->obtenerPromedioCalificaciones();
                            cout<<"El promedio de calificaciones es: " ;
                            cout<< prom <<endl;
                            
                        }catch(const char* msj){
                            cout<< msj <<endl;
                        }
                        try{
                            impHab=IHostal->obtenerInfoHabitaciones();
                            for (int i=0; i<impHab.size(); i++){
                                impHab[i].imprimir();
                                cout<<endl; 
                            };
                        }catch(const char* msj){
                            cout<< msj <<endl;
                        }
                        try{
                            impRes=IHostal->obtenerReservasHostal();
                            for (int i=0; i<impRes.size(); i++){
                                impRes[i].imprimir();
                                cout<<endl; 
                            };
                        }catch(const char* msj){
                            cout<< msj <<endl;
                        }
                    }catch(const char* msj){
                        cout<< msj<< endl;
                    }
                    IHostal->liberarMemoria();                   
                                               
                    
                }//FIN CONSULTA DE HOSTAL
                    break;
                case 13:{// CONSULTA DE RESERVA
                }//FIN CONSULTA DE RESERVA
                    break;
                case 14:{// CONSULTA DE ESTADIA
                }//FIN CONSULTA DE ESTADIA
                    break;
                case 15:{// BAJA RESERVA
                }// FIN BAJA RESERVA
                    break;
                default:{
                    iterarWhile=false;
                }  
            }//end switch
	    }//end while
	return 0;
}
