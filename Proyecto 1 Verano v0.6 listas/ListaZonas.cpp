#include "ListaZonas.h"

ListaZonas::ListaZonas()
{
	this->primero = nullptr;
	this->actual = nullptr;
}

ListaZonas::~ListaZonas()
{
	eliminarTodas();
}

NodoZona* ListaZonas::getPrimero()const
{
	return primero;
}

void ListaZonas::setPrimero(NodoZona* primero)
{
	this->primero = primero;
}

NodoZona* ListaZonas::getActual()const
{
	return actual;
}

void ListaZonas::setActual(NodoZona* actual)
{
	this->actual = actual;
}

bool ListaZonas::agregarZonaAlFinal(Zona* zona)
{
	NodoZona* nuevo = new NodoZona(zona);
	if (nuevo == nullptr)
	{
		return false;
	}
	if (primero == nullptr)
	{
		primero = nuevo;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
	return true;
}

void ListaZonas::eliminarTodas()
{
	actual = primero;
	while (actual != nullptr)
	{
		primero = actual->getSiguiente();
		delete actual;
		actual = primero;
	}
}

string ListaZonas::toString()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr)
	{
		s << actual->getZona()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}


