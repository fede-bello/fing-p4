#ABREVIACIONES
DTI= DataType/include
DTS= DataType/src
COI= conceptos/include
COS= conceptos/src
U= Usuario
R=Reserva
C=Controlador
CONTI= controladores/include
CONTS= controladores/src

EJECUTABLES= $(DTS)/DTFecha.o $(DTS)/DT$(U).o $(COS)/$(U).o $(DTS)/DT$(U)Huesped.o $(COS)/$(U)Huesped.o $(COS)/$(U)Empleado.o $(DTS)/DTHostal.o $(COS)/Hostal.o $(DTS)/DTHabitacion.o $(COS)/Habitacion.o $(DTS)/DT$(R).o $(COS)/$(R).o $(DTS)/DT$(R)Individual.o $(COS)/$(R)Individual.o $(DTS)/DT$(R)Grupal.o $(COS)/$(R)Grupal.o $(DTS)/DTEstadia.o $(COS)/Estadia.o $(DTS)/DTCalificacion.o $(COS)/Calificacion.o $(COS)/Sistema.o $(CONTS)/Fecha$(C).o $(CONTS)/Hostal$(C).o $(CONTS)/$(U)$(C).o $(CONTS)/$(R)$(C).o main.o      

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

DTFecha.o: $(DTS)/DTFecha.cpp $(DTI)/DTFecha.h
	g++ -c DTFecha.cpp

DT$(U)Huesped.o: $(DTS)/DT$(U)Huesped.cpp $(DTI)/DT$(U)Huesped.h
	g++ -c DT$(U)Huesped.cpp

$(U)Huesped.o:$(COS)/$(U)Huesped.cpp $(COI)/$(U)Huesped.h
	g++ -c $(U)Huesped.cpp

DTHostal.o:$(DTS)/DTHostal.cpp $(DTI)/DTHostal.h
	g++ -c DTHostal.cpp

Hostal.o:$(COS)/Hostal.cpp $(COI)/Hostal.h
	g++ -c Hostal.cpp

DTHabitacion.o: $(DTS)/DTHabitacion.cpp $(DTI)/DTHabitacion.h
	g++ -c DTHabitacion.cpp

Habitacion.o: $(COS)/Habitacion.cpp $(COI)/Habitacion.h
	g++ -c Habitacion.cpp

DT$(R).o: $(DTS)/DT$(R).cpp $(DTI)/DT$(R).h
	g++ -c DT$(R).cpp 

$(R).o: $(COS)/$(R).cpp $(COI)/$(R).h
	g++ -c $(R).cpp

DT$(R)Individual.o: $(DTS)/DT$(R)Individual.cpp $(DTI)/DT$(R)Individual.h
	g++ -c DT$(R)Individual.cpp

$(R)Individual.o: $(COS)/$(R)Individual.cpp $(COI)/$(R)Individual.h
	g++ -c $(R)Individual.cpp

DT$(R)Grupal.o: $(DTS)/DT$(R)Grupal.cpp $(DTI)/DT$(R)Grupal.h
	g++ -c DT$(R)Grupal.cpp

$(R)Grupal.o: $(COS)/$(R)Grupal.cpp $(COI)/$(R)Grupal.h
	g++ -c $(R)Grupal.cpp

DTEstadia.o: $(DTS)/DTEstadia.cpp $(DTI)/DTEstadia.h
	g++ -c DTEstadia.cpp 

Estadia.o: $(COS)/Estadia.cpp $(COI)/Estadia.h
	g++ -c Estadia.cpp 

DTCalificacion.o: $(DTS)/DTCalificacion.cpp $(DTI)/DTCalificacion.h
	g++ -c DTCalificacion.cpp

Calificacion.o: $(COS)/Calificacion.cpp $(COI)/Calificacion.h
	g++ -c Calificacion.cpp

Sistema.o: $(COS)/Sistema.cpp $(COI)/Sistema.h
	g++ -c Sistema.cpp

Fecha$(C).o:$(CONTS)/Fecha$(C).cpp $(CONTI)/Fecha$(C).h
	g++ -c Fecha$(C).cpp

$(U)$(C).o:$(CONTS)/$(U)$(C).cpp $(CONTI)/$(U)$(C).h
	g++ -c $(U)$(C).cpp

Hostal$(C).o:$(CONTS)/Hostal$(C).cpp $(CONTI)/Hostal$(C).h
	g++ -c Hostal$(C).cpp

$(R)$(C).o:$(CONTS)/$(R)$(C).cpp $(CONTI)/$(R)$(C).h
	g++ -c $(R)$(C).cpp

main.o: main.cpp $(COI)/imprimir.h 
	g++ -c main.cpp

clean: 
	@rm -f main.o $(COS)/*.o $(DTS)/*.o $(CONTS)/*.o  testing
	

