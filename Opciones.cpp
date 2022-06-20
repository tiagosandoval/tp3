//
// Created by liuvaneshka on 20/06/22.
//

#include "Opciones.h"

Opciones::Opciones(Hash tabla, Lista<Lectura*>* lista_lecturas){
    this->tabla = tabla;
    this->lista_lecturas = lista_lecturas;
}

Opciones::~Opciones(){}

void Opciones::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    lista_lecturas->alta(nueva_lectura);

    cout << "\nLectura creada: " << endl;
    nueva_lectura->mostrar_lectura();
}

Lectura* Opciones::crear_lectura(){
    Lectura* nueva_lectura = nullptr;

    string titulo = printer.pedir_titulo();
    int anio = printer.pedir_anio();
    int minutos = printer.pedir_minutos();
    Escritor* escritor_lectura = crear_escritor();
    int tipo = printer.pedir_tipo();

    switch(tipo) {

        case 1:{
            int versos = printer.pedir_versos();
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro = printer.pedir_libro();
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            generos genero = printer.pedir_genero();

            if(genero == HISTORICA){
                string tema = printer.pedir_tema();
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero);
            break;
        }

        default:
            cout << ROJO << "\nDatos inválidos, intente nuevamente.\n" << endl;
    }
    return nueva_lectura;
}


void Opciones::agregar_escritor(){
    Escritor* nuevo_escritor = crear_escritor();
    cout << "\nEscritor creado:" << endl;
    nuevo_escritor->mostrar_escritor();
}

Escritor* Opciones::crear_escritor() {
    Escritor *nuevo_escritor;
    Escritor *escritor_hallado;
    string nuevo_isni;

    string nombre = printer.pedir_nombre();
    escritor_hallado = tabla.encontrar_por_nombre(nombre);

    if (escritor_hallado != nullptr) {
        nuevo_escritor = escritor_hallado;
        cout << "Escritor existente\n" << endl;
    }
    else{
        string nacionalidad = printer.pedir_nacionalidad();
        int nacimiento = printer.pedir_nacimiento();
        int fallecimiento = printer.pedir_fallecimiento();

        nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
        nuevo_isni = generar_isni();
        tabla.agregar_item(nuevo_isni, nuevo_escritor);
    }

    return nuevo_escritor;
}

string Opciones::generar_isni(){
    string isni = "(";
    isni = isni + printer.pedir_isni();
    while(tabla.encontrar_dato(isni) != nullptr){
        isni = printer.pedir_isni();
    }
    isni = isni + ")";

    return isni;
}

void Opciones::listar_lecturas(){
    int contador = 1;
    lista_lecturas->inicializar();

    while(lista_lecturas->hay_actual()){
        cout << "Lectura numero: "<< contador << endl;
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        lectura_actual->mostrar_lectura();

        lista_lecturas->siguiente();
        contador++;
    }
}