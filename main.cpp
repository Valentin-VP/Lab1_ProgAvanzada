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
#include "DtViaje.h"

using namespace std;
#define MAX_USER 30

struct{
	Usuario* usuarios[MAX_USER];
	int tope;
} coleccionUsuarios;

Usuario* obtenerUsuario (string);
DtViaje** verViajesAntesDeFecha(DtFecha&,string,int&);

Usuario* obtenerUsuario(string ci){ //falta probar
    Usuario* user;
	bool existe=false;
	int i=0;
	while((i<coleccionUsuarios.tope)&&(!existe)){
		if(ci==coleccionUsuarios.usuarios[i]->getCedula()){
			user=coleccionUsuarios.usuarios[i];
			existe=true;
		}
		i++;
	}
	return user;
}


void registrarUsuario(){ //funcionando
    string ci, nombre;
    cout << "Cedula: ";
    cin >> ci;
    bool existe=false;
    int i=0;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
    }
    if(existe){
        cout << "Usuario ya registrado" << endl;
    }else{    
        cout << "Nombre: ";
        cin >> nombre;
        DtFecha* fecha = new DtFecha(27,3,2020);
        Usuario* u=new Usuario(ci,nombre,*fecha);
        coleccionUsuarios.usuarios[coleccionUsuarios.tope] = u;
        coleccionUsuarios.tope++;
    }
}
 
 
// // DtViaje ---> Rodrigo -en proceso-
// DtViaje** verViajesAntesDeFecha (DtFecha& fecha, string ci, int& cantViajes){
//     Usuario* user = obtenerUsuario(ci);
//         if(cantViajes>user->getTopeViajes())
//             cantViajes=user->getTopeViajes();
//     // Devuelve un arreglo con información detallada de los viajes realizados por el usuario antes de cierta fecha. Para poder implementar esta operación
//     // se deberá sobrecargar el operador < del tipo de datos DtFecha.
//     // cantViajes es un parámetro de salida donde se devuleve la cantidad de viajes encontrados (correspobnde a la cantidad de valores DtViajes que se devuelven)
//     // Se espera una salida con el formato:

//     // Viajes encontrados antes de @fecha: @cantViajes

//     // Fecha: 25/1/19  10 minutos  3.5 Km


// }

 
int main(){
    
}
