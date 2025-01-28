#include "Zona.h"

Zona::Zona() :
    segmento(0), fila(0), columna(0), disponible(0),asiento(nullptr), precio(0) {
}

Zona::Zona(int fila, int columna) 
    : fila(fila), columna(columna), segmento(0), disponible(0), precio(0)
{
    // Crear la matriz de asientos
    asiento = new ListaClientes * [fila];
    for (int i = 0; i < fila; i++) {
       asiento[i]= new ListaClientes[columna];
    }
}

Zona::~Zona() {
    for (int i = 0; i < fila; i++) {
    delete[] asiento[i];
    }
    delete[] asiento;
}

int Zona::getFila() {
    return fila;
}

int Zona::getColumna() {
    return columna;
}

//para ver el numero total de espacios
int Zona::getEspacios() {
    return fila * columna; 
}
//valor numerico
int Zona::getDisponibles() 
{
    disponible = 0;
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (asiento[i][j].getPrimero() == nullptr) {
           
                disponible++;
            }
        }
    }
    return disponible;
}

int Zona::getOcupados() {
    return (fila * columna) - getDisponibles();
}

double Zona::getPrecio()
{
    return precio;
}

void Zona::setPrecio(double prec)
{
    precio = prec;
}

Cliente* Zona::getCliente(int f, int c)
{
    if (f >= 0 && f < fila && c >= 0 && c < columna) {
        return asiento[f][c].getPrimero()->getCliente();
    }
    else {
        return nullptr; //fuera de rango
    }

}
bool Zona::asignarCliente(Cliente* cliente, int fil, int colum) 
{
    if (fil < 0 || fil >= fila || colum < 0 || colum >= columna) {
        return false; // Fuera de rango
    }
    if (asiento[fil][colum].getPrimero() != nullptr) {
        return false; // Asiento ya ocupado
    }
    asiento[fil][colum].agregarClienteAlFinal(cliente); // Asignar cliente al asiento
    return true;
}

bool Zona::compraAsiento(ListaClientes* listaClientes, string ced, int fil, int colum) {
    // Buscamos si ya fue introducido
    Cliente* cliente = listaClientes->buscarCliente(ced);

    if (cliente == nullptr) {
        cout << "Cliente no encontrado" << endl;
        return false;
    }
    else {
        return asignarCliente(cliente, fil, colum);
    }
}



void Zona::muestraLibres() 
{
	cout << "Asientos disponibles: " << endl;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			if (asiento[i][j].getPrimero() == nullptr) {
                cout << " - Asiento: [ " << i << "x" << j << " ]" << endl;
			}
		}
	}
}   

string Zona::toString() {
    stringstream s;
    s << " - Zona: " << fila << " filas x " << columna << " columnas\n";
    s << " - Espacios totales: " << getEspacios() << "\n";
    s << " - Disponibles: " << getDisponibles() << "\n";
    s << " - Ocupados: " << getOcupados() << "\n";
    // Mostrar la matriz de asientos

    for (int i = 0; i < fila; i++) {
        char letra = 'A' + i; //para enseñar la letra de la fila

        for (int j = 0; j < columna; j++) {
            if (asiento[i][j].getPrimero() == nullptr) {
                s << "[ " << letra << j + 1 << " ]";
            }
            else {
                s << "[ " << letra << j + 1 << " " << asiento[i][j].getPrimero()->getCliente()->getNombre() << " ]";
            }
        }
        s << "\n";
    }
    return s.str();
}