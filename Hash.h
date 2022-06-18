//
// Created by liuvaneshka on 17/06/22.
//

#ifndef HASH_H
#define HASH_H
#include "Lista.h"
#include "Escritor.h"

class Hash {

private:

    static const int n = 25; // lambda = 0.8, lambda = clave/n un numero primo al menos 1.3 veces mas de las claves

    string llave;

    struct item{
        Escritor* escritor;
        struct item* siguiente;
    };

    item* tabla_hash[n];// se crea la tabla, con su cantidad de buckets

public:

    Hash();
    int valor_Hash(string llave /*isni*/);

    void agregar_item(string isni, Escritor* escritor);

    //pre: indice debe ser un entero
    //post: retorna la cantidad de items dentro de un bucket o indice
    int cantidad_items_en_indice(int indice);
    //post: imprime los primeros items de cada bucket, y cuandos items contiene c/u
    void imprimir_tabla();
};


#endif