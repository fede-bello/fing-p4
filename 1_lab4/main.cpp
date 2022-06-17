
#include "Controladores/include/controladorUsuario.h"
#include "Interfaces/include/Factory.h"

////////////////////////////////
////////  CASOS DE USO /////////
///////////////////////////////
//Comentar Calificacion
//Consulta de Usuario
//Consulta de Hostal
//Consulta de Reserva
//Consulta de Estadia
//Baja de Reserva

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



int main()
{   
    Factory* fabrica = fabrica->getInstancia();
    bool iterarWhile=true;
    cout << "Bienvenido" << endl;
	while(iterarWhile){
        ImprimirOpciones();
		int FuncionSelecionada = 0; 
		cin >> FuncionSelecionada;
		switch (FuncionSelecionada) {
                case 1:{  //ALTA USUARIO
                    IcontroladorUsuario *iUsuario=fabrica->getIcontroladorUsuario();
                    cout << "Alta Usuario"  << endl;        
                    cout<< "Digite su nombre"<<endl;
                    string nombre;
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
                            DTEmpleado *dtusuario=iUsuario->NuevoEmpleado(mail,password,nombre,cargoEmpleado);
                            // bool salir=true,pedirDatos=false;
                            // while(salir){
                            //    map<string,Empleado*>mEmpleado;
                            //    map<string,Huesped*>mHuesped;
                               
                            // }

                            bool excepcion = false;
                            
                            try{
                                iUsuario->ConfirmarAltaEmpleado(dtusuario); 
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
                                            iUsuario->ActualizarMail(dtusuario, mail);
                                            actualizacionExitosa = true; //salgo del while
                                            iUsuario->ConfirmarAltaEmpleado(dtusuario);
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
                                                iUsuario->CancelarUsuario(dtusuario);
                                            }
                                        }
                                    }
                                }else{
                                    iUsuario->CancelarUsuario(dtusuario);
                                }

                                
                            }

                        } 
                        else{
                            int esFinger;
                            bool finger;
                            cout<< "Digite 1 si estudia en la FING, de lo contrario 0"<<endl;
                            if(esFinger==1)
                                finger=true;
                            else   
                                finger=false;
                            DTHuesped *dtusuario=iUsuario->NuevoHuesped(mail,password,nombre,finger);
                            try{
                                
                                
                            }catch(...){
                                cout<< "Hay otro usuario con ese mail"<<endl;
                            }
                            
                        }
                }
                break;//FIN ALTA USUARIO 
                case 2:{ //ALTA DE HOSTAL
                    IcontroladorHostal *cHostal = fabrica->getIcontroladorHostal();
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
                    DTHostal *nuevo = cHostal->nuevoHostal(nombre,direccion,Telefono);
                    try {
                        cHostal->nuevoHostal(nombre,direccion,Telefono);
                    }
                    catch(...){
                        excepcion = true;
                    }
                    if(excepcion){
                        cout<< "Se encuentra registrado un hostal con ese nombre"<<endl;
                        cHostal->cancelarAltaHostal(nuevo);
                    }else{
                        cout<< "Se registro el nuevo hostal"<<endl;
                        cHostal->confirmarAltaHostal(nuevo);
                    }
                }//FIN ALTA HOSTAL
                break;
                case 3:{//ALTA DE HABITACION
                    IcontroladorHostal *cHostal = fabrica->getIcontroladorHostal();


                    cout<<"Alta de Habitacion"<<endl;
                    vector<DTHostal> listaHostales = cHostal->obtenerHostales();

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
                        
                        DTHostal* DThostalElegido = cHostal->elegirHostal(nombreHos);
                        
                        

                        string nombreElegido = DThostalElegido->getNombre();

                        //necesito los objetos Hostal para recorrerlos y conseguir el hostal con el nombre nombreElegido
                        map<string, Hostal *> mapaHostales = cHostal->getMapaHostal();
                        
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

                        DTHabitacion* room = cHostal->nuevaHabitacion(numH, precioH, capH); 

                        
                        cout<<"¿Confirma el alta de la nueva habitacion? Digite 1 en caso de que si, 0 si no."<<endl;
                        room->Imprimir();

                        int booleano = 4;

                        while((booleano != 1) && (booleano != 0)){
                            cin>>booleano;
                            if((booleano != 1) && (booleano != 0)){
                                cout<<"Digite 1 en caso de que si, 0 si no. No se acepta otro numero."<<endl;
                            }
                        }

                        if(booleano == 1){
                            cHostal->confirmarAltaHabitacion(room);
                            cout<<"Alta de habitacion confirmada."<<endl;
                        }else{
                            cHostal->cancelarAltaHabitacion(room);
                            cout<<"Alta de habitacion cancelada."<<endl;
                        }
                    }

                    
                    
                }//FIN ALTA HABITACION
                    break;
                case 4:{//ASIGNAR EMPLEADO A HOSTAL
                        cout<<"debug"<<endl;
                }//FIN ASIGNAR EMPLEADO A HOSTAL
                    break;
                case 5:{//REALIZAR RESERVA
                }//FIN REALIZAR RESERVA
                    break;
                case 6:{//CONSULTA TOP 3 HOSTALES
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
                }//FIN CONSULTA USUARIO
                    break;
                case 12:{// CONSULTA DE HOSTAL
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
