#ifndef DTFECHA
#define DTFECHA
#include<iostream>
using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public: 
        DtFecha();
        DtFecha(int,int,int);
        ~DtFecha();

        void setDia(int);
        int getDia();

        void setMes(int);
        int getMes();

        void setAnio(int);
        int getAnio(); 

        friend ostream& operator <<(ostream& sal,DtFecha& f); //para imprimir fecha con cout

        friend bool operator <(const DtFecha& f1,const DtFecha& f2); // para comparar fechas con <
};
#endif 