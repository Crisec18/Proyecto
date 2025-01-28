#include "Cliente.h"

Cliente::Cliente(string nom, string ced, int annio) 
	:nombre(nom), cedula(ced), fechaNacimiento(annio), maxEntrada(5), descuento(0) {}

Cliente::~Cliente() {}

string Cliente::getNombre() const { return nombre; }
string Cliente::getCedula() const { return cedula; }
int Cliente::getFechaN() const { return fechaNacimiento; }
int Cliente::getMaxEntrada() const { return maxEntrada; }

float Cliente::getDescuento() const { return descuento; }

void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setCedula(string ced) { cedula = ced; }
void Cliente::setFechaN(int annio) { fechaNacimiento = annio; }
void Cliente::setDescuento(float desc) { descuento = desc; }

void Cliente::aplicaDescuento(float)
{
	setDescuento(descuento);
}

bool Cliente::comprarEntrada()
{
	if (maxEntrada > 0) {
		maxEntrada--;
		return true;
	}
	else
	{
		cout << "No se puede comprar mas entradas" << endl;
		return false;
	}
}


string Cliente::toString() {
	stringstream s;

	s << " - Datos del Cliente. " << endl;
	s << " - Nombre: " << nombre << endl;
	s << " - Cedula: " << cedula << endl;
	s << " - Edad: " << 2025 - fechaNacimiento << " Anio de nacimiento: " << fechaNacimiento << endl;
	s << " - Entradas restantes: " << maxEntrada << endl;
	s << " - Descuento: " << descuento << endl;
	return s.str();
}
