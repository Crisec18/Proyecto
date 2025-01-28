#include "ListaCodigosDescuento.h"

ListaCodigosDescuento::ListaCodigosDescuento()
{
	primero = nullptr;
	actual = nullptr;
}

ListaCodigosDescuento::~ListaCodigosDescuento()
{
	eliminarTodos();
}

NodoCodigo* ListaCodigosDescuento::getPrimero()const
{
	return primero;
}

void ListaCodigosDescuento::setPrimero(NodoCodigo* primero)
{
	this->primero = primero;
}

NodoCodigo* ListaCodigosDescuento::getActual()const
{
	return actual;
}

void ListaCodigosDescuento::setActual(NodoCodigo* actual)
{
	this->actual = actual;
}	

bool ListaCodigosDescuento::agregarCodigoAlFinal(CodigoDescuento* codigo)
{
	NodoCodigo* nuevoCodigo = new NodoCodigo(codigo);

	if (nuevoCodigo == nullptr)
	{
		return false;
	}
	if (primero == nullptr)
	{
		primero = nuevoCodigo;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevoCodigo);
	}
	return true;
}

CodigoDescuento* ListaCodigosDescuento::buscarCodigo(string codigo)
{
	//tiene la utilidad para buscar el que se va borrar mas adelante
	actual = primero;  //igualamos los punteros para que actual recorra la lista

	while (actual != nullptr)
	{
		if (actual->getCodigo()->obtenerCodigoGenerado() == codigo)
		{
			return actual->getCodigo();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}

bool ListaCodigosDescuento::eliminarCodigo(string codigo)
{
	NodoCodigo* anterior = nullptr;
	actual = primero;  //igualamos los punteros para que actual recorra la lista

	

	while (actual != nullptr)
	{
		if (actual->getCodigo()->obtenerCodigoGenerado() == codigo)
		{
			if (actual->getCodigo()->getDescuentoUsado()) {  //verifica si el codigo se uso
				return false;                               //si se uso no se puede borrar
			}
			if (anterior == nullptr)
			{
				primero = actual->getSiguiente();
			}
			else
			{
				anterior->setSiguiente(actual->getSiguiente());
			}
			delete actual;
			return true;
		}
		anterior = actual;
		actual = actual->getSiguiente();
	}
	return false;
}

void ListaCodigosDescuento::eliminarTodos()
{
	actual = primero;
	while (actual != nullptr)
	{
		primero = actual->getSiguiente();
		delete actual;
		actual = primero;
	}
}

void ListaCodigosDescuento::generarCodigosDescuento(int cantidad, double porcentajeDescuento, int cantidadUsos) {
	//genera la cantidad de codigos que se le pase 5, 10, 100 y los va rellenando con los usos, porcentaje, etc
	for (int i = 0; i < cantidad; i++) { 

		CodigoDescuento* nuevoCodigo = new CodigoDescuento();
		nuevoCodigo->generarCodigosDeDescuentos();
		nuevoCodigo->setPorcentajeDescuento(porcentajeDescuento);
		nuevoCodigo->setCantidadUsos(cantidadUsos);
		agregarCodigoAlFinal(nuevoCodigo);
	}
}
