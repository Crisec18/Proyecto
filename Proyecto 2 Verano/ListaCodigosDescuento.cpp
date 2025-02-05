#include "ListaCodigosDescuento.h"

ListaCodigosDescuento::ListaCodigosDescuento()
{
	primero = nullptr;
	actual = nullptr;
}

ListaCodigosDescuento::~ListaCodigosDescuento()
{
	eliminarTodos();
}

NodoCodigo* ListaCodigosDescuento::getPrimero()const
{
	return primero;
}

void ListaCodigosDescuento::setPrimero(NodoCodigo* primero)
{
	this->primero = primero;
}

NodoCodigo* ListaCodigosDescuento::getActual()const
{
	return actual;
}

void ListaCodigosDescuento::setActual(NodoCodigo* actual)
{
	this->actual = actual;
}	

bool ListaCodigosDescuento::agregarCodigoAlFinal(CodigoDescuento* codigo)
{
	NodoCodigo* nuevoCodigo = new NodoCodigo(codigo);
	actual = primero;

	if (primero == nullptr)
	{
		primero = nuevoCodigo;
	}
	else
	{
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevoCodigo);
	}
	return true;
}

CodigoDescuento* ListaCodigosDescuento::buscarCodigo(string codigo)
{
	//tiene la utilidad para buscar el que se va borrar mas adelante
	actual = primero;  //igualamos los punteros para que actual recorra la lista

	while (actual != nullptr)
	{
		if (actual->getCodigo()->getCodigoDescuento() == codigo)
		{
			return actual->getCodigo();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}

bool ListaCodigosDescuento::eliminarCodigo(string codigo)
{
	NodoCodigo* nodoAnterior = nullptr;
	actual = primero;

	while (actual != nullptr) {
		if (actual->getCodigo()->getCodigoDescuento() == codigo) {
			if (actual->getCodigo()->getDescuentoUsado()) {
				cout << "El codigo ya fue usado y no puede eliminarse." << endl;
				return false;
			}
			if (nodoAnterior == nullptr) {
				primero = actual->getSiguiente();
			}
			else {
				nodoAnterior->setSiguiente(actual->getSiguiente());
			}
			delete actual->getCodigo();
			delete actual;
			return true;
		}
		nodoAnterior = actual;
		actual = actual->getSiguiente();
	}
	cout << "Codigo no encontrado." << endl;
	return false;
}

void ListaCodigosDescuento::eliminarTodos()
{
	actual = primero;
	while (actual != nullptr)
	{
		primero = actual->getSiguiente();
		delete actual;
		actual = primero;
	}
}

string ListaCodigosDescuento::generarCodigo()
{
	static const char caracteres[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";

	int longitud = 4;
	stringstream codigo;

	for (int i = 0; i < longitud; i++) {
		codigo << caracteres[rand() % (sizeof(caracteres) - 1)];
	}

	return codigo.str();
}

bool ListaCodigosDescuento::generarCodigosDescuento(int porcentaje, int canUsos, int cantidad) {
	if (porcentaje < 1 || porcentaje > 50) {
		cout << "Porcentaje de descuento NO valido (Debe estar entre 1 y 50)" << endl;
		return false;
	}
	bool agregado = false;

	for (int i = 0; i < cantidad; i++) {
		string codigo = generarCodigo();
		CodigoDescuento* nuevoCodigo = new CodigoDescuento(codigo, porcentaje, canUsos);

		if (agregarCodigoAlFinal(nuevoCodigo)) {
			agregado = true;
		}
	}
	return agregado;
}

string ListaCodigosDescuento::toString()
{
	stringstream s;
	actual = primero;
	if (primero == nullptr) {
		s << "No hay codigos de descuento por el momento." << endl;
	}
	s << "+-----------[ LISTA DE CODIGOS ]-----------+\n";
	while (actual != nullptr) {
		s << "Codigo: " << actual->getCodigo()->getCodigoDescuento() << "\n";
		s << "Descuento: " << actual->getCodigo()->getPorcentajeDescuento() << "%\n";
		s << "Usos restantes: " << actual->getCodigo()->getCantidadUsos() << "\n";
		s << "-------------------------------------------\n";
		actual = actual->getSiguiente();
	}
	return s.str();
}