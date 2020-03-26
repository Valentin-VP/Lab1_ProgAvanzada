main: DtBicicleta.o DtMonopatin.o DtVehiculo.o DtViaje.o DtViajeBase.o Monopatin.o Bicicleta.o Vehiculo.o Viaje.o DtFecha.o Usuario.o main.o
	g++ DtBicicleta.o DtMonopatin.o DtVehiculo.o DtViaje.o DtViajeBase.o Monopatin.o Bicicleta.o Vehiculo.o Viaje.o DtFecha.o Usuario.o main.o -o labo

DtBicicleta.o: DtBicicleta.cpp

DtMonopatin.o: DtMonopatin.cpp

DtVehiculo.o: DtVehiculo.cpp

DtViaje.o: DtViaje.cpp

DtViajeBase.o: DtViajeBase.cpp

Monopatin.o: Monopatin.cpp

Bicicleta.o: Bicicleta.cpp

Vehiculo.o: Vehiculo.cpp

Viaje.o: Viaje.cpp

DtFecha.o: DtFecha.cpp

Usuario.o: usuario.cpp

main.o: main.cpp

clean:
	rm *.o labo