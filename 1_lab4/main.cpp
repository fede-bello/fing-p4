
#include "Controladores/include/controladorUsuario.h"
#include "Interfaces/Factory.h"

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
                    controladorUsuario *cUsuario=controladorUsuario::getInstance();
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
                        cout<< "Digite la FuncionSelecionada correcta"<<endl;
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
                                cargoEmpleado=Infrasetructura;
                                break;}
                                //EMPÏEZO A LLAMAR A LAS FUNCIONES DEL CONTROLADOR
                                DTEmpleado *dtusuario=cUsuario->NuevoEmpleado(mail,password,nombre,cargoEmpleado);
                            try{
                                
                            }catch(...){
                                cout<< "Hay otro usuario con ese mail"<<endl;
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
                            DTHuesped *dtusuario=cUsuario->NuevoHuesped(mail,password,nombre,finger);
                            
                        }
                    }
                    break;//FIN ALTA USUARIO 
                case 2:{ //ALTA DE HOSTAL
                    cout << "Alta de Hostal"  << endl;
                    bool salir=true;
                    cout<< "Digite el nombre del Hostal"<<endl;
                    string nombre;
                    cin>>nombre;
                    cout<< "Digite la direccion del Hostal"<<endl;
                    string direccion;
                    cin>>direccion;
                    cout<< "Digite el Telefono del Hostal"<<endl;
                    string Telefono;
                    cin>>Telefono;
                    controladorHostal *cHostal=controladorHostal::getInstance();
                    try {
                        cHostal->nuevoHostal(nombre,direccion,Telefono);
                        salir=false;
                    }
                    catch(...){
                        cout<< "Ya hay un hostal con ese nombre"<<endl;
                    }
                }//FIN ALTA HOSTAL
                    break;
                case 3:{//ALTA DE HABITACION
                    IcontroladorHostal *cHostal = fabrica->getIcontroladorHostal();


                    cout << "Alta de Habitacion"  << endl;
                    cout << "Digite el nombre del Hostal de la lista al que le registrará una nueva Habitacion:"  << endl;

                    vector<DTHostal> listaHostales = cHostal->obtenerHostales();
                    listaHostales


                    




                }//FIN ALTA HABITACION
                    break;
                    case 4:{//ASIGNAR EMPLEADO A HOSTAL
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
