//
// Created by liuvaneshka on 17/06/22.
//

#include "Hash.h"

Hash::Hash(){
    int n = 25; // lambda = 0.8, lambda = clave/n un numero primo al menos 1.3 veces mas de las claves
}

int Hash::valor_Hash(std::string llave /*isni*/)
{
    int hash = 0;
    for(int i = 0; i < llave.length(); i++){
        if((llave[i] != '(') && (llave[i] != ')'))
            hash = hash + (int)llave[i];
    }
    return(hash % n); // devuelve el indice
}
