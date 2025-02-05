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

void ListaZonas::agregarZonaAlFinal(Zona* zona)
{
	NodoZona* nuevo = new NodoZona(zona);

	if (nuevo == nullptr)  // por si no tiene nada
	{
		cout << "No se puede agregar zona vacia" << endl;
		return;
	}
	if (primero == nullptr)
	{
		primero = nuevo;
		return;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
		cout << "Zona agregada correctamente" << endl;
		return;
	}
}

int ListaZonas::cantidadEspacios()
{
	actual = primero;
	int contador = 0;
	while (actual != nullptr)
	{
		contador++;
		actual = actual->getSiguiente();
	}
	return contador;
}

int ListaZonas::getDisponibles()
{
	actual = primero;
	int totalDisponibles = 0;

	while (actual != nullptr) {
		totalDisponibles += actual->getZona()->getDisponibles();
		actual = actual->getSiguiente();
	}
	return totalDisponibles;
}

Zona* ListaZonas::buscarZonaPorPosicion(int n)
{
	actual = primero;
	if (actual != nullptr) {
		for (int i = 0; i < n; i++)
		{
			actual = actual->getSiguiente();
			return actual->getZona();
		}
	}
	else
	{
		cout << "No hay zonas en las posicion: " << n << endl;
		return nullptr;
	}
}

void ListaZonas::eliminarTodas()
{
	actual = primero;
	while (actual != nullptr)
	{
		NodoZona* siguiente = actual->getSiguiente();
		delete actual->getZona();  
		delete actual;
		actual = siguiente;
	}
}

string ListaZonas::toString()
{
	stringstream s;
	actual = primero;
	if (primero == nullptr) {
		s << "No hay zonas agregadas" << endl;
	}
	while (actual != nullptr)
	{
		s << actual->getZona()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}


