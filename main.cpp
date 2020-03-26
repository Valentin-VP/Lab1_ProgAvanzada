#include <stdio.h>
#include <iostream>
#include <ctime>
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

    /*DtViaje ---> Rodrigo -en proceso-
    DtViaje** verViajesAntesDeFecha (DtFecha& fecha, string ci, int& cantViajes){
        Devuelve un arreglo con información detallada de los viajes realizados por el usuario antes de cierta fecha. Para poder implementar esta operación
        se deberá sobrecargar el operador < del tipo de datos DtFecha.
        cantViajes es un parámetro de salida donde se devuleve la cantidad de viajes encontrados (correspobnde a la cantidad de valores DtViajes que se devuelven)
        Se espera una salida con el formato:

        Viajes encontrados antes de @fecha: @cantViajes

        Fecha: 25/1/19  10 minutos  3.5 Km


    }
    */
}
