#pragma once
#include "NodoZona.h"
class ListaZonas
{
private:
	NodoZona* primero;
	NodoZona* actual;
public:
	ListaZonas();
	virtual ~ListaZonas();
	
	NodoZona* getPrimero()const;
	void setPrimero(NodoZona*);
	
	NodoZona* getActual()const;
	void setActual(NodoZona*);
	
	void agregarZonaAlFinal(Zona*);
	int cantidadEspacios();
	int getDisponibles();
	Zona* buscarZonaPorPosicion(int);
	bool eliminarZona(string);
	void eliminarTodas();

	string toString();
};

