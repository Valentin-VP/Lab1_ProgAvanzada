#include<stdio.h>
#include<iostream>
#include<ctime>
#include "Bicicleta.h"
#include "DtBicicleta.h"
#include "DtFecha.h"
#include "DtMonopatin.h"
#include "DtVehiculo.h"
#include "DtViajeBase.h"
#include "Monopatin.h"
#include "TipoBici.h"
#include "Usuario.h"
#include "Vehiculo.h"
#include "Viaje.h"
using namespace std;
#define MAX_USER 30

struct coleccionUsuarios{
	Usuario* usuarios[MAX_USER];
	int tope;
};

/*void registrarUsuario(){
    string ci, nombre;
    bool yaExisteCi=false;
    cout << endl << "Cedula: ";
    cin >> ci;
    for(int i=0;i<coleccionUsuarios.tope;i++){
        
    }
    if(yaExisteCi)
        cout << "Cedula ya registrada" << endl;
    else{    
        cout << endl << "nombre: ";
        cin >> nombre;

    }
}*/
 
int main(){
    DtFecha* hoy = new DtFecha(25,3,2020);
    Usuario* nuevo = new Usuario("49457795","Valentin",*hoy);
    cout << *nuevo << endl;
    delete nuevo;
    cout << *hoy << endl;
}