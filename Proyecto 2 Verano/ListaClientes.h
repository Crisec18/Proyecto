#pragma once
#include "NodoCliente.h"
class ListaClientes
{
private:
	NodoCliente* primero;
	NodoCliente* actual;
public:
	ListaClientes();
	virtual ~ListaClientes();
	
	NodoCliente* getPrimero()const;
	void setPrimero(NodoCliente*);
	
	NodoCliente* getActual()const;
	void setActual(NodoCliente*);
	
	void agregarClienteAlFinal(Cliente*);
	//Cliente* buscarClientePorPosicion(int);
	bool eliminarCliente(string);
	Cliente* buscarClientePorCedula(string);
	void eliminaTodos();

	string toString();
};

