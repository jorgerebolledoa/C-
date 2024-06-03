#include "Pila.h"

// Constructor
Pila::Pila() {
    capacidad = TAMANIO_PILA;
    elementos = new int[capacidad];
    tope = -1; // La pila está vacía al principio
}

// Destructor
Pila::~Pila() {
    delete[] elementos;
}

// Empujar un elemento a la pila
void Pila::push(int elemento) {
    if (tope == capacidad - 1) {
        std::cerr << "Error: la pila está llena" << std::endl;
        return;
    }
    elementos[++tope] = elemento;
}

// Sacar un elemento de la pila
int Pila::pop() {
    if (isEmpty()) {
        std::cerr << "Error: la pila está vacía" << std::endl;
        return -1; // Valor sentinela para indicar un error
    }
    return elementos[tope--];
}

// Obtener el elemento superior de la pila sin sacarlo
int Pila::peek() {
    if (isEmpty()) {
        std::cerr << "Error: la pila está vacía" << std::endl;
        return -1; // Valor sentinela para indicar un error
    }
    return elementos[tope];
}

// Verificar si la pila está vacía
bool Pila::isEmpty() {
    return tope == -1;
}

