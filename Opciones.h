//
// Created by liuvaneshka on 20/06/22.
//

#ifndef OPCIONES_H
#define OPCIONES_H
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
#include "Cola.h"
//Para pedir datos al usuario
#include "Printer.h"
//Para las listas
#include "Lista.h"
#include "Hash.h"


class Opciones {

private:
    Hash tabla;
    Printer printer;
    Lista<Lectura*>* lista_lecturas;

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Pide al usuario los atributos necesarios y crea el objeto correspondiente (Poema, Cuento, Novela, Novela_historica)
    Lectura* crear_lectura();

public:
    //pre: recibe un objeto tipo hash y una lista de objetos -lecturas-
    //post: construye las opciones con el objeto y lista
    Opciones(Hash tabla, Lista<Lectura*>* lista_lecturas);

    //PRE: -
    //POST: Destruye las opciones.
    ~Opciones();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea y almacena en lista_lecturas la lectura con los atributos ingresados por el usuario.
    void agregar_lectura();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Crea y almacena en lista_escritores el escritor con los atributos ingresados por el usuario.
    void agregar_escritor();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Pide al usuario los atributos necesarios y crea al Escritor.
    Escritor* crear_escritor();

    //PRE: -
    //POST: Pide al usuario isni.
    string generar_isni();

    void listar_lecturas();

};


#endif
