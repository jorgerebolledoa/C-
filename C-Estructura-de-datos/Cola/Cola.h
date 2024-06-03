#ifndef COLA_H
#define COLA_H

#include <iostream>

// Tamaño predeterminado de la cola
#define TAMANIO_COLA 100

class Cola {
private:
    int* elementos; // Array para almacenar los elementos de la cola
    int capacidad;  // Capacidad máxima de la cola
    int frente;     // Índice del elemento frontal de la cola
    int final;      // Índice del elemento final de la cola
    int cantidad;   // Cantidad actual de elementos en la cola

public:
    // Constructor
    Cola();

    // Destructor
    ~Cola();

    // Métodos de la cola
    void enqueue(int elemento);  // Encolar un elemento
    int dequeue();               // Desencolar un elemento
    int peek();                  // Obtener el elemento frontal de la cola sin desencolarlo
    bool isEmpty();              // Verificar si la cola está vacía
};

#endif /* COLA_H */
