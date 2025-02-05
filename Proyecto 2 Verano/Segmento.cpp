#include "Segmento.h"
#include <iostream>
#include <sstream>
using namespace std;

int Segmento::contador = 0;

Segmento::Segmento()
    : precio(0.0), nombre("----"), zonas(new ListaZonas()), numero(contador++){
   
}

Segmento::Segmento(string nom, double prec)
    :nombre(nom), precio(prec), zonas(new ListaZonas()), numero(contador++) {
}

Segmento::~Segmento() {
    delete zonas;
}

int Segmento::getCantZonas()  //por agregar
{
    return zonas->cantidadEspacios();
}

// cant numerica
int Segmento::getEspaciosDisponibles()
{
    return zonas->getDisponibles();
}

int Segmento::getContador()
{
    return contador;
}

// gets y sets
Zona* Segmento::getZona(int n) {
    return zonas->buscarZonaPorPosicion(n);
}

bool Segmento::agregaZona(Zona* zo1)
{
    if (zo1 != nullptr) {
        zonas->agregarZonaAlFinal(zo1);
        cout<<"Agregado con exito\n";
        return true;
    }
    cout << "No se puede agregar una zona nula.\n";
    return false;
}

void Segmento::setPrecio(double prec) 
{
    NodoZona* actual = zonas->getPrimero();
    if (prec > 0.0) {
        this->precio = prec;
        //ponerle el precio a los espacios de la zona
        while (actual != nullptr) {
            actual->getZona()->setPrecio(prec); 
            actual = actual->getSiguiente();
        }
    }
    else {
        cout << "El precio debe ser mayor a 0 colones.\n";
        precio = 0.0;
    }
}

double Segmento::getPrecio() { return precio; }

void Segmento::setNombre(string nom) { nombre = nom; }

string Segmento::getNombre() { return nombre; }

bool Segmento::eliminaZona(int num)
{
    NodoZona* borrar = zonas->getPrimero();
    NodoZona* actual = nullptr;

    while (borrar != nullptr) {
        if (borrar->getZona()->getContador() == num) {
            // Si es el primer nodo
            if (actual == nullptr) {
                zonas->setPrimero(borrar->getSiguiente());
            }
            else {
                actual->setSiguiente(borrar->getSiguiente());
            }

            delete borrar;
            return true;
        }
        //avanzamos
        actual = borrar;
        borrar = borrar->getSiguiente();
    }

    cout << "Zona con el numero identificador: " << num << " no encontrado." << endl;
    return false;
}

int Segmento::entradasVendidas()
{
    NodoZona* actual = zonas->getPrimero();
    int vendidos = 0;

    while (actual != nullptr) {
        vendidos += actual->getZona()->getOcupados();
        actual = actual->getSiguiente();
        if (vendidos > 0) {
            return vendidos;
        }
    }
}
string Segmento::toString() {
    stringstream s;
    NodoZona* actual = zonas->getPrimero();

    s << "Segmento: " << nombre << "\n";
    s << "Precio por asiento: " << precio << " colones.\n";
    s << "Zonas asociadas:\n";

    if (actual == nullptr) {
        s << "No hay zonas asociadas a este segmento.\n";
    }
    else {
        while (actual != nullptr) {
            s << actual->getZona()->toString() << "\n";
            actual = actual->getSiguiente();
        }
    }
    return s.str();
}

