#ifndef MENU_H
#define MENU_H
#include <iostream>
// Clases generales
#include "Escritor.h"
#include "Lectura.h"
#include "CONSTANTES.h"
// Subclases
#include "Novela.h"
#include "Novela_historica.h"
#include "Cuento.h"
#include "Poema.h"
// Para la opcion de sortear una lectura
#include <stdlib.h>
#include <time.h>
// Para la cola de lecturas
#include "Lista.h"
//Para pedir datos al usuario
#include "Printer.h"
//Hash
#include "Hash.h"
//Opciones
#include "Opciones.h"
//printer
#include "Printer.h"


using namespace std;

class Menu {

private:

    int opcion;
    Printer printer;
    Hash tabla;
    Lista<Lectura*>* lista_lecturas;

public:

    //PRE: -
    //POST: Construye un Menu.
    Menu();

    //PRE: -
    //POST: Destruye un Menu.
    ~Menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Impriem las opcines del Menu.
    void mostrar_menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Pide al usuario la opcion que desea ejecutar del Menu.
    void elegir_opcion();

    //PRE: Menu debe ser un objeto válido.
    //POST: Dependiendo de la opcion ingresada por el usuario, se ejecuta la acción correspondiente.
    bool selector_menu();
};

#endif
