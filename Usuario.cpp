#include "Usuario.h"
#include<iostream>
using namespace std;

Usuario::Usuario(){}
Usuario::Usuario(string c,string n,DtFecha f){
	this->cedula=c;
	this->nombre=n;
	this->fechaIngreso=f;
}
Usuario::~Usuario(){}
void Usuario::setCedula(string c){
	this->cedula=c;
}
string Usuario::getCedula(){
	return this->cedula;
}
void Usuario::setNombre(string n){
	this->nombre=n;
}
string Usuario::getNombre(){
	return this->nombre;
}
void Usuario::setFechaIngreso(DtFecha f){
	this->fechaIngreso=f;
}
DtFecha Usuario::getFechaIngreso(){
	return this->fechaIngreso;
}

ostream& operator <<(ostream& sal,Usuario& u){
	cout << "Cedula: " << u.cedula << endl << "Nombre: " << u.nombre << endl << "Fecha: " << u.fechaIngreso;
}
