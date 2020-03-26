#ifndef BICICLETA
#define BICICLETA
#include "TipoBici.h"
using namespace std;

class Bicicleta{
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
//falta darPrecioViaje
};

#endif
