#ifndef MONOPATIN
#define MONOPATIN
#include "Vehiculo.h"
using namespace std;

class Monopatin: public Vehiculo{
	private:
		bool tieneLuces;
	public:
		Monopatin();
		Monopatin(int,float,float,bool);
		~Monopatin();
		void setTieneLuces(bool);
		bool getTieneLuces();

		float darPrecioViaje(int,int);
};

#endif
