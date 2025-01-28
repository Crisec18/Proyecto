#include "Evento.h"
#include "Segmento.h"
#include "Zona.h"   
#include <Windows.h>
#include "ListaClientes.h"
#include "ListaCodigosDescuento.h"
using namespace std;

int main() {
    string nomEve;
    int op = 0;
    int seg, fila, columna = 0;
    string nomCliente, cedCliente;
    int anio;
    string nomSeg = "";
    double precio, descuento = 0;
    string codigoDescuento = "";

    cout << " - Ingrese el nombre del evento: ";
    getline(cin, nomEve);

    Evento* even1 = new Evento();
    Segmento* seg1 = new Segmento();
    Zona* nuevaZon = new Zona();
    Cliente* clie1 = new Cliente();
    ListaClientes* listaC = new ListaClientes();
    ListaCodigosDescuento* listaCod = new ListaCodigosDescuento();

    do {
        system("cls");
        cout << " +------------------------------------------------------------+" << endl;
        cout << " +--------------------+ " << nomEve << " +--------------------+" << endl;
        cout << "[1] - Configurar evento: " << endl;
        cout << "[2] - Comprar entradas: " << endl;
        cout << "[3] - Ver espacios libres :" << endl;
        cout << "[4] - Codigos de descuento: " << endl;
        cout << "[5] - Acerca de..." << endl;
        cout << "[6] - Crear archivo de texto con los datos del evento" << endl;
        cout << "[7] - Salir..." << endl;
        cout << "[*] - Digite la opcion..." << endl;
        cin >> op;

        switch (op) {
        case 1: {
            /* para establecer los espacios de los 3 segmentos */
            do {
                system("cls");
                cout << "+-----------[ CONFIGURAR EVENTO ]-----------+" << endl;
                cout << " (1) - Ingresa segmento(s): " << endl;
                cout << " (2) - Ingresa precio de segmento(s):" << endl;
                cout << " (3) - Volver..." << endl;
                cin >> op;

                switch (op) {
                case 1: {
                    system("cls");
                    op = 0;
                    cout << " - Ingrese la cantidad de segmento(s) deseados: ";
                    cin >> seg;

                    // Creacion de los segmentos
                    even1->setTamMaximo(seg);
                    for (int i = 0; i < seg; i++) {
                        cout << " Ingrese la nomenclatura del segmento (VIP/ESTANDAR/PREMIUM): ";
                        cin >> nomSeg;
                        cout << "\n";

                        // Crear un nuevo segmento
                        seg1 = new Segmento(seg, nomSeg);

                        cout << " - Ingrese el tamanio de la zona para el segmento " << nomSeg << " [Filas/Columnas]: " << endl;
                        cout << " Filas: ";
                        cin >> fila;
                        cout << " Columnas: ";
                        cin >> columna;
                        cout << "\n";

                        if (fila <= 0 || columna <= 0) {
                            cout << "Valores invalidos, intente nuevamente...\n";
                            system("pause");
                            continue;
                        }

                        // Crear la zona
                        nuevaZon = new Zona(fila, columna);
                        // Asignar la zona al segmento
                        seg1->agregaZona(nuevaZon);
                        // Agregar el segmento al evento
                        even1->agregarSegmento(seg1);

                        cout << " ~ Segmento " << nomSeg << " agregado con tamanio de zona " << fila << "x" << columna << "!" << endl;
                        system("pause");
                    }
                    break;
                }
                case 2: {
                    // Aquí se asigna el precio a un segmento específico
                    cout << " - Ingrese el numero del segmento para establecer el precio: ";
                    cin >> seg;

                    // validar seg
                    if (seg <= 0 || seg > even1->getCanSegmentos()) {
                        cout << "Numero de segmento invalido. Intente nuevamente.\n";
                        system("pause");
                        break;
                    }

                    // solicitar el precio del segmento
                    cout << " - Ingrese el precio para el segmento " << seg << ": ";
                    cin >> precio;

                    // guardamos la op
                    Segmento* seleSeg = even1->obtenerSegmento(seg - 1);

                    if (seleSeg != nullptr) {
                        // asignamos al segmento
                        even1->establecerPrecioSegmento(seleSeg, precio);
                        cout << "Precio establecido!\n";
                    }
                    else {
                        cout << "No se pudo encontrar el segmento...\n";
                    }
                    system("pause");
                    break;
                }
                }
            } while (op != 3);
            break;
        }
        case 2: {
            do {
                system("cls");
                cout << "+-------------[ COMPRAR ENTRADAS ]-------------+" << endl;
                cout << " (1) - Registrar cliente" << endl;
                cout << " (2) - Comprar entrada" << endl;
                cout << " (3) - Volver..." << endl;
                cout << "[*] - Digite la opcion: ";
                cin >> op;

                switch (op) {
                case 1: {
                    cin.ignore();
                    cout << "\tIngrese su cedula: "; getline(cin, cedCliente);

                    // busca si ya fue introducido
                    listaC->buscarClientePorCedula(cedCliente);

                    if (listaC) {  // como es booleano, solo recibe true o false desde el metodo
                        cout << "Cliente ya registrado..." << endl;
                    }
                    else {
                        cout << "Cliente no registrado..." << endl;
                        cout << "\tIngrese su nombre: "; getline(cin, nomCliente);
                        cout << "\tIngrese su anio de nacimiento: "; cin >> anio;

                        // creamos y agregamos el cliente
                        clie1 = new Cliente(nomCliente, cedCliente, anio);
                        listaC->agregarClienteAlFinal(clie1);
                        cout << "Cliente registrado exitosamente..." << endl;
                    }
                    system("pause");
                    break;
                }
                case 2: {
                    cin.ignore();
                    cout << "Ingrese su cedula: "; getline(cin, cedCliente);
                    // buscamos nuevamente
                   listaC->buscarClientePorCedula(cedCliente);

                    if (listaC) {
                        cout << "Cliente no registrado. Por favor, registrese primero." << endl;
                        system("pause");
                        break;
                    }

                    cout << " - Ingrese el segmento: "; cin >> seg;
                    seg1 = even1->obtenerSegmento(seg - 1);

                    if (seg1 == nullptr) {
                        cout << "Segmento no encontrado" << endl;
                        system("pause");
                        break;
                    }

                    cout << endl;
                    cout << "\t Asientos libres: " << endl;
                    cout << even1->mostrarSegmentoEspecifico(seg - 1) << endl; // Imprimir la información del segmento

                    cout << "Ingrese la fila y columna del asiento que desea comprar: " << endl;
                    cout << "Fila: ";
                    cin >> fila;
                    cout << "Columna: ";
                    cin >> columna;
                    cout << " Ingresado!..." << endl;

                    //cambiar
                    //if (even1->comprarEntrada(contCli, cedCliente, seg - 1, fila, columna)) {
                    //    cout << "Entrada comprada exitosamente..." << endl;
                    //}
                    //else {
                    //    cout << "No se pudo comprar la entrada..." << endl;
                    //}
                    system("pause");
                    break;
                }
                case 3: {
                    cout << "Volviendo al menu principal..." << endl;
                    break;
                }
                default: {
                    cout << "Opcion invalida, intente nuevamente..." << endl;
                    break;
                }
                }
            } while (op != 3);
            system("pause");
            break;
        }
        case 3: {
            do {
                system("cls");
                cout << "+-----------[ ESPACIOS DISPONIBLES ]-----------+" << endl;
                cout << " (1) - Ver segmento especifico: " << endl;
                cout << " (2) - Ver todos: " << endl;
                cout << " (3) - Volver..." << endl;
                cout << "[*] - Digite opcion: ";
                cin >> op;

                switch (op) {
                case 1: {
                    cout << " Ingrese el segmento: " << endl;
                    cin >> seg;

                    if (seg <= 0 || seg > even1->getCanSegmentos()) {
                        cout << "Numero de segmento invalido. Intente nuevamente.\n";
                        system("pause");
                        break;
                    }
                    else {
                        cout << even1->mostrarSegmentoEspecifico(seg - 1);
                    }
                    break;
                }
                case 2: {
                    //muestra numericamente los asientos disponibles
                    cout << even1->mostrarTotalDisponibles();
                    break;
                }
                default:
                    cout << "volviendo..." << endl;
                    break;
                }
                system("pause");
            } while (op != 3);
            break;
        }
        case 4: {
            do {
                system("cls");
                cout << "+------------[ CODIGOS DE DESCUENTO ]------------+" << endl;
                cout << " (1) - Ingresar codigo de descuento: " << endl;
                cout << " (2) - Ver codigos: " << endl;
                cout << " (3) - Volver..." << endl;
                cout << "[*] - Digite opcion: ";
                cin >> op;

                switch (op) {
                case 1: {
                    cout << "Ingrese el codigo alfa-numerico de 4 digitos: ";
                    cin >> codigoDescuento;

                    cout << "Ingrese el porcentaje de descuento: "; cin >> descuento;

                    if (even1->agregaCodigoDescuento(codigoDescuento, descuento)) {
                        cout << "Codigo ingresado correctamente..." << endl;
                    }
                    else {
                        cout << "Codigo ya ingresado anteriormente..." << endl;
                    }
                    system("pause");
                    break;
                }
                case 2: {
                    cout << even1->mostrarCodigosDescuento();
                    system("pause");
                    break;
                }
                case 3: {
                    cout << "volviendo..." << endl;
                    break;
                }
                default:
                    cout << "Opcion invalida..." << endl;
                    break;
                }
            } while (op != 3);
            break;
        }
        case 5: {
            cout << "Programa creado por el mono Cristian Elizondo Cascante ";
            system("pause");
            break;
        }
        case 6: {
            //aqui vamos hacer el archivo de txt
        }
        case 7: {
            cout << "Gracias!..";
            system("pause");
            break;
        }
        default: {
            cout << "Opcion invalida intente nuevamente..." << endl;
            break;
        }
        }
    } while (op != 7);

    delete even1;
    delete seg1;

    return 0;
}
