#pragma once
#include "NodoSegmento.h"
class ListaSegmentos
{
private: 		
	NodoSegmento* primero;
	NodoSegmento* actual;
public:
	ListaSegmentos();
	virtual ~ListaSegmentos();
	
	NodoSegmento* getPrimero()const;
	void setPrimero(NodoSegmento*);
	
	NodoSegmento* getActual()const;
	void setActual(NodoSegmento*);
	
	
	bool editaSegmento(int);
	int cantidadSegmentos();
	bool agregarSegmentoAlFinal(Segmento*);
	Segmento* buscarSegmentoPorPosicion(int pos);
	bool eliminarSegmento(int);
	void eliminaTodos();
	void entradasVendidas();
	int espaciosDisponibles();

	string toString();
};

