#include "Segmento.h"
#include <iostream>
#include <sstream>
using namespace std;

int Segmento::contador = 0;

Segmento::Segmento()
    : precio(0.0), nombre("----"), zonas(new ListaZonas()), numero(contador++){
   
}

Segmento::Segmento(string nom)
    :nombre(nom), precio(0.0), zonas(new ListaZonas()), numero(contador++) {
}

Segmento::~Segmento() {
    
}

//int Segmento::getCantZonas()  //por agregar
//{
//    return cantZonas;
//}

// cant numerica
int Segmento::getEspaciosDisponibles()
{
  /*  int disponibles = 0;
    for (int i = 0; i < cantZonas; i++) {
        disponibles += zonas[i]->getDisponibles();
    }
    return disponibles;*/
}

// gets y sets
Zona* Segmento::getZona(int n) {
    /*if (n < 0 || n >= cantZonas) {
        cout << "Índice fuera de rango." << endl;
        return nullptr;
    }
    return zonas[n];*/
}

bool Segmento::agregaZona(Zona* zo1)
{
   zonas->agregarZonaAlFinal(zo1);
}

void Segmento::setPrecio(double prec) 
{
    //if (prec > 0.0) {
    //    this->precio = prec;

    //    //le establece el precio a todas las zonas asociadas
    //    for (int i = 0; i < cantZonas; i++) {
    //        if (zonas[i] != nullptr) {
    //            zonas[i]->setPrecio(precio);
    //        }
    //    }
    //}
    //else {
    //    cout << "El precio debe ser mayor a 0 colones.\n";
    //    precio = 0.0;
    //}
}

double Segmento::getPrecio() { return precio; }

void Segmento::setNombre(string nom) { nombre = nom; }

string Segmento::getNombre() { return nombre; }

string Segmento::toString() {
    stringstream s;
    //// verifica si hay zonas asignadas
    //if (cantZonas == 0) {
    //    s << "No hay zonas asignadas a este segmento.\n";
    //}
    //else {
    //    s << " - Segmento: " << nombre << "\n";
    //    s << " - Precio por asiento: " << precio << " colones.\n";
    //    for (int i = 0; i < cantZonas; i++) {
    //        s << " - Informacion de la zona: \n" << zonas[i]->toString();
    //    }
    //}
    return 0;
}

