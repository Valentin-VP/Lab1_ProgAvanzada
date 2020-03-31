#ifndef VEHICULO
#define VEHICULO
using namespace std;

class Vehiculo{
	private:
		int nroSerie;
		float porcentajeBateria;
		float precioBase;

	public:
		Vehiculo();
		Vehiculo(int,float,float);
		~Vehiculo();

		void setNroSerie(int);
		int getNroSerie();
		void setPorcentajeBateria(float);
		float getPorcentajeBateria();
		void setPrecioBase(float);
		float getPrecioBase();
		
		virtual float darPrecioViaje(int,int)=0;
};
#endif
