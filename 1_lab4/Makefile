#ABREVIACIONES
DTI= DataType/include
DTS= DataType/src
COI= Clases/include
COS= Clases/src
U= Usuario
R=Reserva
C=controlador
CONTI= Controladores/include
CONTS= Controladores/src
INTI= Interfaces/include
INTS= Interfaces/src

EJECUTABLES= $(DTS)/DTFecha.o $(DTS)/DT$(U).o $(COS)/$(U).o $(DTS)/DTHuesped.o \
$(COS)/Huesped.o $(DTS)/DTEmpleado.o $(COS)/Empleado.o $(DTS)/DTHostal.o $(COS)/Hostal.o \
$(DTS)/DTHabitacion.o $(COS)/Habitacion.o $(DTS)/DT$(R).o $(COS)/$(R).o \
$(DTS)/DT$(R)Individual.o $(COS)/$(R)Individual.o $(DTS)/DT$(R)Grupal.o $(COS)/$(R)Grupal.o \
$(DTS)/DTEstadia.o $(COS)/Estadia.o $(DTS)/DTCalificacion.o $(COS)/Calificacion.o  \
$(CONTS)/$(C)Fecha.o $(CONTS)/$(C)Hostal.o $(CONTS)/$(C)$(U).o $(CONTS)/$(C)$(R).o \
$(INTS)/I$(C)Fecha.o $(INTS)/I$(C)Hostal.o $(INTS)/I$(C)$(R).o $(INTS)/I$(C)$(U).o \
$(INTS)/Factory.o main.o   

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

DTFecha.o: $(DTS)/DTFecha.cpp $(DTI)/DTFecha.h
	g++ -c DTFecha.cpp

DT$(U).o: $(DTS)/DT$(U).cpp $(DTI)/DT$(U).h
	g++ -c DT$(U).cpp

$(U).o: $(COS)/$(U).cpp $(COI)/$(U).h
	g++ -c $(U).cpp

DTHuesped.o: $(DTS)/DTHuesped.cpp $(DTI)/DTHuesped.h
	g++ -c DTHuesped.cpp

Huesped.o:$(COS)/Huesped.cpp $(COI)/Huesped.h
	g++ -c Huesped.cpp

DTEmpleado.o: $(DTS)/DTEmpleado.cpp $(DTI)/DTEmpleado.h
	g++ -c DTEmpleado.cpp

Empleado.o:$(COS)/Empleado.cpp $(COI)/Empleado.h
	g++ -c Empleado.cpp

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

I$(C)Fecha.o:$(INTS)/I$(C)Fecha.cpp $(INTI)/I$(C)Fecha.h
	g++ -c I$(C)Fecha.cpp

I$(C)Hostal.o:$(INTS)/I$(C)Hostal.cpp $(INTI)/I$(C)Hostal.h
	g++ -c I$(C)Hostal.cpp

I$(C)Usuario.o:$(INTS)/I$(C)Usuario.cpp $(INTI)/I$(C)Usuario.h
	g++ -c I$(C)Usuario.cpp

I$(C)Reserva.o:$(INTS)/I$(C)Reserva.cpp $(INTI)/I$(C)Reserva.h
	g++ -c I$(C)Reserva.cpp

Calificacion.o: $(COS)/Calificacion.cpp $(COI)/Calificacion.h
	g++ -c Calificacion.cpp


$(C)Fecha.o:$(CONTS)/$(C)Fecha.cpp $(CONTI)/$(C)Fecha.h
	g++ -c $(C)Fecha.cpp

$(C)$(U).o:$(CONTS)/$(C)$(U).cpp $(CONTI)/$(C)$(U).h
	g++ -c $(C)$(U).cpp

$(C)Hostal.o:$(CONTS)/$(C)Hostal.cpp $(CONTI)/$(C)Hostal.h
	g++ -c $(C)Hostal.cpp

$(C)$(R).o:$(CONTS)/$(C)$(R).cpp $(CONTI)/$(C)$(R).h
	g++ -c $(C)$(R).cpp


Factory.o:$(INTS)/Factory.cpp $(INTS)/Factory.h
	g++ -c Factory.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	@rm -f main.o $(COS)/*.o $(DTS)/*.o $(CONTS)/*.o $(INTS)/*.o testing
	

