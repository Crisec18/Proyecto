#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre;
	string cedula;
	int fechaNacimiento;
	int maxEntrada;   //limete de compras por cliente
	float descuento;  //descuento por cliente
public:
	Cliente(string = "----", string = "----", int = 0);
	virtual ~Cliente();

	string getNombre()const;
	string getCedula()const;
	int getFechaN()const;
	int getMaxEntrada()const;
	float getDescuento()const;

	//void
	void setNombre(string);
	void setCedula(string);
	void setFechaN(int);
	void setDescuento(float);

	void aplicaDescuento(float);
	bool comprarEntrada();

	string toString();
};

