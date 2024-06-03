#include <iostream> // Incluir la biblioteca estándar de entrada/salida

// Definición de la clase Punto
class Punto {
public:
    // Constructores
    Punto(); // Constructor por defecto
    Punto(int x, int y); // Constructor con parámetros para inicializar el punto con coordenadas específicas

    // Destructor
    ~Punto();

    // Métodos para establecer las coordenadas del punto
    void setX(int x);
    void setY(int y);

    // Métodos para obtener las coordenadas del punto
    int getX();
    int getY();

    // Método para imprimir las coordenadas del punto
    void imprimir();

private:
    int x; // Coordenada x del punto
    int y; // Coordenada y del punto
};

// Implementación del constructor por defecto
Punto::Punto() {
    x = 0; // Inicializar x a 0
    y = 0; // Inicializar y a 0
}

// Implementación del constructor con parámetros
Punto::Punto(int x, int y) {
    this->x = x; // Inicializar x con el valor proporcionado
    this->y = y; // Inicializar y con el valor proporcionado
}

// Implementación del destructor
Punto::~Punto() {
    std::cout << "Destructor" << std::endl; // Imprimir un mensaje cuando el destructor es llamado
}

// Implementación del método setX para establecer la coordenada x
void Punto::setX(int x) {
    this->x = x;
}

// Implementación del método setY para establecer la coordenada y
void Punto::setY(int y) {
    this->y = y;
}

// Implementación del método getX para obtener la coordenada x
int Punto::getX() {
    return x;
}

// Implementación del método getY para obtener la coordenada y
int Punto::getY() {
    return y;
}

// Implementación del método imprimir para imprimir las coordenadas del punto
void Punto::imprimir() {
    std::cout << "(" << x << ", " << y << ")" << std::endl; // Imprimir las coordenadas en el formato (x, y)
}

// Función principal del programa
int main() {
    Punto p1; // Crear un objeto Punto utilizando el constructor por defecto
    p1.setX(5); // Establecer la coordenada x de p1 a 5
    p1.setY(10); // Establecer la coordenada y de p1 a 10
    p1.imprimir(); // Imprimir las coordenadas de p1

    Punto p2(3, 7); // Crear un objeto Punto utilizando el constructor con parámetros
    p2.imprimir(); // Imprimir las coordenadas de p2

    return 0; // Finalizar el programa
}
