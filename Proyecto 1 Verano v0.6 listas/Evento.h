#pragma once
#include <string>
#include "ListaSegmentos.h"
#include "ListaCodigosDescuento.h"

//aqui hay que aplicar la mayoria de cambios
class Evento {
private:
    int tamMaximo;
    int canSegmentos;
    ListaSegmentos* segmentos; 
    ListaCodigosDescuento* codigos; //lista de codigos de descuento
    int canDescuento;
public:
    Evento();
    Evento(int);
    virtual ~Evento();

    int getCanSegmentos() const;
    Segmento* obtenerSegmento(int);
    string imprimirSegmento();
    bool agregarSegmento(Segmento*);
    bool agregaCodigoDescuento(string, double);

    

    // Métodos operativos
    //configurar evento
    void eliminaTodo();
    void establecerPrecioSegmento(Segmento*, double precio);
    string mostrarCodigosDescuento()const;

    //metodos ver detalles
    int espacioDisponibles();
    string mostrarTotalDisponibles();
    string mostrarSegmentoEspecifico(int);

    //Metodos con clientes
    bool comprarEntrada(ListaClientes*,string ced, int seg, int fila, int columna);
    void aplicarDescuento(Cliente* cliente, float porcentaje);


};
