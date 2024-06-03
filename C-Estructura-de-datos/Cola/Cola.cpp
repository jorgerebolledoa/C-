#include "Cola.h"

// Constructor
Cola::Cola() {
    capacidad = TAMANIO_COLA;
    elementos = new int[capacidad];
    frente = 0;
    final = -1;
    cantidad = 0;
}

// Destructor
Cola::~Cola() {
    delete[] elementos;
}

// Encolar un elemento
void Cola::enqueue(int elemento) {
    if (cantidad == capacidad) {
        std::cerr << "Error: la cola está llena" << std::endl;
        return;
    }
    final = (final + 1) % capacidad;
    elementos[final] = elemento;
    cantidad++;
}

// Desencolar un elemento
int Cola::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: la cola está vacía" << std::endl;
        return -1; // Valor sentinela para indicar un error
    }
    int elemento = elementos[frente];
    frente = (frente + 1) % capacidad;
    cantidad--;
    return elemento;
}

// Obtener el elemento frontal de la cola sin desencolarlo
int Cola::peek() {
    if (isEmpty()) {
        std::cerr << "Error: la cola está vacía" << std::endl;
        return -1; // Valor sentinela para indicar un error
    }
    return elementos[frente];
}

// Verificar si la cola está vacía
bool Cola::isEmpty() {
    return cantidad == 0;
}
