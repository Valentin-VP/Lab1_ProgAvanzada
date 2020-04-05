
#include "DtMonopatin.h"

DtMonopatin::DtMonopatin(){}
DtMonopatin::DtMonopatin(int a, float b, float c, bool luces):DtVehiculo(a,b,c){
    this->tieneLuces=luces;
}

DtMonopatin::~DtMonopatin(){}

bool DtMonopatin::getTieneLuces(){
    if(tieneLuces){
        return true;
    }else{
        return false;
    }
}

ostream& operator <<(ostream& sal, const DtMonopatin& m){ //imprime los datos de m
    string luces = (m.tieneLuces) ? "Si":"No";
	cout << (DtVehiculo) m << endl; 
    cout << " --MONOPATÍN-- "<< endl;
	cout << " - Tiene luces: " << luces << endl;   
   return sal;
}