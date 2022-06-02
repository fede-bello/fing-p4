EJECUTABLES= DataType/src/DTFecha.o DataType/src/DTHuesped.o conceptos/src/Huesped.o DataType/src/DTHabitacion.o conceptos/src/Habitacion.o DataType/src/DTReserva.o conceptos/src/Reserva.o DataType/src/DTReservaIndividual.o conceptos/src/ReservaIndividual.o DataType/src/DTReservaGrupal.o conceptos/src/ReservaGrupal.o DataType/src/DTEstadia.o conceptos/src/Estadia.o DataType/src/DTCalificacion.o conceptos/src/Calificacion.o conceptos/src/Sistema.o main.o      

#si cambia cualquier .o corre el codigo de abajo

testing: $(EJECUTABLES)
	@g++ $(EJECUTABLES) -o testing

#si cambia .cpp corre el codigo de abajo y lo copila

DTFecha.o: DataType/src/DTFecha.cpp include/DTFecha.h
	g++ -c DTFecha.cpp

DTHuesped.o:DataTypeconceptos/src/DTHuesped.cpp include/DTHuesped.h
	g++ -c DTHuesped.cpp

Huesped.o:conceptos/src/Huesped.cpp conceptos/include/Huesped.h
	g++ -c Huesped.cpp

DTHabitacion.o: DataType/src/DTHabitacion.cpp include/DTHabitacion.h
	g++ -c DTHabitacion.cpp

Habitacion.o: conceptos/src/Habitacion.cpp conceptos/include/Habitacion.h
	g++ -c Habitacion.cpp

DTReserva.o: DataType/src/DTReserva.cpp include/DTReserva.h
	g++ -c DTReserva.cpp 

Reserva.o: conceptos/src/Reserva.cpp conceptos/include/Reserva.h
	g++ -c Reserva.cpp

DTReservaIndividual.o: DataType/src/DTReservaIndividual.cpp include/DTReservaIndividual.h
	g++ -c DTReservaIndividual.cpp

ReservaIndividual.o: conceptos/src/ReservaIndividual.cpp conceptos/include/ReservaIndividual.h
	g++ -c ReservaIndividual.cpp

DTReservaGrupal.o: DataType/src/DTReservaGrupal.cpp include/DTReservaGrupal.h
	g++ -c DTReservaGrupal.cpp

ReservaGrupal.o: src/ReservaGrupal.cpp conceptos/include/ReservaGrupal.h
	g++ -c ReservaGrupal.cpp

DTEstadia.o: DataType/src/DTEstadia.cpp include/DTEstadia.h
	g++ -c DTEstadia.cpp 

Estadia.o: conceptos/src/Estadia.cpp conceptos/include/Estadia.h
	g++ -c Estadia.cpp 

DTCalificacion.o: DataType/src/DTCalificacion.cpp include/DTCalificacion.h
	g++ -c DTCalificacion.cpp

Calificacion.o: conceptos/src/Calificacion.cpp conceptos/include/Calificacion.h
	g++ -c Calificacion.cpp

Sistema.o: conceptos/src/Sistema.cpp conceptos/include/Sistema.h
	g++ -c Sistema.cpp

main.o: main.cpp conceptos/include/imprimir.h 
	g++ -c main.cpp

clean: 
	@rm  main.o conceptos/src/*.o  testing
	

