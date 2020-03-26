#ifndef USUARIO
#define USUARIO
#include<iostream>
#include "DtFecha.h"
using namespace std;

class Usuario{
	private:
		string cedula;
		string nombre;
		DtFecha fechaIngreso;
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

		friend ostream& operator <<(ostream&,Usuario&);
};





#endif
