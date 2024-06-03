/* Clases, punteros, constructor y destructor(~) */

#include <iostream>  // Incluye la librería estándar para entrada y salida

using namespace std;  // Usamos el espacio de nombres estándar para evitar escribir "std::" repetidamente

// Definición de la clase Caja
class Caja
{
private:
    double largo;  // Variable miembro para almacenar el largo de la caja
    double ancho;  // Variable miembro para almacenar el ancho de la caja
    double alto;   // Variable miembro para almacenar el alto de la caja

public:
    static int cantidadCajas;  // Variable estática para contar la cantidad de instancias de Caja

    // Constructor que inicializa las dimensiones de la caja y aumenta el contador de cajas
    Caja(double l, double a, double h)
    {
        this->largo = l;  // Inicializa el largo de la caja
        this->ancho = a;  // Inicializa el ancho de la caja
        this->alto = h;   // Inicializa el alto de la caja
        cantidadCajas++;  // Incrementa el contador de cajas
    }

    // Destructor que disminuye el contador de cajas
    ~Caja()
    {
        cantidadCajas--;  // Decrementa el contador de cajas
    }
};

// Inicializa la variable estática cantidadCajas a 0
int Caja::cantidadCajas = 0;

// Función principal
int main()
{
    // Muestra la cantidad inicial de cajas (0)
    cout << "Cantidad de cajas: " << Caja::cantidadCajas << endl;

    // Crea una instancia de Caja
    Caja caja1(10, 20, 30);

    // Muestra la cantidad de cajas después de crear caja1 (1)
    cout << "Cantidad de cajas: " << Caja::cantidadCajas << endl;

    // Crea otra instancia de Caja
    Caja caja2(5, 10, 15);

    // Muestra la cantidad de cajas después de crear caja2 (2)
    cout << "Cantidad de cajas: " << Caja::cantidadCajas << endl;

    // Las cajas serán destruidas automáticamente al salir del scope (al final de main)
    // y el destructor será llamado, decrementando el contador de cajas.

    return 0;  // Fin de la función principal
}
