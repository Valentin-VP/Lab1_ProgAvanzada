#include <stdio.h>
#include <iostream>
#include <stdexcept> //funcion invaid_argument
#include <stdlib.h> //funcion system
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
#define MAX_VEHICULOS 100

struct coleccionUsuarios{
	Usuario* usuarios[MAX_USER];
	int tope;
} coleccionUsuarios;

struct coleccionVehiculos{
	Vehiculo* vehiculos[MAX_VEHICULOS];
	int tope;
} coleccionVehiculos;

void errorSiExisteUsuario(string ci);
void errorSiNoExisteUsuario(string);
Usuario* obtenerUsuario (string);
void ingresarViaje();
void ingresarViaje(string ci,int nroSerie,DtViajeBase& viajeB);
void verViajesAntesDeFecha();
DtViaje** verViajesAntesDeFecha(DtFecha&,string,int&);
void agregarVehiculo();
void agregarVehiculoAux(DtVehiculo*);
void errorSiExisteVehiculo(int);
void errorSiNoExisteVehiculo(int);
void porcentajeValido(float);
void precioBaseValido(float);
void valorPositivo(int);
void fechaValida(DtFecha,string);
void obtenerVehiculos();
DtVehiculo** obtenerVehiculos(int &cantVehiculos);
DtVehiculo* obtenerVehiculo(int);
void cambiarBateriaVehiculo();
void cambiarBateriaVehiculo(int,float);
void registrarUsuario();
bool igualFecha(DtFecha,DtFecha);
bool existeViaje(string,DtFecha);
void eliminarViajes(string,DtFecha);



Usuario* obtenerUsuario(string ci){  //esta bien? //aqui errorSiExisteUsuario(ci) tiraria una excepcion SI existe ese usuario (se va al Catch)
	try{
		errorSiNoExisteUsuario(ci);
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
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}
void errorSiNoExisteUsuario(string ci){
	//ERROR SI EL USUARIO *NO* EXISTE EN LA COLECCION
	int i=0;
    bool existe=false;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
        }
        if(!existe)
            throw invalid_argument("ERROR: NO EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

void errorSiExisteUsuario(string ci){
	// EXPLOTA SI EL USUARIO BUSCADO YA EXISTE EN LA COLECCION
    int i=0;
    bool existe=false;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
        }
        if(existe)
            throw invalid_argument("ERROR: YA EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

void registrarUsuario(){ //funcionando 
    string ci, nombre;
	int d, m, y;
    cout << "Cedula: ";
    cin >> ci;
    try{
        errorSiExisteUsuario(ci);
        cout << "Nombre: ";
        cin >> nombre;
		cout << "Fecha de registro" << endl << "Dia: ";
		cin >> d;
		cout << "Mes: ";
		cin >> m;
		cout << "Anio: ";
		cin >> y; 
        DtFecha* fecha = new DtFecha(d,m,y);
        Usuario* u=new Usuario(ci,nombre,*fecha);
        coleccionUsuarios.usuarios[coleccionUsuarios.tope] = u;
        coleccionUsuarios.tope++;
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}
 
void agregarVehiculo(){
    system("clear");
    //Interfaz con el usuario
	cout <<"______________________________________________" <<endl;
	cout <<"____R E G I S T R O__D E__V E H I C U L O_____"<< endl;
    int nroSerie;
	float porcentajeBateria;
	float precioBase;
	DtVehiculo* dtvehiculo;	
    try{
		cout << "Nro de Serie: " << endl;
		cin >> nroSerie;		
		errorSiExisteVehiculo(nroSerie);// 1 -Vehiculo ya registrado
		cout <<"\nPorcentaje Batería: " << endl;
		cin >> porcentajeBateria;
        porcentajeValido(porcentajeBateria);// 2 - Porcentaje en valor entre 0 y 100
        cout <<"\nPrecio Base: " << endl;
		cin >> precioBase;
        precioBaseValido(precioBase);// 3 - Precio base positivo
       	dtvehiculo = new DtVehiculo(nroSerie,porcentajeBateria,precioBase);		
		agregarVehiculoAux(dtvehiculo);
		        
    }catch (invalid_argument& e){
        //YA EXISTE EL VEHICULO, PORCENTAJE INVALIDO O 
        cout << e.what() << endl;
    }
}

void agregarVehiculoAux(DtVehiculo* dtvehiculo){
	if(Bicicleta* bici=dynamic_cast<Bicicleta*>(dtvehiculo)){
		DtBicicleta* dtbici=new DtBicicleta(bici->getNroSerie(),bici->getPorcentajeBateria(),bici->getPrecioBase(),bici->getTipo(),bici->getCantCambios());
		Bicicleta* b = new Bicicleta(dtbici->getNroSerie(),dtbici->getPorcentajeBateria(),dtbici->getPrecioBase(),dtbici->getTipoBici(),dtbici->getCantCambios());
		//guardar en coleccionVehiculo y subir tope
		coleccionVehiculos.vehiculos[coleccionVehiculos.tope]=b;
		coleccionVehiculos.tope=coleccionVehiculos.tope+1;
	}else if(Monopatin* mono=dynamic_cast<Monopatin*>(dtvehiculo)){
		DtMonopatin* dtmono=new DtMonopatin(mono->getNroSerie(),mono->getPorcentajeBateria(),mono->getPrecioBase(),mono->getTieneLuces());
		Monopatin* m = new Monopatin(dtmono->getNroSerie(),dtmono->getPorcentajeBateria(),dtmono->getPrecioBase(), dtmono->getTieneLuces());
		coleccionVehiculos.vehiculos[coleccionVehiculos.tope]=m;
		coleccionVehiculos.tope=coleccionVehiculos.tope+1;
	}
}

void precioBaseValido(float pb){
    if(pb<=0)
        throw invalid_argument("Precio base inválido; debe ser mayor a 0\n");
}
void porcentajeValido(float pb){
    if((pb<0)||(pb>100))
        throw invalid_argument("Valor de batería inválido\n");
}
void errorSiExisteVehiculo(int nroSerie){
    int i=0;
    while(i<coleccionVehiculos.tope){//&&(existe)){
        if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie())
            throw invalid_argument("Ya existe ese vehículo\n");
        i++;
    }
}
void errorSiNoExisteVehiculo (int nroSerie){
	bool existe = false;
    int i=0;
    while(i<coleccionVehiculos.tope &&(!existe)){
        if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie())
			existe = true;
		
		i++;
    }
	if (!existe) throw invalid_argument("No existe ese vehículo\n");
}

void ingresarViaje(){
    string ci;
    int nroSerieVehiculo;
    int dia, mes, anio, duracion, distancia;
    cout << "Ingrese su cedula: ";
    cin >> ci;
    cout << "Ingrese numero de serie del vehiculo: ";
    cin >> nroSerieVehiculo;
    try{
        errorSiExisteUsuario(ci);
        // Comprobar si existe el Usuario
        errorSiExisteVehiculo(nroSerieVehiculo);
        // Comprobar si existe el vehiculo
        
        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese mes: ";
        cin >> mes;
        cout << "Ingrese anio: ";
        cin >> anio;
        cout << "Ingrese la duracion del viaje: ";
        cin >> duracion;
        cout << "Ingrese la distancia del viaje: ";
        cin >> distancia;
		// Comprobar si la distancia y duracion son validas:
        valorPositivo(duracion);
        valorPositivo(distancia);

        DtFecha fecha=DtFecha(dia,mes,anio);
        fechaValida(fecha,ci);
        // Comprobar si la fecha del viaje es posterior o igual a la fecha de ingreso del usuario
        DtViajeBase viaje = DtViajeBase(duracion,distancia,fecha);
        ingresarViaje(ci,nroSerieVehiculo,viaje);
    }catch(std::invalid_argument& e){
        cout << e.what() << endl;
    }
}

DtVehiculo* obtenerVehiculo(int nroSerie){
	// PRE: Se controla antes que el vehiculo existe en la coleccion
	for(int i=0;i<coleccionVehiculos.tope;i++){
		if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie()){
			DtVehiculo* dtve = new DtVehiculo(coleccionVehiculos.vehiculos[i]->getNroSerie(),coleccionVehiculos.vehiculos[i]->getPorcentajeBateria(),coleccionVehiculos.vehiculos[i]->getPrecioBase());
			return dtve;
		}
	}
}
void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viaje){
        // obtener Usuario 
        Usuario* usuario = obtenerUsuario(ci);
        // Obtener Vehiculo
        DtVehiculo* ve = obtenerVehiculo(nroSerieVehiculo) ;// = obtenerVehiculo(nroSerieVehiculo);
        float precioViaje;
        
		if(DtBicicleta* dtbici = dynamic_cast<DtBicicleta*>(ve)){
			Bicicleta* dtb = new Bicicleta(dtbici->getNroSerie(),dtbici->getPorcentajeBateria(),dtbici->getPrecioBase(),dtbici->getTipoBici(),dtbici->getCantCambios());
			precioViaje = dtb->darPrecioViaje(viaje.getDuracion(),viaje.getDistancia());
			DtViaje* dviaje = new DtViaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),precioViaje,ve);
			Viaje* viajea = new Viaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),dtb);
			usuario->agregarViaje(viajea);
		}
		else{
			if(DtMonopatin* dtmono = dynamic_cast<DtMonopatin*>(ve)){
			Monopatin* dtm = new Monopatin(dtmono->getNroSerie(),dtmono->getPorcentajeBateria(),dtmono->getPrecioBase(),dtmono->getTieneLuces());
			precioViaje = dtm->darPrecioViaje(viaje.getDuracion(),viaje.getDistancia());
			DtViaje* dviaje = new DtViaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),precioViaje,ve);
			Viaje* viajea = new Viaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),dtm);
			usuario->agregarViaje(viajea);
			}
		}
}

void valorPositivo(int d){
	if(d<=0)
		throw invalid_argument("El valor debe ser positivo\n");
}

void fechaValida(DtFecha f, string ci){
	Usuario* user = obtenerUsuario(ci);
	if(f < user->getFechaIngreso())
		throw invalid_argument("La fecha del viaje debe ser posterior o igual a la fecha de ingreso del usuario\n");
}
 
// DtViaje ---> Rodrigo -en proceso-
// Bloque de codigo cuando se solicita imprimir Viajes -- OPERACION verViajesAntesDe

void verViajesAntesDeFecha(){
    system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"V I A J E S   D E L   U S U A R I O"<< endl;
	string ci;
	int dia,mes,anio,cantViajes=0;
    DtFecha dtFecha;
    cout << "CI: ";
	cin >> ci;
    cout << "Visualizar viajes antes de la fecha: "<<endl;
    cout << "Dia: ";
	cin >> dia;
    cout << "Mes: ";
	cin >> mes;
    cout << "Anio: ";
	cin >> anio;
    dtFecha = DtFecha(dia,mes,anio);
    DtViaje** viajes= verViajesAntesDeFecha(dtFecha, ci, cantViajes);
    for (int i=0; i<cantViajes; i++)
        cout << "\n" << *(viajes[i]); //revisando si imprime bien
}

DtViaje** verViajesAntesDeFecha (DtFecha& fecha, string ci, int& cantViajes){
	// try catch usando errorSiNoExisteUsuario
	try{
		errorSiNoExisteUsuario(ci);
		Usuario* user = obtenerUsuario(ci); 
		if(cantViajes>user->getTopeViajes())
			cantViajes=user->getTopeViajes();
		Viaje** viajes=user->obtenerViaje(); //copia todos los viajes del usuario en el arreglo de punteros Viaje viajes
		DtViaje** dtViajes = new DtViaje*[MAX_VIAJES];
		DtViaje* dtViaje;
		DtVehiculo* dtVehiculo;
		int i=0;
		cout << "Viajes Realizados: " << endl;
		while (i<user->getTopeViajes()){ //Obtiene y guarda todos los viajes que  su fecha es anterior a la indicada
			if(viajes[i]->getFecha()<fecha){
				dtVehiculo= new DtVehiculo (viajes[i]->getVehiculo()->getNroSerie(),viajes[i]->getVehiculo()->getPorcentajeBateria(),viajes[i]->getVehiculo()->getPrecioBase());
				dtViaje= new DtViaje(viajes[i]->getDuracion(),viajes[i]->getDistancia(),viajes[i]->getFecha(),(viajes[i]->getVehiculo())->getPrecioBase(),dtVehiculo); //falta solucionar
				dtViajes[cantViajes]=dtViaje;
				cantViajes++;
			}
			i++;
		}
		return dtViajes;
	}catch(std::invalid_argument& e){
		cout << e.what() << endl;
	}

}	

bool igualFecha(DtFecha f1,DtFecha f2){ //ve si una fecha es igual a la otra
	if(f1.getDia()==f2.getDia()){
		if(f1.getMes()==f2.getMes()){
			if(f1.getAnio()==f2.getAnio())
				return true;
			else
				return false;
		}else
			return false;
	}else
		return false;
}


//_____________________________COMPROBAR EN EXISTEVIAJE Y EN ELIMINARVIAJES SI EL user->obtenerViaje[i] ESTA BIEN________________________________ 



bool existeViaje(string ci,DtFecha fecha){ //ve si el usuario ci tiene un viaje en esa fecha
	Usuario* user = obtenerUsuario(ci);
	bool encontro;
	int i=0;
	while((!encontro)&&(i < user->getTopeViajes())){
		if(igualFecha(user->obtenerViaje[i]->getFecha(), fecha))
			encontro=true;
		else
			i++;
	}
	if(encontro)
		return true;
	else 
		return false;
}

void eliminarViajes(){   //ejercicio e sin comprobar si funciona
	string ci;
	cout << "Cedula del usuario: ";
	cin >> ci;
	int d,m,y;
	cout << "Dia: ";
	cin >> d;
	cout << "Mes: ";
	cin >> m;
	cout << "Anio: ";
	cin >> y;
	DtFecha fecha = DtFecha(d,m,y);
	try{
		errorSiExisteUsuario(ci);
		int i=0,f=0;
		bool encontroUser=false,encontroFecha=false;
		while((!encontroUser)||(i<coleccionUsuarios.tope)){
        	if(ci!=coleccionUsuarios.usuarios[i]->getCedula())
				i++;
			else{
				encontroUser=true;  //i es la posicion del usuario en el arreglo
				while(existeViaje(ci,fecha)){	
					while((!encontroFecha)||(i<coleccionUsuarios.usuarios[i]->getTopeViajes())){
						if(!igualFecha(fecha,coleccionUsuarios.usuarios[i]->obtenerViaje[f]))//PUEDEN SER IGUALES LAS FECHAS? O SON OBJETOS CON IDENTIDAD PROPIA
							f++;
						else{
							delete &(coleccionUsuarios.usuarios[i]->obtenerViaje[f]);
							&(coleccionUsuarios.usuarios[i]->obtenerViaje[f])=coleccionUsuarios.usuarios[coleccionUsuarios.usuarios[i]->getTopeViajes()-1];
							coleccionUsuarios.usuarios[i]->setTopeViajes(coleccionUsuarios.usuarios[i]->getTopeViajes()-1);	
						}
					}
				}
			}
		}
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

// OP G
/* NO TENGO CLARO SI ESTA BIEN */
void obtenerVehiculos(){ 
	system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"___V E R__L I S T A D O__ D E__V E H I C U L O S___"<< endl;
	int cantVehiculos = coleccionVehiculos.tope;
	DtBicicleta* bici;
	DtMonopatin* patin;

		DtVehiculo** dtVehiculos = obtenerVehiculos(cantVehiculos);
		cout << "VEHICULOS DEL SISTEMA: " <<endl;
		for (int i = 0; i < cantVehiculos; i++){
			bici = dynamic_cast<DtBicicleta*>(dtVehiculos[i]);			
			if (bici!=NULL)
				cout << "\n\n" << *(bici);
			else{
				patin = dynamic_cast<DtMonopatin*>(dtVehiculos[i]);		
				if (patin!=NULL)
					cout << "\n\n" << *(patin);	
			}
			cout << "-------------------------"<< endl;	
		}
}
DtVehiculo** obtenerVehiculos(int &cantVehiculos){
	Vehiculo** vehiculos = coleccionVehiculos.vehiculos;
	DtBicicleta* dtBici;
	DtMonopatin* dtPatin;
	if(cantVehiculos>coleccionVehiculos.tope)
		cantVehiculos=coleccionVehiculos.tope;
	DtVehiculo** dtVehiculos = new DtVehiculo*[cantVehiculos];
	for(int i=0;i<cantVehiculos;i++){
		if(Bicicleta* bici = dynamic_cast<Bicicleta*>(vehiculos[i])){
				dtBici = new DtBicicleta(bici->getNroSerie(),bici->getPorcentajeBateria(),bici->getPrecioBase(),bici->getTipo(),bici->getCantCambios());
				dtVehiculos[i]=dtBici;
		}else{
			if(Monopatin* patin = dynamic_cast<Monopatin*>(vehiculos[i])){
					dtPatin = new DtMonopatin(patin->getNroSerie(),patin->getPorcentajeBateria(),patin->getPrecioBase(),patin->getTieneLuces());
					dtVehiculos[i]=dtPatin;
			}
		}
	}
	return dtVehiculos;
}

void cambiarBateriaVehiculo(){
	int nroSerieVehiculo, porcentajeBateria;
	try{
		cout << "Nro de Serie: " << endl;
		cin >> nroSerieVehiculo;		
		errorSiNoExisteVehiculo(nroSerieVehiculo);// 1 -Vehiculo ya registrado
		cout <<"\nPorcentaje Batería: " << endl;
		cin >> porcentajeBateria;
        porcentajeValido(porcentajeBateria);// 2 - Porcentaje en valor entre 0 y 100
		cambiarBateriaVehiculo(nroSerieVehiculo, porcentajeBateria);
    }catch (invalid_argument& e){
        //NO EXISTE EL VEHICULO|PORCENTAJE INVALIDO
        cout << e.what() << endl;
    }
}

void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo){
	int j=0;
	bool found= false;
	while((j<coleccionVehiculos.tope)&&(!found)){
		if(nroSerieVehiculo==coleccionVehiculos.vehiculos[j]->getNroSerie()){
			coleccionVehiculos.vehiculos[j]->setPorcentajeBateria(cargaVehiculo);
			found=true;
		}
	}
}


int main(){

    int opcion;

	system("clear");
	cout << "Bienvenido. Elija la opción." << endl;
	cout << "1) Registrar usuario" << endl;
	cout << "2) Agregar vehículo" << endl;
	cout << "3) Ingresar viaje" << endl;
	cout << "4) Ver viajes antes de.." << endl;
	cout << "5) Eliminar viajes" << endl;
	cout << "6) Cambiar bateria del vehículo" << endl;
	cout << "7) Obtener vehículos" << endl;
	cout << "0) Salir" << endl;
	cout << "Opción: ";
	cin >> opcion;
		switch(opcion){
			case 1: registrarUsuario();
				break;
			case 2: agregarVehiculo();
				break;
			case 3: ingresarViaje();
				break;
			case 4: verViajesAntesDeFecha();
				break;
			case 5: eliminarViajes();
				break;
			case 6: cambiarBateriaVehiculo();
				break;
			case 7: obtenerVehiculos();
				break;
			case 0: system("exit");
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}
    return 0;
}
