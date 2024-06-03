#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <vector>
#include <list>

class TablaHash {
private:
    int capacidad;                   // Capacidad de la tabla hash
    std::vector<std::list<int>> tabla; // Vector de listas para el almacenamiento de los elementos

    // Función hash para mapear una clave a un índice en la tabla
    int hash(int clave);

public:
    // Constructor
    TablaHash(int capacidad);

    // Métodos públicos
    void insertar(int clave);
    bool buscar(int clave);
    void eliminar(int clave);
    void imprimir();
};

#endif /* TABLA_HASH_H */

