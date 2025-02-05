#include "NodoCodigo.h"

NodoCodigo::NodoCodigo()
{
	this->codigo = nullptr;
	this->siguiente = nullptr;
}

NodoCodigo::NodoCodigo(CodigoDescuento* codigo)
{
	this->codigo = codigo;
	this->siguiente = nullptr;
}

NodoCodigo::~NodoCodigo()
{
}

CodigoDescuento* NodoCodigo::getCodigo()const
{
	return codigo;
}

void NodoCodigo::setCodigo(CodigoDescuento* codigo)
{
	this->codigo = codigo;
}

NodoCodigo* NodoCodigo::getSiguiente()const
{
	return siguiente;
}	

void NodoCodigo::setSiguiente(NodoCodigo* siguiente)
{
	this->siguiente = siguiente;
}	

