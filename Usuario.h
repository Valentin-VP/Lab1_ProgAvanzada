#ifndef USUARIO
#define USUARIO
#include<iostream>
#include "DtFecha.h"
#include "Viaje.h"
#define MAX_VIAJES 100
using namespace std;

class Usuario{
	private:
		string cedula;
		string nombre;
		DtFecha fechaIngreso;
		Viaje* viajes[MAX_VIAJES];
		int topeViajes;
	public:
		Usuario();
		Usuario(string,string,DtFecha);
		~Usuario();
		void setCedula(string);
		string getCedula();
		void setNombre(string);
		string getNombre();
		void setFechaIngreso(DtFecha);
		DtFecha getFechaIngreso();
		int getTopeViajes();
		void setTopeViajes(int);

		void agregarViaje(Viaje*);
		Viaje** obtenerViaje();

		friend ostream& operator <<(ostream&,Usuario&);


};





#endif
