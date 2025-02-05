#pragma once
#include <iostream>
#include <sstream>
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
	CodigoDescuento(double porcentaje, int usos);
	CodigoDescuento(string cod,double porcentaje,int usos);
	~CodigoDescuento();

	string getCodigoDescuento();
	bool getDescuentoUsado();
	double getPorcentajeDescuento();
	int getCantidadUsos();

	void setCodigoDescuento(string);
	void setDescuentoUsado(bool desc);
	void setPorcentajeDescuento(double porcentaje);
	void setCantidadUsos(int usos);

	bool aplicarDescuento();
	//void generarCodigosDeDescuentos();
	
};

