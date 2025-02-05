#include "NodoSegmento.h"


NodoSegmento::NodoSegmento(Segmento* segmento)
{
	this->segmento = segmento;
	this->siguiente = nullptr;
}

NodoSegmento::~NodoSegmento()
{
}

Segmento* NodoSegmento::getSegmento()const
{
	return segmento;
}

void NodoSegmento::setSegmento(Segmento* segmento)
{
	this->segmento = segmento;
}

NodoSegmento* NodoSegmento::getSiguiente()const
{
	return siguiente;
}

void NodoSegmento::setSiguiente(NodoSegmento* siguiente)
{
	this->siguiente = siguiente;
}

