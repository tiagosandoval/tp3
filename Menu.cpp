#include "Menu.h"
#include "Parser.h"

Menu::Menu(){

    Lista <Lectura*> *lista_lecturas = new Lista<Lectura*>;

    Parser parser;
    Hash tabla;
    this-> tabla = parser.procesar_escritor(ARCHIVO_ESCRITORES, tabla);
    this->lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, tabla);

    srand( (unsigned int) time(0));
}

Menu::~Menu(){

    delete lista_lecturas;
}

void Menu::mostrar_menu(){
    for(int i = 0; i < CANT_OPCIONES; i++)
        cout << AMARILLO << i+1 << ". " << OPCIONES[i]  << endl;
}

void Menu::elegir_opcion(){
    string opcion;
    this->opcion = printer.pedir_opcion();
}

bool Menu::selector_menu(){
    Opciones opciones(tabla, lista_lecturas);
    bool estado;
    switch (this->opcion){

        case 1:
            cout << VERDE << "Caso 1: Agregar una nueva lectura"<< endl;
            opciones.agregar_lectura();
            estado = true;
            break;

        case 2:
            cout << VERDE << "Caso 2: Quitar lectura" << endl;
            estado = true;
            break;

        case 3:
            cout << VERDE << "Caso 3: Agregar un escritor" << endl;
            estado = true;
            break;

        case 4:
            cout << VERDE << "Caso 4: Actualizar fallecimiento autor" << endl;
            estado = true;
            break;

        case 5:
            cout << VERDE << "Caso 5: Listar los escritores" << endl;
            tabla.imprimir_tabla();
            estado = true;
            break;

        case 6:
            cout << VERDE << "Caso 6: Sortear una lectura" << endl;
            estado = true;
            break;

        case 7:
            cout << VERDE << "Caso 7: Listar lecturas" << endl;
            opciones.listar_lecturas();
            estado = true;
            break;

        case 8:
            cout << VERDE << "Caso 8: Listar lecturas por anio" << endl;
            estado = true;
            break;

        case 9:
            cout << VERDE << "Caso 9: Listar lecturas por escritor" << endl;
            estado = true;
            break;

        case 10:
            cout << VERDE << "Caso 10: Listar Novelas por genero" << endl;
            estado = true;
            break;

        case 11:
            cout << VERDE << "Caso 11: Listar proximas lecturas" << endl;
            estado = true;
            break;

        case 12:
            cout << "\n\t\t\tCordial despedida\n" << endl;
            estado = false;
            break;

        default:
            cout << "\nError elige otra opcion valida\n" << endl;
            estado = true;

    }
    return estado;
}
