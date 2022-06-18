//
// Created by liuvaneshka on 17/06/22.
//

#include <iostream>
#include "Hash.h"

Hash::Hash(){
    for(int i = 0; i < n; i++){
        tabla_hash[i] = new lista;
        //tabla_hash[i]->lista_escritor.inicializar() ;
        tabla_hash[i]->llave = "";
        tabla_hash[i]->escritor = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}

int Hash::valor_Hash(string llave)
{
    int hash = 0;
    int tamanio = (int)(llave).length();

    for(int i = 1; i < tamanio; i++){
        if((llave[i] != ')')){
            hash = hash + (int)llave[i];
        }
    }

    return(hash % n); // devuelve el indice
}

void Hash::agregar_lista(string isni , Escritor* escritor) {

    int indice = valor_Hash(isni);

    if(tabla_hash[indice]->escritor == nullptr){
        tabla_hash[indice]->llave = isni;
        tabla_hash[indice]->escritor = escritor;
    }
    else{
        lista* puntero = tabla_hash[indice]; // apnta al primer
        lista* nuevo= new lista; // crea una nueva lista de elementos
        nuevo->llave = isni;
        nuevo->escritor = escritor;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

int Hash::cantidad_listas_en_indice(int indice) {
    int contador = 0;

    if(tabla_hash[indice]->llave == ""){
        return contador;
    }
    else{
        contador++;
        lista* puntero = tabla_hash[indice];
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

        cantidad_elementos = cantidad_listas_en_indice(i);

        std::cout << "Indice = " << i << std::endl;

         if(cantidad_elementos > 0){
             std::cout << "******************" << std::endl;
             imprimir_lista(i);
             std::cout <<"  cantidad de listas = " << cantidad_elementos << std::endl;
             std::cout << "******************" << std::endl;

         }
    }
}

void Hash::imprimir_lista(int indice) {
    lista* puntero = tabla_hash[indice];
    if(puntero->escritor != nullptr){
        std::cout << indice << "  contiene los siguientes " << std::endl;

        while(puntero != nullptr){
            std::cout << puntero->escritor->obtener_nombre() << std::endl;
            std::cout << puntero->llave << std::endl;

            puntero = puntero->siguiente;
        }
    }
}

Escritor* Hash::encontrar_objeto(string llave) {
    int indice = valor_Hash(llave);
    bool encontrado = false;
    Escritor* escritor;

    lista* puntero = tabla_hash[indice];
    while(puntero != nullptr){
        if(puntero->llave == llave){
            encontrado = true;
            escritor = puntero->escritor;
        }
        puntero = puntero->siguiente;
    }
    /*
    if(encontrado){
        std::cout << escritor->obtener_nombre() << std::endl;
    }
     */
    if(!encontrado)
        escritor = nullptr;

    return escritor;
}

void Hash::eliminar_lista(string llave) {
/*
    int indice = Hash(llave);

    lista* puntero_eliminar;
    lista* puntero;
    lista* aux;

*/

}