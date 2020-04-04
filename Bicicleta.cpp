#include "Bicicleta.h"

Bicicleta::Bicicleta(){}
Bicicleta::Bicicleta(int nroSerie,float porBateria,float precioBase,TipoBici tipo,int cantCambios):Vehiculo(nroSerie,porBateria,precioBase){
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
float Bicicleta::darPrecioViaje(int duracion, int distancia){
	float viaje;
	viaje = this->getPrecioBase() * distancia;
	return viaje;
}
