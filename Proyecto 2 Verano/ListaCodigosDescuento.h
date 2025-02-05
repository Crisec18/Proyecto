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
	string generarCodigo();
	bool generarCodigosDescuento(int porcentaje, int canUsos, int cantidad);

	string toString();
};

