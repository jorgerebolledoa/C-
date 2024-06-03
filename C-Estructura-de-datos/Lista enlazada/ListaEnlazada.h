#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>

// Definición de la estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor
    ListaEnlazada();

    // Destructor
    ~ListaEnlazada();

    // Métodos de la lista
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void eliminarInicio();
    void eliminarFinal();
    void imprimir();
};

#endif /* LISTA_ENLAZADA_H */
