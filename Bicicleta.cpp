#include "Bicicleta.h"

Bicicleta::Bicicleta(){}
Bicicleta::Bicicleta(TipoBici tipo,int cantCambios){
	this->tipo=tipo;
	this->cantCambios=cantCambios;
}
Bicicleta::~Bicicleta(){}

void Bicicleta::setTipo(TipoBici tipo){
	this->tipo=tipo;
}
TipoBici Bicicleta::getTipo(){
	return this->tipo;
}
void Bicicleta::setCantCambios(int cc){
	this->cantCambios=cc;
}
int Bicicleta::getCantCambios(){
	return this->cantCambios;
}

