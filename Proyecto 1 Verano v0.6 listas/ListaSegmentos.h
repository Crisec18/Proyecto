#pragma once
#include "NodoSegmento.h"
class ListaSegmentos
{
private: 		
	NodoSegmento* primero;
	NodoSegmento* ultimo;
public:
	ListaSegmentos();
	virtual ~ListaSegmentos();
	
	NodoSegmento* getPrimero()const;
	void setPrimero(NodoSegmento*);
	
	NodoSegmento* getUltimo()const;
	void setUltimo(NodoSegmento*);
	
	
	bool editaSegmento(int);
	void agregarSegmentoAlFinal(Segmento*);
	Segmento* buscarSegmentoPorPosicion(int pos);
	bool eliminarSegmento(string);
	void eliminaTodos();

	string toString();
};

