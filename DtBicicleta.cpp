#include "DtBicicleta.h"
#include "DtVehiculo.h"
#include "TipoBici.h"

DtBicicleta::DtBicicleta(){}

DtBicicleta::DtBicicleta(int a, float b, float c, TipoBici tipoB, int cambios):DtVehiculo(a,b,c){
    this->tipo = tipoB;
    this->cantCambios = cambios;
}

DtBicicleta::~DtBicicleta(){}

TipoBici DtBicicleta::getTipoBici(){
    return this->tipo;
}

// void DtBicicleta::setTipoBici(TipoBici t){       No debiera ser necesario
//     this->tipo=t;
// }

int DtBicicleta::getCantCambios(){
    return this->cantCambios;
}

void DtBicicleta::setCantCambios(int c){
    this->cantCambios=c;
}

ostream& operator <<(ostream& sal, const DtBicicleta& b){ //imprime los datos de m
    string tipo[2]={"Paseo","Montaña"};
	cout << (DtVehiculo) b << "\n" 
	"Tipo de Bicicleta: " << tipo[b.tipo] << "\n" 
    "Cantidad de Cambios: " << b.cantCambios << endl;
    return sal;

	
}
