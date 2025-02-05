#include "ListaSegmentos.h"

ListaSegmentos::ListaSegmentos()
{
	this->primero = nullptr;
	this->actual = nullptr;
}

ListaSegmentos::~ListaSegmentos()
{
}

NodoSegmento* ListaSegmentos::getPrimero()const
{
	return primero;
}

void ListaSegmentos::setPrimero(NodoSegmento* primero)
{
	this->primero = primero;
}

NodoSegmento* ListaSegmentos::getActual()const
{
	return actual;
}

void ListaSegmentos::setActual(NodoSegmento* actual)
{
	this->actual = actual;
}

//por hacer el editar segmento
bool ListaSegmentos::editaSegmento(int pos)
{
    actual = primero;
    int contador = 0;

    while (actual != nullptr) {
        if (contador == pos) {
            Segmento* segmento = actual->getSegmento();

            // Verificar si ya se han vendido entradas
            if (segmento->entradasVendidas() > 0) {
                cout << "No se puede editar este segmento porque ya se han vendido entradas." << endl;
                return false;
            }

            // Pedir nuevos datos
            string nuevoNombre;
            double nuevoPrecio;
            int opcionZona;

            cout << " Ingrese el nuevo nombre del segmento (VIP/PREMIUN/ESTANDAR): ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << " Ingrese el nuevo precio del segmento: ";
            cin >> nuevoPrecio;

            // Actualizar valores
            segmento->setNombre(nuevoNombre);
            segmento->setPrecio(nuevoPrecio);

            // Editar zonas si el usuario lo desea
            char respuesta;
            cout << "¿Desea modificar las zonas de este segmento? (s/n): ";
            cin >> respuesta;
          
            if (respuesta == 's' || respuesta == 'S') {
                cout << "¿Desea eliminar una zona? (1) Eliminar (2) No: ";
                cin >> opcionZona;
                if (opcionZona == 1) {
                    int numZona;
                    cout << "Ingrese el numero de zona a eliminar: ";
                    cin >> numZona;
                    if (segmento->eliminaZona(numZona)) {
                        cout << "Zona eliminada correctamente." << endl;
                    }
                    else {
                        cout << "Error al eliminar la zona." << endl;
                    }
                }
            }

            return true;
        }

        actual = actual->getSiguiente();
        contador++;
    }

    cout << "Segmento no encontrado en la posicion " << pos << endl;
    return false;
}

int ListaSegmentos::cantidadSegmentos()
{
	actual = primero;
	int contador = 0;
	while (actual != nullptr) {
		contador++;
		actual = actual->getSiguiente();
	}
	return contador;
}

bool ListaSegmentos::agregarSegmentoAlFinal(Segmento* segmento)
{
	NodoSegmento* nuevo = new NodoSegmento(segmento);
	actual = primero;

	if (primero == nullptr)
	{
		primero = nuevo;
        return true;
	}
	else
	{
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
		return true;
	}
}

Segmento* ListaSegmentos::buscarSegmentoPorPosicion(int pos)
{
	actual = primero;
	int contador = 0;

	while (actual != nullptr) {
		if (contador == pos) {
			return actual->getSegmento();
		}
		actual = actual->getSiguiente();
		contador++;
	}
	return nullptr;  //no existe en esa posicion
}

bool ListaSegmentos::eliminarSegmento(int num)
{
    actual = primero;
    NodoSegmento* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getSegmento()->getContador() == num) {
            if (anterior == nullptr) {
                primero = actual->getSiguiente();
            }
            else {
                anterior->setSiguiente(actual->getSiguiente());
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    cout << "No se encontro: " << num << endl;
    return false;
}


void ListaSegmentos::entradasVendidas()
{
    actual = primero;
    int totalVendidas = 0;
    
    while (actual != nullptr) {
        actual->getSegmento()->entradasVendidas();
        totalVendidas += actual->getSegmento()->entradasVendidas();
        actual = actual->getSiguiente();
    }

    cout << "Total de entradas vendidas en todos los segmentos: " << totalVendidas << endl;
}

int ListaSegmentos::espaciosDisponibles()
{
    actual = primero;
    int totalDisponibles = 0;
    while (actual != nullptr) {
        totalDisponibles += actual->getSegmento()->getCantZonas();
		actual = actual->getSiguiente();
    }
    return totalDisponibles;
}

string ListaSegmentos::toString()
{
	stringstream s;
	actual = primero;

	while (actual != nullptr)
	{
		s << actual->getSegmento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
