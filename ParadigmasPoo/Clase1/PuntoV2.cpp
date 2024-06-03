#include <iostream> // Incluir la biblioteca estándar de entrada/salida

// Definición de la clase Punto
class Punto {
public:
    Punto(); // Constructor por defecto
    Punto(double x, double y); // Constructor que inicializa con coordenadas específicas
    ~Punto(); // Destructor
    void imprimir(); // Método para imprimir las coordenadas del punto
    friend inline Punto operator+(const Punto& p1, const Punto& p2); // Sobrecarga del operador + para sumar dos puntos
    friend std::ostream& operator<<(std::ostream& os, const Punto& p); // Sobrecarga del operador << para imprimir un punto

private:
    double x; // Coordenada x del punto
    double y; // Coordenada y del punto
};

// Implementación del constructor por defecto
Punto::Punto() {
    x = 0;
    y = 0;
}

// Implementación del constructor con parámetros
Punto::Punto(double x, double y) {
    this->x = x;
    this->y = y;
}

// Implementación del destructor
Punto::~Punto() {
    std::cout << "Destructor" << std::endl; // Mensaje para indicar que el destructor ha sido llamado
}

// Implementación del método imprimir
void Punto::imprimir() {
    std::cout << "(" << x << ", " << y << ")" << std::endl; // Imprimir las coordenadas del punto
}

// Implementación de la sobrecarga del operador + para sumar dos puntos
inline Punto operator+(const Punto& p1, const Punto& p2) {
    return Punto(p1.x + p2.x, p1.y + p2.y); // Devolver un nuevo punto con las coordenadas sumadas
}

// Implementación de la sobrecarga del operador << para imprimir un punto
std::ostream& operator<<(std::ostream& os, const Punto& p) {
    os << "(" << p.x << ", " << p.y << ")"; // Formatear la salida del punto
    return os; // Devolver el flujo de salida
}

// Función principal del programa
int main() {
    Punto p1(5, 10); // Crear un punto con coordenadas (5, 10)
    Punto p2(3, 7); // Crear un punto con coordenadas (3, 7)
    Punto p3 = p1 + p2; // Sumar los dos puntos y asignar el resultado a p3
    std::cout << p1 << std::endl; // Imprimir p1
    std::cout << p2 << std::endl; // Imprimir p2
    std::cout << p3 << std::endl; // Imprimir p3
    return 0; // Terminar el programa
}
#include <iostream> // Incluir la biblioteca estándar de entrada/salida

// Definición de la clase Punto
class Punto {
public:
    Punto(); // Constructor por defecto
    Punto(double x, double y); // Constructor que inicializa con coordenadas específicas
    ~Punto(); // Destructor
    void imprimir(); // Método para imprimir las coordenadas del punto
    friend inline Punto operator+(const Punto& p1, const Punto& p2); // Sobrecarga del operador + para sumar dos puntos
    friend std::ostream& operator<<(std::ostream& os, const Punto& p); // Sobrecarga del operador << para imprimir un punto

private:
    double x; // Coordenada x del punto
    double y; // Coordenada y del punto
};

// Implementación del constructor por defecto
Punto::Punto() {
    x = 0;
    y = 0;
}

// Implementación del constructor con parámetros
Punto::Punto(double x, double y) {
    this->x = x;
    this->y = y;
}

// Implementación del destructor
Punto::~Punto() {
    std::cout << "Destructor" << std::endl; // Mensaje para indicar que el destructor ha sido llamado
}

// Implementación del método imprimir
void Punto::imprimir() {
    std::cout << "(" << x << ", " << y << ")" << std::endl; // Imprimir las coordenadas del punto
}

// Implementación de la sobrecarga del operador + para sumar dos puntos
inline Punto operator+(const Punto& p1, const Punto& p2) {
    return Punto(p1.x + p2.x, p1.y + p2.y); // Devolver un nuevo punto con las coordenadas sumadas
}

// Implementación de la sobrecarga del operador << para imprimir un punto
std::ostream& operator<<(std::ostream& os, const Punto& p) {
    os << "(" << p.x << ", " << p.y << ")"; // Formatear la salida del punto
    return os; // Devolver el flujo de salida
}

// Función principal del programa
int main() {
    Punto p1(5, 10); // Crear un punto con coordenadas (5, 10)
    Punto p2(3, 7); // Crear un punto con coordenadas (3, 7)
    Punto p3 = p1 + p2; // Sumar los dos puntos y asignar el resultado a p3
    std::cout << p1 << std::endl; // Imprimir p1
    std::cout << p2 << std::endl; // Imprimir p2
    std::cout << p3 << std::endl; // Imprimir p3
    return 0; // Terminar el programa
}
