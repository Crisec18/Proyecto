#include "ListaSegmentos.h"

ListaSegmentos::ListaSegmentos()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
}

ListaSegmentos::~ListaSegmentos()
{
}

NodoSegmento* ListaSegmentos::getPrimero()const
{
	return primero;
}

void ListaSegmentos::setPrimero(NodoSegmento* primero)
{
	this->primero = primero;
}

NodoSegmento* ListaSegmentos::getUltimo()const
{
	return ultimo;
}

void ListaSegmentos::setUltimo(NodoSegmento* ultimo)
{
	this->ultimo = ultimo;
}

//por hacer el editar segmento

void ListaSegmentos::agregarSegmentoAlFinal(Segmento* segmento)
{
	NodoSegmento* nuevo = new NodoSegmento(segmento);
	if (nuevo == nullptr)
	{
		return;
	}
	if (primero == nullptr)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
}

Segmento* ListaSegmentos::buscarSegmentoPorPosicion(int pos)
{
	NodoSegmento* actual = primero;
	int contador = 0;
	while (actual != nullptr) {
		if (contador == pos) {
			return actual->getSegmento();
		}
		actual = actual->getSiguiente();
		contador++;
	}
	return nullptr;  //no existe en esa posicion
}


string ListaSegmentos::toString()
{
	stringstream s;
	NodoSegmento* actual = primero;
	while (actual != nullptr)
	{
		s << actual->getSegmento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
