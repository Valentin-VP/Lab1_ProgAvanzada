#ifndef BICICLETA
#define BICICLETA
#include "Vehiculo.h"
#include "TipoBici.h"
using namespace std;

class Bicicleta: public Vehiculo{
	private:
		TipoBici tipo;
		int cantCambios;
	public:
		Bicicleta();
		Bicicleta(TipoBici,int);
		~Bicicleta();
		void setTipo(TipoBici);
		TipoBici getTipo();
		void setCantCambios(int);
		int getCantCambios();

		float darPrecioViaje(int,int);
};

#endif
