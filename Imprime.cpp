/* Sobrecarga de funciones, 
es poder darle mas de un uso a 
una funcion con el mismo nombre  */
#include <iostream>  // Incluimos la librería estándar de entrada y salida

using namespace std;  // Usamos el espacio de nombres estándar para evitar escribir "std::" repetidamente

// Definimos una clase llamada Imprime
class Imprime
{
private:
    // Aquí se podrían declarar variables miembro privadas si fueran necesarias
public:
    // Sobrecargamos el método imprime para que pueda aceptar diferentes tipos de datos

    // Método imprime que acepta un entero
    void imprime(int n){
        cout << n << endl;  // Imprime el entero seguido de un salto de línea
    }

    // Método imprime que acepta un número de punto flotante (double)
    void imprime(double n){
        cout << n << endl;  // Imprime el número de punto flotante seguido de un salto de línea
    }

    // Método imprime que acepta un carácter
    void imprime(char n){
        cout << n << endl;  // Imprime el carácter seguido de un salto de línea
    }

    // Constructor de la clase Imprime
    Imprime(/* args */);
    // Destructor de la clase Imprime
    ~Imprime();
};

// Definición del constructor de la clase Imprime
Imprime::Imprime(/* args */)
{
    // Este constructor no realiza ninguna acción específica
}

// Definición del destructor de la clase Imprime
Imprime::~Imprime()
{
    // Este destructor no realiza ninguna acción específica
}
