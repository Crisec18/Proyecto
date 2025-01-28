#include "Evento.h"

Evento::Evento()
    : tamMaximo(0), canSegmentos(0), canDescuento(0), segmentos(nullptr), codigos(nullptr) {
}

Evento::Evento(int tamMax) : tamMaximo(tamMax), canSegmentos(0), canDescuento(0) {
    segmentos = new ListaSegmentos();
    codigos = new ListaCodigosDescuento();
}

Evento::~Evento() {
    eliminaTodo();
}

int Evento::getCanSegmentos() const { return canSegmentos; }

bool Evento::agregarSegmento(Segmento* seg) {
   segmentos->agregarSegmentoAlFinal(seg);
}


Segmento* Evento::obtenerSegmento(int n) {
  /*  segmentos->buscarSegmento(n);*/ 
}

//void Evento::eliminaTodo() {
//   
//}

void Evento::establecerPrecioSegmento(Segmento* seg, double precio) {
   segmentos->
}

//descuentos

string Evento::mostrarCodigosDescuento() const {
    stringstream s;
    s << "Codigos de descuento: " << endl << endl;
    for (int i = 0; i < 20; i++) {
        if (descuentos[i] != nullptr && descuentos[i]->getCodigosDescuento() != "0000") {
            s << " - " << descuentos[i]->getCodigosDescuento() << " (" << descuentos[i]->getPorcentajeDescuento() << "%) "
                << (descuentos[i]->getDescuentoUsado() ? "(usado)" : "(disponible)") << endl;
        }
    }
    return s.str();
}

int Evento::espacioDisponibles() {
    int total = 0;
    for (int i = 0; i < canSegmentos; ++i) {
        total += segmentos[i]->getEspaciosDisponibles();
    }
    return total;
}

string Evento::mostrarTotalDisponibles() {
    stringstream s;
    s << "Total de espacios disponibles: " + to_string(espacioDisponibles()) + "\n";
    return s.str();
}

string Evento::mostrarSegmentoEspecifico(int seg) {
    if (seg < 0 || seg >= canSegmentos) {
        return "Segmento fuera de rango.";
    }
    return segmentos[seg]->toString();
}

bool Evento::comprarEntrada(ContenedoraClientes* co1, string ced, int seg, int fila, int columna)
{
    Cliente* cliente = co1->buscaClientePorCedula(ced);
    if (cliente == nullptr) {
        cout << "Cliente no encontrado" << endl;
        return false;
    }
    //se guarda el segmento por ser un arreglo de punteros
    Segmento* segmento = segmentos[seg];

    if (seg < 0 || seg >= canSegmentos) {
        cout << "Segmento fuera de rango" << endl;
        return false;
    }
    
    for (int i = 0; i < segmento->getCantZonas(); i++) {
        Zona* zona = segmentos[seg]->getZona(i);

        if (zona != nullptr && zona->asignarCliente(cliente, fila, columna)) {
            cout<<"Compra realizada con exito"<<endl;
           
            return true;
       }
    }
    cout << "No se pudo realizar la compra" << endl;
    return false;
}

void Evento::aplicarDescuento(Cliente* cliente, float porcentaje)
{
    if (porcentaje <= 0 || porcentaje > 50) {
        cout << "El porcentaje de descuento debe ser mayor a 0 y menor o igual a 50" << endl;
        return;
    }
    cliente->aplicaDescuento(porcentaje);
}

