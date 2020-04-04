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
        
        ~DtMonopatin();
        
        friend ostream& operator <<(ostream& sal, const DtMonopatin& m);
};

#endif