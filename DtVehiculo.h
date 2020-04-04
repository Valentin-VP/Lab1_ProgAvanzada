#ifndef DTVEHICULO
#define DTVEHICULO
using namespace std;
#include <iostream>

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
		
		friend ostream& operator <<(ostream& sal,const DtVehiculo& v); //imprime datos de v


};
#endif
