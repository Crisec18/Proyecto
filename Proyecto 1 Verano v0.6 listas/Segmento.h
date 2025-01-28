#ifndef SEGMENTO_H
#define SEGMENTO_H
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
        Segmento(string);
        ~Segmento();
  

        // gets, sets
        int getCantZonas();
        int getEspaciosDisponibles();

        bool agregaZona(Zona*);
        Zona* getZona(int);

        void setPrecio(double p);
        double getPrecio();

        void setNombre(string);
        string getNombre();

        // Métodos adicionales
        string toString();
};
#endif  //SEGMENTO_H

