#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class CodigoDescuento
{
private:
	string codigosDescuento;
	bool descuentoUsado;
	double porcentajeDescuento;
	int canUsos;
public:
    CodigoDescuento();
	CodigoDescuento(string cod, double porcentaje,int usos);
	~CodigoDescuento();

	bool getDescuentoUsado();
	double getPorcentajeDescuento();
	int getCantidadUsos();

	void setCodigoDescuento(string cod);
	void setDescuentoUsado(bool desc);
	void setPorcentajeDescuento(double porcentaje);
	void setCantidadUsos(int usos);

	void generarCodigosDeDescuentos();
	string obtenerCodigoGenerado();

	
};

