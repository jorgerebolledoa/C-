#include "ArbolBinario.h"

// Constructor
ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

// Destructor
ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

// Método privado para insertar recursivamente un valor en el árbol
Nodo* ArbolBinario::insertarRecursivo(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        nodo = new Nodo;
        nodo->dato = valor;
        nodo->izquierda = nullptr;
        nodo->derecha = nullptr;
    } else if (valor < nodo->dato) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertarRecursivo(nodo->derecha, valor);
    }
    return nodo;
}

// Método público para insertar un valor en el árbol
void ArbolBinario::insertar(int valor) {
    raiz = insertarRecursivo(raiz, valor);
}

// Método privado para buscar recursivamente un valor en el árbol
bool ArbolBinario::buscarRecursivo(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return false;
    } else if (valor == nodo->dato) {
        return true;
    } else if (valor < nodo->dato) {
        return buscarRecursivo(nodo->izquierda, valor);
    } else {
        return buscarRecursivo(nodo->derecha, valor);
    }
}

// Método público para buscar un valor en el árbol
bool ArbolBinario::buscar(int valor) {
    return buscarRecursivo(raiz, valor);
}

// Método privado para imprimir recursivamente los elementos del árbol en orden
void ArbolBinario::imprimirInOrderRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirInOrderRecursivo(nodo->izquierda);
        std::cout << nodo->dato << " ";
        imprimirInOrderRecursivo(nodo->derecha);
    }
}

// Método público para imprimir los elementos del árbol en orden
void ArbolBinario::imprimirInOrder() {
    imprimirInOrderRecursivo(raiz);
    std::cout << std::endl;
}

// Método privado para destruir recursivamente el árbol
void ArbolBinario::destruirArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izquierda);
        destruirArbol(nodo->derecha);
        delete nodo;
    }
}
