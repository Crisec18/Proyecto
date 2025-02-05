#pragma once
#include "Zona.h"
class NodoZona{
private:
	Zona* zona;
	NodoZona* siguiente;
public:
	NodoZona(Zona*);
	~NodoZona();

	Zona* getZona()const;
	void setZona(Zona*);

	NodoZona* getSiguiente()const;
	void setSiguiente(NodoZona*);
};

