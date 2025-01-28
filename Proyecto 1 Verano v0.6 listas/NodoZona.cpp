#include "NodoZona.h"

NodoZona::NodoZona()
{
	this->zona = nullptr;
	this->siguiente = nullptr;
}

NodoZona::NodoZona(Zona* zona)
{
	this->zona = zona;
	this->siguiente = nullptr;
}

NodoZona::~NodoZona()
{
}

Zona* NodoZona::getZona()const
{
	return zona;
}

void NodoZona::setZona(Zona* zona)
{
	this->zona = zona;
}

NodoZona* NodoZona::getSiguiente()const
{
	return siguiente;
}

void NodoZona::setSiguiente(NodoZona* siguiente)
{
	this->siguiente = siguiente;
}
