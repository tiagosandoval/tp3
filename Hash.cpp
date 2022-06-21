//
// Created by liuvaneshka on 17/06/22.
//

#include <iostream>
#include "Hash.h"

Hash::Hash(){
    for(int i = 0; i < n; i++){
        tabla_hash[i] = new Item;
        //tabla_hash[i]->lista_escritor.inicializar() ;
        // Lista <Escritor*> *lista_escritores = new Lista<Escritor*> // esto en el parser procesar escritor
        tabla_hash[i]->llave = "";
        tabla_hash[i]->escritor = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}

int Hash::valor_Hash(string llave){
    int hash = 0, i = 1;

    while(llave[i] != ')') {
        hash = hash + (int) llave[i];
        i++;
    }

    return(hash % n); // devuelve el indice
}

void Hash::agregar_item(string isni , Escritor* escritor) {

    int indice = valor_Hash(isni);

    if(tabla_hash[indice]->escritor == nullptr){
        tabla_hash[indice]->llave = isni;
        tabla_hash[indice]->escritor = escritor;
    }
    else{
        Item* puntero = tabla_hash[indice]; // apnta al primer
        Item* nuevo= new Item; // crea una nueva lista de elementos
        nuevo->llave = isni;
        nuevo->escritor = escritor;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

int Hash::cantidad_item_en_indice(int indice) {
    int contador = 0;

    if(tabla_hash[indice]->llave == ""){
        return contador;
    }
    else{
        contador++;
        Item* puntero = tabla_hash[indice];
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

        cantidad_elementos = cantidad_item_en_indice(i);

        std::cout << "Indice = " << i << std::endl;

         if(cantidad_elementos > 0){
             std::cout << "******************" << std::endl;
             imprimir_item(i);
             std::cout <<"  cantidad de listas = " << cantidad_elementos << std::endl;
             std::cout << "******************" << std::endl;

         }
    }
}

void Hash::imprimir_item(int indice) {
    Item* puntero = tabla_hash[indice];
    if(puntero->escritor != nullptr){
        std::cout << indice << "  contiene los siguientes " << std::endl;

        while(puntero != nullptr){
            std::cout << puntero->escritor->obtener_nombre() << std::endl;
            std::cout << puntero->llave << std::endl;

            puntero = puntero->siguiente;
        }
    }
}

Escritor* Hash::encontrar_dato(string llave) {
    int indice = valor_Hash(llave);
    bool encontrado = false;
    Escritor* escritor;

    Item* puntero = tabla_hash[indice];
    while(puntero != nullptr){
        if(puntero->llave == llave){
            encontrado = true;
            escritor = puntero->escritor;
        }
        puntero = puntero->siguiente;
    }
    if(!encontrado)
        escritor = nullptr;

    std::cout << escritor << std::endl;
    return escritor;
}


Escritor* Hash::buscar_item(int indice, string nombre) {
    Item* puntero = tabla_hash[indice];
    Escritor* escritor = nullptr;

    if(puntero->escritor != nullptr){

        while((puntero != nullptr)){
            if(puntero->escritor->obtener_nombre() == nombre){
                std::cout << "ENCONTRADO ==========="<<puntero->escritor->obtener_nombre() << endl;
                escritor = puntero->escritor;
                std::cout << escritor << std::endl;
                return escritor;
            }
            puntero = puntero->siguiente;
        }
    }
    return escritor;
}

Escritor* Hash::encontrar_por_nombre(string nombre) {
    Escritor* escritor;
    Escritor* encontrado = nullptr;
    int cantidad_elementos;
    for(int i = 0; i < n; i++){
        cantidad_elementos = cantidad_item_en_indice(i);
        if(cantidad_elementos > 0){
            escritor = buscar_item(i, nombre);
            if(escritor != nullptr){
                encontrado = escritor;
                std::cout << escritor << std::endl;
            }
        }
    }
    std::cout << "hey " << encontrado << std::endl;
    return encontrado;
}
/*
void Hash::eliminar_lista(string llave) {

    int indice = Hash(llave);

    lista* puntero_eliminar;
    lista* puntero;
    lista* aux;



}
*/
