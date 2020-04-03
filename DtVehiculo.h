#ifndef DTVEHICULO
#define DTVEHICULO
#include <iostream>
using namespace std;

class DtVehiculo{
	private:
		int nroSerie;
		float porcentajeBateria;
		float precioBase;
	public:
		DtVehiculo();
		DtVehiculo(int,float,float);
		virtual ~DtVehiculo();
		int getNroSerie();
		float getPorcentajeBateria();
		float getPrecioBase();
		friend ostream& operator <<(ostream& sal,DtVehiculo& v); //imprime datos de v
};
#endif
