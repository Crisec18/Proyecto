#include "CodigoDescuento.h"

CodigoDescuento::CodigoDescuento() : codigosDescuento(""), descuentoUsado(false), porcentajeDescuento(0.0), canUsos(0) {
    
}

CodigoDescuento::CodigoDescuento(string cod,double porcentaje, int usos)
    : descuentoUsado(false), codigosDescuento(cod) {
    if (porcentaje <= 50) {
        porcentajeDescuento = porcentaje;
    }
    else {
        cout << "Porcentaje de descuento NO valido (Debe estar entre 1 y 50)" << endl;
        return;
    }
    if (usos > 0) {
        canUsos = usos;
    }
    else {
        cout << "Cantidad de usos no valida (Debe ser mayor a 0)" << endl;
        return;
    }
}

CodigoDescuento::CodigoDescuento(double porcentaje, int usos)
    : descuentoUsado(false){
    if(porcentaje <= 50){
        porcentajeDescuento = porcentaje;
    }
	else{
		cout << "Porcentaje de descuento NO valido (Debe estar entre 1 y 50)" << endl;
        return;
	}
    if (usos > 0) {
		canUsos = usos;
	}
	else {
		cout << "Cantidad de usos no valida (Debe ser mayor a 0)" << endl;
        return;
	}
}

CodigoDescuento::~CodigoDescuento() {}


string CodigoDescuento::getCodigoDescuento()
{
    return codigosDescuento;
}

bool CodigoDescuento::getDescuentoUsado() { return descuentoUsado; }
double CodigoDescuento::getPorcentajeDescuento() { return porcentajeDescuento; }
int CodigoDescuento::getCantidadUsos() { return canUsos; }

void CodigoDescuento::setCodigoDescuento(string cod) { codigosDescuento = cod; }
void CodigoDescuento::setDescuentoUsado(bool desc) { descuentoUsado = desc; }
void CodigoDescuento::setPorcentajeDescuento(double porcentaje) { porcentajeDescuento = porcentaje; }
void CodigoDescuento::setCantidadUsos(int usos) { canUsos = usos; }

//void CodigoDescuento::generarCodigosDeDescuentos()
//{
//    const int tamanio = 4;
//    string codigo;
//
//    const char alphanum[] =
//        "0123456789"
//        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//        "abcdefghijklmnopqrstuvwxyz";
//    srand(time(0));
//    for (int i = 0; i < tamanio; i++)
//    {
//        codigo += alphanum[rand() % (sizeof(alphanum) - 1)];
//    }
//
//    setCodigoDescuento(codigo);
//}

bool CodigoDescuento::aplicarDescuento() {
    if (canUsos > 0) {
        canUsos--;
        if (canUsos == 0) {
            descuentoUsado = true; // usado cuando se agotan los usos
        }
        return true;
    }
    return false; // No se puede aplicar el descuento si ya no hay usos
}

