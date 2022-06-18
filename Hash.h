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

    struct lista{
        string llave;
        //Lista<Escritor*>* lista_escritor;
        Escritor* escritor;
        struct lista* siguiente;
    };

    lista* tabla_hash[n];// se crea la tabla, con su cantidad de buckets

public:

    //post: construye la tabal hash
    Hash();

    //pre: recibe una cadena
    //post: genera una clave
    int valor_Hash(string llave /*isni*/);

    //pre: recibe una cadena para generar la clave, y el objeto a introducir
    //post: agrega un item a la lista
    void agregar_lista(string isni, Escritor* escritor);

    //pre: indice debe ser un entero
    //post: retorna la cantidad de items dentro de un bucket o indice
    int cantidad_listas_en_indice(int indice);

    //post: imprime los primeros items de cada bucket, y cuandos items contiene c/u
    void imprimir_tabla();

    //pre: recibe un indice entero
    //post: imprime los valores dentro de cada indice
    void imprimir_lista(int indice);

    //pre: recibe una cadena representando la llave
    //post: busca el objeto asociado a la llave
    Escritor* encontrar_objeto(string llave);

    //pre: recibe una cadena representando la llave
    //post: elimina el elemento
    void eliminar_lista(string llave);
};


#endif