#pragma once
#include "NodoCodigo.h"

class ListaCodigosDescuento
{
private:
	NodoCodigo* primero;
	NodoCodigo* actual;
public:
	ListaCodigosDescuento();
	virtual ~ListaCodigosDescuento();
	
	NodoCodigo* getPrimero()const;
	void setPrimero(NodoCodigo*);
	
	NodoCodigo* getActual()const;
	void setActual(NodoCodigo*);
	
	bool agregarCodigoAlFinal(CodigoDescuento*);
	CodigoDescuento* buscarCodigo(string);
	bool eliminarCodigo(string);
	void eliminarTodos();
	void generarCodigosDescuento(int can, double porcentaje, int usos);

	string toString();
};

