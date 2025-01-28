#include "ListaClientes.h"

ListaClientes::ListaClientes()
{
	this->primero = nullptr;  //puntero que apunta al primer nodo de la lista
	this->actual = nullptr;  //puntero que apunta al nodo actual de la lista y el que va a recorrer la lista
}

ListaClientes::~ListaClientes()
{
	eliminaTodos();
}

NodoCliente* ListaClientes::getPrimero()const
{
	return primero;
}

void ListaClientes::setPrimero(NodoCliente* primero)
{
	this->primero = primero;
}

NodoCliente* ListaClientes::getActual()const
{
	return actual;
}

void ListaClientes::setActual(NodoCliente* actual)
{
	this->actual = actual;
}

bool ListaClientes::agregarClienteAlFinal(Cliente* cliente)
{
	NodoCliente* nuevoCliente = new NodoCliente(cliente);

	if (nuevoCliente == nullptr)
	{
		return false;
	}
	if (primero == nullptr)
	{
		primero = nuevoCliente;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevoCliente);
	}
	return true;
}

Cliente* ListaClientes::buscarCliente(string cedula)
{
	actual = primero;  //igualamos los punteros para que actual recorra la lista

	while (actual != nullptr)
	{
		if (actual->getCliente()->getCedula() == cedula)
		{
			return actual->getCliente();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;  //no se encontro el cliente
}

bool ListaClientes::eliminarCliente(string cedula)
{
	NodoCliente* borrarCliente = nullptr;  //creamos un puntero para borrar el cliente
	actual = primero;

	while (actual != nullptr)
	{
		if (actual->getCliente()->getCedula() == cedula)
		{
			if (actual == primero)
			{
				primero = actual->getSiguiente();
			}
			else
			{
				borrarCliente->setSiguiente(actual->getSiguiente());
			}
			delete actual;
			return true;
		}
		borrarCliente = actual;
		actual = actual->getSiguiente();
	}
	return false;  //no se encontro el cliente
}

bool ListaClientes::buscarClientePorCedula(string ced)
{
	actual = primero;

	while (actual != nullptr) {
		if (actual->getCliente()->getCedula() == ced) {
		return true;
		}
		return false;
	}
	return false;
}

void ListaClientes::eliminaTodos()
{
	//borra todos los nodos de la lista
	actual = primero;
	while (actual != nullptr)
	{
		primero = actual->getSiguiente();
		delete actual;
		actual = primero;
	}
}

string ListaClientes::toString()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s<<actual->getCliente()->toString() << endl;
		actual->getSiguiente();
	}
	return s.str();
}