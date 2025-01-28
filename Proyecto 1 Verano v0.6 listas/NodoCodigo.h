#pragma once
#include "CodigoDescuento.h"
class NodoCodigo
{
private:
	CodigoDescuento* codigo;
	NodoCodigo* siguiente;
public:
	NodoCodigo();
	NodoCodigo(CodigoDescuento*);
	~NodoCodigo();

	CodigoDescuento* getCodigo()const;
	void setCodigo(CodigoDescuento*);

	NodoCodigo* getSiguiente()const;
	void setSiguiente(NodoCodigo*);
};

