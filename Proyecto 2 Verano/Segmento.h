#pragma once
#include "ListaZonas.h"

class Segmento
{
    private:
        string nombre;  //vip, estandar, etc
        double precio;
        ListaZonas* zonas;    //asientos asociados
        static int contador;  //es para encontrar mas facil el segmento
        int numero;
    public:
        // constructores
        Segmento();
        Segmento(string, double);
        ~Segmento();
  

        // gets, sets
        int getCantZonas();
        int getEspaciosDisponibles();
        int getContador();

        bool agregaZona(Zona*);
        Zona* getZona(int);

        void setPrecio(double p);
        double getPrecio();

        void setNombre(string);
        string getNombre();

        bool eliminaZona(int);
        int entradasVendidas();
        // Métodos adicionales
        string toString();
};

