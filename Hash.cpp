//
// Created by liuvaneshka on 17/06/22.
//

#include <iostream>
#include "Hash.h"

Hash::Hash(){
    for(int i = 0; i < n; i++){
        tabla_hash[i] = new item;
        //tabla_hash[i]->lista_escritor.inicializar() ;
        tabla_hash[i]->escritor = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}

int Hash::valor_Hash(string llave /*isni*/)
{
    int hash = 0;
    for(int i = 1; i < (int)(llave).length(); i++){
        if((llave[i] != ')'))
            hash = hash + (int)llave[i];
    }
    return(hash % n); // devuelve el indice
}

void Hash::agregar_item(string isni , Escritor* escritor) {

    int indice = valor_Hash(isni);

    if(tabla_hash[indice]->escritor == nullptr){
        tabla_hash[indice]->escritor = escritor;
    }
    else{
        item* puntero = tabla_hash[indice]; // apnta al primer
        item* nuevo= new item; // crea una nueva lista de elementos
        nuevo->escritor = escritor;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

int Hash::cantidad_items_en_indice(int indice) {
    int contador = 0;

    if(tabla_hash[indice]->escritor == nullptr){
        return contador;
    }
    else{
        contador++;
        item* puntero = tabla_hash[indice];
        while(puntero->siguiente != nullptr){
            contador++;
            puntero = puntero->siguiente;
        }
    }
    return contador;
}

void Hash::imprimir_tabla() {
    int cantidad_elementos;
    for(int i = 0; i < n; i++){

        cantidad_elementos = cantidad_items_en_indice(i);

        std::cout << "Indice = " << i << std::endl;
        if(tabla_hash[i]->escritor != nullptr)
            std::cout << tabla_hash[i]->escritor->obtener_nombre()<< std::endl;
        std::cout << "cantidad de items = " << cantidad_elementos << std::endl;

    }
}