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
	
	bool agregarZonaAlFinal(Zona*);
	//Zona* buscarZona(string);
	bool eliminarZona(string);
	void eliminarTodas();

	string toString();
};

