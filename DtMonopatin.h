#ifndef DTMONOPATIN
#define DTMONOPATIN
#include "DtVehiculo.h"
#include <iostream>
using namespace std;

class DtMonopatin : public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        DtMonopatin();
        DtMonopatin(int, float, float, bool);

        bool getTieneLuces();
        void setTieneLuces(bool);

        ~DtMonopatin();
        friend ostream& operator <<(ostream& sal, const DtMonopatin& m); //imprime datos de m
};

#endif