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
    cout << "15 -> Baja de Reserva" << endl;
    cout << "16 -> Carga de datos" <<endl<<endl;
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
                            }catch(const char* msj){
                                cout<< msj<<endl;
                                cout<< "Digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
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
                                        }catch(const char* msj){
                                            cout<< msj<<endl;
                                            cout<< "Digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
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
                            }catch(const char* msj){
                                cout<< msj<< endl;
                                cout<< "Digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
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
                                        }catch(const char* msj){
                                            cout<< msj <<endl;
                                            cout<< "Digite 1 para cambiar el mail, 0 para cancelar el alta:"<<endl;
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

                    for (int i=0; i<listaHostales.size(); i++){
                        listaHostales[i].imprimir();
                        cout<<endl; 
                    }

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
                /*
                    vector<DTHostal> impHos;
                    try{
                        impHos=IHostal->obtenerHostales();
                        int prom;
                        for (int i=0; i<impHos.size(); i++){
                            impHos[i].imprimir();
                            cout<<endl;
                            IHostal->elegirHostal(impHos[i].getNombre()); //Esto es para recordar el nombre del hostal, ya que obtenerPromedioCalificaciones solo funciona si hay un hostal recordado
                            try{
                                prom=IHostal->obtenerPromedioCalificaciones();
                                cout<<"El promedio de calificaciones es: " ;
                                cout<< prom<<endl;
                            }catch(const char* endl){
                                cout<<msj<<endl;
                            }
                        };
                        cout<<"Ingrese el nombre del hostal en el que quiera realizar la reserva" <<endl;
                        string hostal;
                        cin>>hostal; //Nombre del hostal
                        IHostal->elegirHostal(hostal);
                        cout<<"Indique la fecha de Check In" <<endl;
                        DTFecha In=digiteFecha();
                        cout<<"Indique la fecha de Check Out" <<endl;
                        DTFecha Out=digiteFecha();
                        try{
                            vector<DTHabitacion> impHab=IHostal->obtenerHabitaciones(In,Out);
                            for(int i=0; i<impHab.size(); i++){
                                //IMPRIMIR LAS HABITACIONES QUE RECIBI, SI NO HAY HABITACIONES DEVOLVER EXCEPCION Y SEGUIR A PARTIR DE ELEGIR HABITACION
                            }
                        }

                    }
                */  
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
                    cout<<"Registrar Estadia"<<endl;

                    vector<DTHostal> hostales = IHostal->obtenerHostales();

                    for (int i=0; i<hostales.size(); i++){
                        hostales[i].imprimir();
                        cout<<endl; 
                    }

                    cout<<"Elija el hostal donde se realizará la estadía:"<<endl;
                    string nombreHosElegido;
                    cin>>nombreHosElegido;
                    
                    bool estaHostalElegido = false; //Flag para que si no está pueda volver

                    DTHostal * DTHostalElegido;

                    while(!estaHostalElegido){
                        try{
                            DTHostalElegido = IHostal->elegirHostal(nombreHosElegido);
                            estaHostalElegido = true; //si no fue al catch pongo la flag en true para que no vuelva a entrar al while
                        }catch(const char* msj){
                            cout<<msj<<endl;
                            cout<<"Elija un hostal de la lista:"<<endl;

                            for (int i=0; i<hostales.size(); i++){
                                hostales[i].imprimir();
                                cout<<endl; 
                            }

                            cin>>nombreHosElegido;
                        }
                    }   

                    Hostal * hostalElegido = new Hostal(DTHostalElegido->getNombre(), DTHostalElegido->getDireccion(), DTHostalElegido->getTelefono());

                    cout<<"Ingrese el mail del huesped a registrar:"<<endl;
                    string email;
                    cin>>email;

                    vector<DTReserva> vectRes = IHostal->obtenerReservasHuesped(email, nombreHosElegido);
                    
                    for (int i=0; i<vectRes.size(); i++){
                        vectRes[i].imprimir();
                        cout<<endl; 
                    }
                    
                    cout<<"Ingrese el codigo de reserva a registrar:"<<endl;
                    int codigoResElegido;
                    cin>>codigoResElegido;

                    bool estaReservaElegida = false; 
                    bool flagSeleccionadaOk = false; //Flag para que si no está pueda volver
                    int iter = 0;

                    while(!flagSeleccionadaOk){
                        while((iter < vectRes.size()) && (!estaReservaElegida)){
                            estaReservaElegida = (vectRes[iter].getCodigo() == codigoResElegido);
                            iter++;
                        }

                        if(!estaReservaElegida){
                            cout<<"Ingrese un codigo de reserva de los de la lista de reservas:"<<endl;

                            for (int i=0; i<vectRes.size(); i++){
                                vectRes[i].imprimir();
                                cout<<endl; 
                            }
                            
                            cin>>codigoResElegido;

                        }else{
                            flagSeleccionadaOk = true; //salgo del while porque está ok el codigo de reserva elegido
                        }
                    }
                    
                    //tengo que crear la estadia
                    DTEstadia a_registrar = DTEstadia(IHostal->getCantidadEstadias(), IFecha->getFechaActual(), DTFecha());

                    IReserva->registrarEstadia(codigoResElegido);
                    
                    IReserva->actualizarEstadoReservaCerrada(codigoResElegido);

                    // DTHostal DTHosElegido = 

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
                    vector<DTHostal> impHos;
                    vector<DTReserva> impRes;
                    vector<DTHuesped> impHues;
                    bool noHostal=false;
                    try{
                        impHos=IHostal->obtenerHostales();
                        for (int i=0; i<impHos.size(); i++){
                            impHos[i].imprimir();
                            cout<<endl; 
                        };
                        cout<<"Ingrese el nombre del hostal del que quiere consultar la reserva" <<endl;
                        while (!noHostal){
                            string hostal;
                            cin>>hostal; //Nombre del hostal
                            try{
                                IHostal->elegirHostal(hostal);
                                noHostal=false;
                                try{
                                    impRes=IHostal->obtenerReservasHostal();
                                    int hab;
                                    for (int i=0; i<impRes.size(); i++){
                                        impRes[i].imprimir();
                                        cout<<endl; 
                                        hab=IHostal->habitacionDeReserva(hostal,impRes[i]);
                                        cout << "Habitacion: ";
                                        cout<<hab<<endl;
                                        impHues=IHostal->huespedesReserva(hostal,impRes[i]);
                                        cout<<"Huespedes: ";
                                        for(int j=0; j<impHues.size(); j++){
                                            impHues[j].imprimir(); 
                                        }

                                    };
                                    
                                    
                                    
                                }catch(const char* msj){
                                    cout<< msj<<endl;
                                }



                            }catch(const char* msj){
                                cout<< msj<< endl;
                                cout<< "Vuelva a ingresar el nombre del hostal" <<endl;
                            }                           
                            
                        }               
                        
                    }catch(const char* msj){
                        cout<< msj<< endl;
                    } 


                }//FIN CONSULTA DE RESERVA
                    break;
                case 14:{// CONSULTA DE ESTADIA
                    vector<DTHostal> impHos;
                    vector<DTEstadia> impEst;
                    vector<DTReserva> impRes;
                    cout<<"Consulta de estadia:" <<endl;

                    bool noHostal = false;
                    try{
                        impHos=IHostal->obtenerHostales();
                        for (int i=0; i<impHos.size(); i++){
                            impHos[i].imprimir();
                            cout<<endl; 
                        };
                        cout<<"Ingrese el nombre del hostal del que quiere consultar la estadia" <<endl;
                        while (!noHostal){
                            string hostal;
                            cin>>hostal; //Nombre del hostal
                            try{
                                IHostal->elegirHostal(hostal);
                                noHostal=false;
                                try{
                                    impEst=IHostal->obtenerEstadias(hostal);

                                    int est;
                                    for (int i=0; i<impEst.size(); i++){
                                        //imprimo los datos de la estadia
                                        cout<<impEst[i].getIdentificador()<<endl;
                                        cout<<"CheckIn: ";
                                        impEst[i].getCheckIn().imprimir();
                                        DTFecha a_comparar = DTFecha();
                                        //Me fijo si tiene fecha de checkOut cargada
                                        if(!(a_comparar == impEst[i].getCheckOut())){
                                            cout<<"CheckOut: ";
                                            impEst[i].getCheckOut().imprimir();
                                        }else{
                                            cout<<"La estadia no tiene fecha de checkOut cargada"<<endl;
                                        }
                                        
                                        cout<<"Ingrese el identificador de la estadia por la que quiere consultar:" <<endl;
                                        int codigoEst;
                                        cin>>codigoEst;

                                        try{
                                            IReserva->elegirEstadia(codigoEst);
                                            bool noReserva=false;
                                        }catch(const char* msj){ /////////////FALTA PONER EL THROW EN CONTROLADORRESERVA.CPP EN ELEGIRESTADIA/////////////////////
                                            cout<< msj<< endl;
                                            cout<< "Vuelva a ingresar el codigo de estadia" <<endl;
                                        }

                                    }
                                    
                                    
                                    
                                }catch(const char* msj){
                                    cout<< msj<<endl;
                                }



                            }catch(const char* msj){
                                cout<< msj<< endl;
                                cout<< "Vuelva a ingresar el nombre del hostal" <<endl;
                            }                           
                            
                        }               
                        
                    }catch(const char* msj){
                        cout<< msj<< endl;
                    } 
                }//FIN CONSULTA DE ESTADIA
                    break;
                case 15:{// BAJA RESERVA
                }// FIN BAJA RESERVA
                    break;
                 case 16: {
     //CARGA DE DATOS 

//Datos de prueba Húespedes
     cout << "Cargando Húespedes" << endl;
     IUsuario->ConfirmarAltaHuesped(IUsuario->NuevoHuesped("sofia@mail.com", "123", "Sofía", true));
     IUsuario->ConfirmarAltaHuesped(IUsuario->NuevoHuesped("frodo@mail.com", "123", "Frodo", true));
     IUsuario->ConfirmarAltaHuesped(IUsuario->NuevoHuesped("sam@mail.com", "123", "Sam", false));
     IUsuario->ConfirmarAltaHuesped(IUsuario->NuevoHuesped("merry@mail.com", "123", "Merry", false));
     IUsuario->ConfirmarAltaHuesped(IUsuario->NuevoHuesped("seba@mail.com", "123", "Seba", true));
     //Datos de prueba Empleados
     cout << "Cargando Empleados" << endl;
     IUsuario->ConfirmarAltaEmpleado(IUsuario->NuevoEmpleado("emilia@mail.com", "123", "Emilia", Recepcion));

     IUsuario->ConfirmarAltaEmpleado(IUsuario->NuevoEmpleado("leo@mail.com", "123", "Leonardo", Recepcion));

     IUsuario->ConfirmarAltaEmpleado(IUsuario->NuevoEmpleado("alina@mail.com", "123", "Alina", Administracion));

     IUsuario->ConfirmarAltaEmpleado(IUsuario->NuevoEmpleado("barli@mail.com", "123", "Barliman", Recepcion));

     //Hostels
     cout << "Cargando Hostales" << endl;
     IHostal->confirmarAltaHostal(IHostal->nuevoHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111"));
     IHostal->confirmarAltaHostal(IHostal->nuevoHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512"));
     IHostal->confirmarAltaHostal(IHostal->nuevoHostal("El Pony Pisador", "Bree (Preguntar por Gandalf)", "000"));
     IHostal->confirmarAltaHostal(IHostal->nuevoHostal("Altos de Fing", "Av. del toro 1424", "099892992"));
     IHostal->confirmarAltaHostal(IHostal->nuevoHostal("Caverna Lujosa", "Amaya 2515", "233233235"));

     //Habitaciones
     cout << "Cargando Habitaciones y asignación a Hostales" << endl;
     DTHostal* DThostalElegido = IHostal->elegirHostal("La posada del finger");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(1, 2, 40.0));//Asocia la habitación a   Hostal  HO1

     DThostalElegido = IHostal->elegirHostal("La posada del finger");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(2, 7, 10.0));//Asociar  Hostal  H01

     DThostalElegido = IHostal->elegirHostal("La posada del finger");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(3, 3, 30.0));//Asociar  Hostal  H01

     DThostalElegido = IHostal->elegirHostal("La posada del finger");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(4, 12, 5.0));//Asociar  Hostal  H01

     DThostalElegido = IHostal->elegirHostal("Caverna Lujosa");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(1, 2, 3.0));//Asociar  Hostal   H05

     DThostalElegido = IHostal->elegirHostal("El Pony Pisador");
     IHostal->confirmarAltaHabitacion(IHostal->nuevaHabitacion(1, 5, 9.0));//Asociar  Hostal   H03

     //Empleados a Hostal 
     /*
     cout<<"Asignando empleados a Hostal"<<endl;
     IHostal->elegirHostal("La posada del finger");//Asigno a Emilia H01
     IUsuario->ActualizarCargo("emilia@mail.com",Recepcion);
     IUsuario->AsignarEmpleado();

     IHostal->elegirHostal("Mochileros");//Asigno a Leonardo H02
     IUsuario->ActualizarCargo("leo@mail.com",Recepcion);
     IUsuario->AsignarEmpleado();

     IHostal->elegirHostal("Mochileros");//Asigno a Alina H02
     IUsuario->ActualizarCargo("alina@mail.com",Administracion);
     IUsuario->AsignarEmpleado();

     IHostal->elegirHostal("sador");//Asigno a Barliman H03
     IUsuario->ActualizarCargo("barli@mail.com",Recepcion);
     IUsuario->AsignarEmpleado();*/
     //RESERVAS
     /*
     //Reserva en H01 hab HA1 individual huesped H1

     IUsuario->setEmail("sofia@mail.com");
     DTFecha in=DTFecha(1,5,22,2);
     DTFecha out=DTFecha(10,5,22,10);
     IHostal->elegirHostal("La posada del finger");
     DTHabitacion room=IHostal->elegirHabitacion(1);
     IUsuario->confirmarAltaReservaIndividual();



     cout<<"Reservas cargadas"<<endl;
     */
                 }
     break;                //FIN CARGA DE DATOS
                     default:{
                    iterarWhile=false;
                }
            }//end switch
	    }//end while
	return 0;
}
