#ifndef PILA_H
#define PILA_H

#include <iostream>

// Tamaño predeterminado de la pila
#define TAMANIO_PILA 100

class Pila {
private:
    int* elementos; // Array para almacenar los elementos de la pila
    int capacidad;  // Capacidad máxima de la pila
    int tope;       // Índice del elemento superior de la pila

public:
    // Constructor
    Pila();

    // Destructor
    ~Pila();

    // Métodos de la pila
    void push(int elemento);  // Empujar un elemento a la pila
    int pop();                // Sacar un elemento de la pila
    int peek();               // Obtener el elemento superior de la pila sin sacarlo
    bool isEmpty();           // Verificar si la pila está vacía
};

#endif /* PILA_H */
