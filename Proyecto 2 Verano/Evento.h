#pragma once
#include <string>
#include "ListaSegmentos.h"
#include "ListaCodigosDescuento.h"

//aqui hay que aplicar la mayoria de cambios
class Evento {
private:
    int canSegmentos;
    ListaSegmentos* segmentos; 
    ListaCodigosDescuento* codigos; //lista de codigos de descuento
    int canDescuento;
public:
    Evento();
    virtual ~Evento();

    int getCanSegmentos() const;
    Segmento* obtenerSegmento(int);
 /*   string imprimirSegmento();*/
    bool agregarSegmento(Segmento*);
 

    // Métodos operativos
    //configurar evento
    void eliminaTodo();
    //void establecerPrecioSegmento(int n, double precio);
    string mostrarCodigosDescuento()const;

    //metodos ver detalles
    int espacioDisponibles();
    string mostrarTotalDisponibles();
    string mostrarSegmentoEspecifico(int);
    Zona* obtenerZona(int, int);
    //falta meter todos los de las listas

    //Metodos con clientes
    bool comprarEntrada(ListaClientes*,string ced, int seg, int fila, int columna);

    //descuentos 
    //bool eliminarCodigoDescuento(string codigo);
    bool aplicarDescuento(Cliente*, double);


};
