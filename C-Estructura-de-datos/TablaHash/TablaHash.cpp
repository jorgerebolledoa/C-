#include "TablaHash.h"

// Constructor
TablaHash::TablaHash(int capacidad) {
    this->capacidad = capacidad;
    tabla.resize(capacidad); // Inicializar el tamaño del vector
}

// Función hash para mapear una clave a un índice en la tabla
int TablaHash::hash(int clave) {
    return clave % capacidad;
}

// Método público para insertar un elemento en la tabla hash
void TablaHash::insertar(int clave) {
    int indice = hash(clave);
    tabla[indice].push_back(clave);
}

// Método público para buscar un elemento en la tabla hash
bool TablaHash::buscar(int clave) {
    int indice = hash(clave);
    for (int valor : tabla[indice]) {
        if (valor == clave) {
            return true;
        }
    }
    return false;
}

// Método público para eliminar un elemento de la tabla hash
void TablaHash::eliminar(int clave) {
    int indice = hash(clave);
    tabla[indice].remove(clave);
}

// Método público para imprimir la tabla hash
void TablaHash::imprimir() {
    for (int i = 0; i < capacidad; ++i) {
        std::cout << "índice " << i << ": ";
        for (int valor : tabla[i]) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }
}
