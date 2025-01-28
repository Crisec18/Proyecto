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
	
	bool agregarClienteAlFinal(Cliente*);
	Cliente* buscarCliente(string);
	bool eliminarCliente(string);
	bool buscarClientePorCedula(string);
	void eliminaTodos();

	string toString();
};

