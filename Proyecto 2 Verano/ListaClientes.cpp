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

void ListaClientes::agregarClienteAlFinal(Cliente* cliente)
{
	NodoCliente* nuevoCliente = new NodoCliente(cliente);

	if (nuevoCliente == nullptr)
	{
		cout << "No se pudo agregar el cliente" << endl;
		return;
	}
	if (primero == nullptr)
	{
		primero = nuevoCliente;
		return;
	}
	else
	{
		actual = primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevoCliente);
		cout << "Cliente agregado correctamente" << endl;
		return;
	}
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
			if (primero == nullptr) {
				actual = nullptr;
			}
			return true;
		}
		borrarCliente = actual;
		actual = actual->getSiguiente();
	}
	return false;  //no se encontro el cliente
}
Cliente* ListaClientes::buscarClientePorCedula(string ced) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getCliente()->getCedula() == ced) {
			return actual->getCliente();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;  // Retorna nullptr si no se encuentra el cliente
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
		s << actual->getCliente()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}