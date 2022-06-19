//
// Created by liuvaneshka on 17/06/22.
//

#ifndef HASH_H
#define HASH_H

template <typename Dato>
class Hash {

private:

    static const int n = 25; // lambda = 0.8, lambda = clave/n un numero primo al menos 1.3 veces mas de las claves

    struct Item{
        Dato llave;
        Dato* dato;
        struct Item* siguiente;
    };

    Item* tabla_hash[n];// se crea la tabla, con su cantidad de buckets

public:

    //post: construye la tabal hash
    Hash();

    //pre: recibe una cadena
    //post: genera una clave
    int valor_Hash(string llave);

    //pre: recibe una cadena para generar la clave, y el dato a introducir
    //post: agrega un item a la lista
    void agregar_item(string isni, Dato* dato);

    //pre: indice debe ser un entero
    //post: retorna la cantidad de items dentro de un bucket o indice
    int cantidad_items_en_indice(int indice);

    //post: imprime los primeros items de cada bucket, y cuandos items contiene c/u
    void imprimir_tabla();

    //pre: recibe un indice entero
    //post: imprime los valores dentro de cada indice
    void imprimir_items(int indice);

    //pre: recibe una cadena representando la llave
    //post: busca el dato asociado a la llave
    Dato* encontrar_dato(string llave);

    //pre: recibe una cadena representando la llave
    //post: elimina el elemento
    void eliminar_item(string llave);
};

template <typename Dato>

Hash<Dato>::Hash(){
    for(int i = 0; i < n; i++){
        tabla_hash[i] = new lista;
        //tabla_hash[i]->lista_escritor.inicializar() ;
        // Lista <Escritor*> *lista_escritores = new Lista<Escritor*> // esto en el parser procesar escritor
        tabla_hash[i]->llave = "";
        tabla_hash[i]->dato = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}

template <typename Dato>

int Hash<Dato>::valor_Hash(string llave)
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

template <typename Dato>
void Hash<Dato>::agregar_item(string llave , Dato* dato) {

    int indice = valor_Hash(llave);

    if(tabla_hash[indice]->dato == nullptr){
        tabla_hash[indice]->llave = llave;
        tabla_hash[indice]->dato = dato;
    }
    else{
        Item* puntero = tabla_hash[indice]; // apnta al primer
        Item* nuevo= new Item; // crea una nueva lista de elementos
        nuevo->llave = llave;
        nuevo->dato = dato;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

template <typename Dato>
int Hash<Dato>::cantidad_items_en_indice(int indice) {
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

template <typename Dato>
void Hash<Dato>::imprimir_tabla() {
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

template <typename Dato>
void Hash<Dato>::imprimir_items(int indice) {
    Item* puntero = tabla_hash[indice];
    if(puntero->dato != nullptr){
        std::cout << indice << "  contiene los siguientes " << std::endl;

        while(puntero != nullptr){
            std::cout << puntero->dato->obtener_nombre() << std::endl;
            std::cout << puntero->llave << std::endl;

            puntero = puntero->siguiente;
        }
    }
}

template <typename Dato>
Dato* Hash<Dato>::encontrar_dato(string llave) {
    int indice = valor_Hash(llave);
    bool encontrado = false;
    Dato* dato;

    Item* puntero = tabla_hash[indice];
    while(puntero != nullptr){
        if(puntero->llave == llave){
            encontrado = true;
            dato = puntero->dato;
        }
        puntero = puntero->siguiente;
    }

    if(!encontrado)
        dato = nullptr;

    return dato;
}

template <typename Dato>
void Hash<Dato>::eliminar_item(string llave) {
/*
    int indice = Hash(llave);

    lista* puntero_eliminar;
    lista* puntero;
    lista* aux;

*/

}


#endif