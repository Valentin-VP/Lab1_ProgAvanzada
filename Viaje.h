#ifndef VIAJE
#define VIAJE
#include "DtFecha.h"
#include "Vehiculo.h"
using namespace std;

class Viaje{

    private:

        int duracion;
        int distancia;
        DtFecha fecha;
        Vehiculo* vehiculo;

    public:

        Viaje();
        Viaje(int,int,DtFecha,Vehiculo*);
        ~Viaje();

        void setDuracion(int);
        int getDuracion();

        void setDistancia(int);
        int getDistancia();

        void setFecha(DtFecha);
		DtFecha getFecha();

        Vehiculo* getVehiculo();
};
#endif