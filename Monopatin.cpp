#include "Monopatin.h"

Monopatin::Monopatin(){}
Monopatin::~Monopatin(){}
void Monopatin::setTieneLuces(bool f){
	this->tieneLuces=f;
}
bool Monopatin::getTieneLuces(){
	return this->tieneLuces;
}

float Monopatin::darPrecioViaje(int duracion, int distancia){
	float precio;
	if(this->getTieneLuces()){
		precio = (0.5 * duracion) + (distancia * this->getPrecioBase());
	}else{
		precio = distancia * this->getPrecioBase();
	}
	return precio;
}
