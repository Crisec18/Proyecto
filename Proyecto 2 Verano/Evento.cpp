#include "Evento.h"

Evento::Evento() : canSegmentos(0), canDescuento(0) {
    segmentos = new ListaSegmentos();
    codigos = new ListaCodigosDescuento();
}

Evento::~Evento() {
    eliminaTodo();
}

int Evento::getCanSegmentos() const { return canSegmentos; }

bool Evento::agregarSegmento(Segmento* seg) {
    if (segmentos->agregarSegmentoAlFinal(seg)) {
        cout << "Agregado con éxito" << endl;
        return true;
    }
    cout << "Fallo al agregar" << endl;
    return false;
}


Segmento* Evento::obtenerSegmento(int n) {
    return segmentos->buscarSegmentoPorPosicion(n);
}

void Evento::eliminaTodo() {
    if (segmentos) {
        delete segmentos;
        segmentos = nullptr;
    }
    if (codigos) {
        delete codigos;
        codigos = nullptr;
    }
    canSegmentos = 0;
    canDescuento = 0;
}

//void Evento::establecerPrecioSegmento(int n, double precio) {
//   segmentos->buscarSegmentoPorPosicion(n)->setPrecio(precio);
//}

//descuentos

string Evento::mostrarCodigosDescuento() const {
    return codigos->toString();
}

int Evento::espacioDisponibles() {
    return segmentos->cantidadSegmentos();
}

string Evento::mostrarTotalDisponibles() {
    stringstream s;
    s << "Total de espacios disponibles: " + to_string(espacioDisponibles()) + "\n";
    return s.str();
}

string Evento::mostrarSegmentoEspecifico(int seg) {
    Segmento* segmento = segmentos->buscarSegmentoPorPosicion(seg);
    if (segmento != nullptr) {
        return segmento->toString();
    }
    return "Segmento no encontrado.";
}

Zona* Evento::obtenerZona(int posSegmento, int posZona)
{
    Segmento* segmento = segmentos->buscarSegmentoPorPosicion(posSegmento);
    if (segmento != nullptr) {
        return segmento->getZona(posZona);
    }
    return nullptr; // Si el segmento o la zona no existen

}

bool Evento::comprarEntrada(ListaClientes* lista, string ced, int seg, int fila, int columna) {
    Cliente* cliente = lista->buscarClientePorCedula(ced);
    if (cliente == nullptr) {
        cout << "Cliente no encontrado" << endl;
        return false;
    }

    Segmento* segmento = segmentos->buscarSegmentoPorPosicion(seg);
    if (segmento == nullptr) {
        cout << "Segmento no encontrado" << endl;
        return false;
    }

    for (int i = 0; i < segmento->getCantZonas(); i++) {
        Zona* zona = segmento->getZona(i);
        if (zona != nullptr && zona->asignarCliente(cliente, fila, columna)) {
            cout << "Compra realizada con éxito" << endl;
            return true;
        }
    }

    cout << "No se pudo realizar la compra" << endl;
    return false;
}


bool Evento::aplicarDescuento(Cliente* cliente, double porcentaje)
{
 /*   CodigoDescuento* nuevoCodigo = new CodigoDescuento(porcentaje);
    return codigos->agregarCodigoAlFinal(nuevoCodigo);*/
    return 0;
}

