#ifndef ZONA_H
#define ZONA_H
#pragma once
#include "ListaClientes.h"

//Aqui se crea la matriz
//Los asientos para los clientes
class Zona
{
private:
	int segmento;
	int fila;
	int columna;
	int disponible;
	double precio;       //precio de la zona que es el mismo que el del segmento
	ListaClientes** asiento;  //matriz de asientos

public:
	Zona();
	Zona(int, int);
	virtual ~Zona();

	int getFila();
	int getColumna();
	int getEspacios();
	int getDisponibles();
	int getOcupados();
	double getPrecio();
	void setPrecio(double);

	Cliente* getCliente(int, int);

	bool asignarCliente(Cliente*, int, int);
	bool compraAsiento(ListaClientes*, string, int, int);
	void muestraLibres();

	
	string toString();

};
#endif  //ZONA_H


