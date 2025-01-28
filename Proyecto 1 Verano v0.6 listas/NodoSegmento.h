#pragma once
#include "Segmento.h"
class NodoSegmento
{
private:
	Segmento* segmento;
	NodoSegmento* siguiente;
public:
	NodoSegmento();
	NodoSegmento(Segmento*);
	~NodoSegmento();

	Segmento* getSegmento()const;
	void setSegmento(Segmento*);

	NodoSegmento* getSiguiente()const;
	void setSiguiente(NodoSegmento*);
};

