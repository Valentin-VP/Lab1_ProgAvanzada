#ifndef VIAJE
#define VIAJE
#include "DtFecha.h"
using namespace std;

class Viaje{

    private:

        int duracion;
        int distancia;
        DtFecha fecha;

    public:

        Viaje();
        Viaje(int,int,DtFecha);
        ~Viaje();

        void setDuracion(int);
        int getDuracion();

        void setDistancia(int);
        int getDistancia();

        void setFecha(DtFecha);
		DtFecha getFecha();
};
#endif