#include <iostream>
#include "Parser.h"
#include "CONSTANTES.h"

using namespace std;

void Parser::procesar_escritor(string ruta, Hash tabla){

    string nombre, nacionalidad, lectura, isni;
    int nacimiento, fallecimiento;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){

        lectura = entrada.leer_linea();

        if(!lectura.empty()){

            isni = lectura;

            nombre = entrada.leer_linea();
            nacionalidad = entrada.leer_linea();
            lectura = entrada.leer_linea();

            if(!lectura.empty() && !entrada.final_archivo()) {

                nacimiento = atoi(lectura.c_str());
                lectura = entrada.leer_linea();

                if(entrada.final_archivo() && lectura.empty()){
                    fallecimiento = DESCONOCIDO;
                }

                else if (!lectura.empty()) {
                    fallecimiento = atoi(lectura.c_str());
                }

                else{
                    fallecimiento = DESCONOCIDO;
                }
            }

            else if (!lectura.empty() && entrada.final_archivo()){
                if(isdigit(lectura[0]))
                    nacimiento = atoi(lectura.c_str());
                else
                    nacimiento = DESCONOCIDO;
                fallecimiento = DESCONOCIDO;
            }

            else{
                nacimiento = DESCONOCIDO;
                fallecimiento = DESCONOCIDO;
            }
            Escritor* escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            tabla.agregar_item(isni, escritor);

        }

    }
    entrada.cerrar_archivo();
    std::cout << "hash " << std::endl;
    tabla.imprimir_tabla();
}

Lista <Lectura*>* Parser::procesar_lectura(string ruta, Lista<Lectura*>* lista_lecturas, Hash tabla){

    Escritor* escritor;
    string dato, titulo, tipo, libro, tema_linea;
    generos genero;
    int minutos, anio, versos;


    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        dato = entrada.leer_linea();

        if(!dato.empty()){
            tipo = dato;
            titulo = entrada.leer_linea();

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());

            dato = entrada.leer_linea();

            if(tipo == POEMA){
                versos = atoi(dato.c_str());

                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, tabla);

                Poema* poema = new Poema(titulo, escritor, anio, minutos, versos);
                almacenar_lectura(poema, lista_lecturas);
            }
            else if(tipo == NOVELA){
                genero = obtener_genero(dato);

                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();

                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato,tabla);

                    Novela_historica* historica = new Novela_historica(titulo, escritor, anio, minutos, tema_linea);
                    almacenar_lectura(historica, lista_lecturas);
                }
                else{
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, tabla);

                    Novela* novela = new Novela(titulo, escritor, anio, minutos, genero);
                    almacenar_lectura(novela, lista_lecturas);
                }

            }
            else if(tipo == CUENTO){
                libro = dato;

                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, tabla);


                Cuento* cuento = new Cuento(titulo, escritor, anio, minutos, libro);
                almacenar_lectura(cuento, lista_lecturas);
            }
        }
    }
    entrada.cerrar_archivo();
    return lista_lecturas;
}


generos Parser::obtener_genero(string genero) {
    generos numero_genero;

    if (genero == "DRAMA")
        numero_genero = DRAMA;
    else if (genero == "COMEDIA")
        numero_genero = COMEDIA;
    else if (genero == "FICCION")
        numero_genero = FICCION;
    else if (genero == "SUSPENSO")
        numero_genero = SUSPENSO;
    else if (genero == "TERROR")
        numero_genero = TERROR;
    else if (genero == "ROMANTICA")
        numero_genero = ROMANTICA;
    else if (genero == "HISTORICA")
        numero_genero = HISTORICA;

    return numero_genero;
}


void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> *lista_lecturas){
    lista_lecturas->alta(lectura);
}


bool Parser::verificar_escritor(string linea_escritor){
    return linea_escritor != "ANONIMO";
}
Escritor* Parser::obtener_escritor(string linea, Hash tabla){
    Escritor* escritor;

    if (verificar_escritor(linea)){
        escritor = tabla.encontrar_dato(linea);
        std::cout <<  "****************" << escritor->obtener_nombre() << std::endl;
    }
    else{
        escritor = nullptr;
        std::cout << escritor << std::endl;
    }
    return escritor;
}

