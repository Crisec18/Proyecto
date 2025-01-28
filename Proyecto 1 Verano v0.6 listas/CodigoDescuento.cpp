#include "CodigoDescuento.h"

CodigoDescuento::CodigoDescuento() : codigosDescuento(""), descuentoUsado(false), porcentajeDescuento(0.0), canUsos(0) {}

CodigoDescuento::CodigoDescuento(string cod, double porcentaje, int usos)
    : codigosDescuento(cod), descuentoUsado(false), porcentajeDescuento(porcentaje), canUsos(usos) {}

CodigoDescuento::~CodigoDescuento() {}


bool CodigoDescuento::getDescuentoUsado() { return descuentoUsado; }
double CodigoDescuento::getPorcentajeDescuento() { return porcentajeDescuento; }
int CodigoDescuento::getCantidadUsos() { return canUsos; }

void CodigoDescuento::setCodigoDescuento(string cod) { codigosDescuento = cod; }
void CodigoDescuento::setDescuentoUsado(bool desc) { descuentoUsado = desc; }
void CodigoDescuento::setPorcentajeDescuento(double porcentaje) { porcentajeDescuento = porcentaje; }
void CodigoDescuento::setCantidadUsos(int usos) { canUsos = usos; }

void CodigoDescuento::generarCodigosDeDescuentos()
{
    const int tamanio = 4;
    string codigo;

    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand(time(0)); // Inicializa la semilla para la generación de números aleatorios

    for (int i = 0; i < tamanio; i++)
    {
        codigo += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    setCodigoDescuento(codigo);
}

string CodigoDescuento::obtenerCodigoGenerado()
{
    return codigosDescuento;
}
