
#include "Controladores/include/controladorUsuario.h"

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
    cout << "Ingresar opción:" << endl;
    cout << "0 -> Salir" << endl;
    cout << "1 -> Alta de Usuario " << endl;
    cout << "2 -> Alta de Hostal" << endl;
    cout << "3 -> Alta de Habitacion" << endl;
    cout << "4 -> Asignar empleado a hostal" << endl;
    cout << "5 -> Realizar Reserva" << endl;
    cout << "5 -> Consultar top 3 de hostales" << endl;
    cout << "6 -> Registrar Estadia" << endl;
    cout << "7 -> Finalizar Estadia" << endl;
    cout << "8 -> Calificar Estadia" << endl;
    cout << "9 -> Comentar Calificacion" << endl;
    cout << "10 -> Consulta de Usuario" << endl;
    cout << "11 -> Consulta de Hostal" << endl;
    cout << "12 -> Consulta de Reserva" << endl;
    cout << "13-> Consulta de Estadia" << endl;
    cout << "14 -> Baja de Reserva" << endl<<endl;
}



int main()
{    
	while(true){
        ImprimirOpciones();
		int FuncionSelecionada = 0; 
		cin >> FuncionSelecionada;
		switch (FuncionSelecionada) {
                case 1:{  
                    controladorUsuario *cUsuario=controladorUsuario::getInstance();
                    int esEmpleado;
                    cout << "Alta de Usuario"  << endl;
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
                                break;
                        DTEmpleado *dtusuario=cUsuario->NuevoEmpleado(mail,password,nombre,cargoEmpleado);
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
                    break;//fin case 1
                case 2:{
                    cout << "Alta de Hostal"  << endl;
                    bool salir=true;
                    while(salir)
                    cout<< "Digite el nombre del Hostal"<<endl;
                    string nombre;
                    cin>>nombre;
                    cout<< "Digite la direccion del Hostal"<<endl;
                    string direccion;
                    cin>>direccion;
                    cout<< "Digite el Telefono del Hostal"<<endl;
                    int Telefono;
                    cin>>Telefono;
                    controladorHostal *cHostal=controladorHostal::getInstance();
                    try {
                        cHostal->nuevoHostal(nombre,direccion,Telefono);
                        salir=false;
                    }
                    catch(...){
                        cout<< "Ya hay un hostal con ese nombre"<<endl;
                    }
                    
                }
                    break;
                default:{}
                    break;
                
            }//end switch
	    }//end while
	return 0;
}
