#ifndef DTVEHICULO
#define DTVEHICULO
using namespace std;

class DtVehiculo{
	private:
		int nroSerie;
		float porcentajeBateria;
		float precioBase;
	public:
		DtVehiculo();
		~DtVehiculo();
		int getNroSerie();
		float getPorcentajeBateria();
		float getPrecioBase();

};
#endif
