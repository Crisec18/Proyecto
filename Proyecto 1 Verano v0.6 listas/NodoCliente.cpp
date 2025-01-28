#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente* cliente)
{
	this->cliente = cliente;
	this->siguiente = NULL;
}

NodoCliente::~NodoCliente()
{
}

Cliente* NodoCliente::getCliente()const
{
	return cliente;
}	

void NodoCliente::setCliente(Cliente* cliente)
{
	this->cliente = cliente;
}

NodoCliente* NodoCliente::getSiguiente()const
{
	return siguiente;
}	

void NodoCliente::setSiguiente(NodoCliente* siguiente)
{
	this->siguiente = siguiente;
}	

