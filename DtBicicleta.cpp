#include "DtBicicleta.h"
#include "TipoBici.h"

DtBicicleta::DtBicicleta(){}

DtBicicleta::~DtBicicleta(){}

TipoBici DtBicicleta::getTipoBici(){
    return this->tipo;
}

void DtBicicleta::setTipoBici(TipoBici t){
    this->tipo=t;
}

int DtBicicleta::getCantCambios(){
    return this->cantCambios;
}

void DtBicicleta::setCantCambios(int c){
    this->cantCambios=c;
}
