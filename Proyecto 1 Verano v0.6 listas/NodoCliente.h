#pragma once
#include "Cliente.h"	
class NodoCliente
{
private:
	Cliente* cliente;
	NodoCliente* siguiente;
public:
		NodoCliente(Cliente*);
		virtual ~NodoCliente();
		Cliente* getCliente()const;
		void setCliente(Cliente*);
		NodoCliente* getSiguiente()const;
		void setSiguiente(NodoCliente*);
};

