# Estructura de datos
[https://github.com/jorgerebolledoa/C-/tree/master/C-Estructura-de-datos](Estructura de datos)
# Clase 1 Paradigmas POO

## Contenidos Vistos

### 1. Introducción a C++
- **Historia y evolución**: Breve resumen de cómo ha evolucionado C++ desde sus inicios.
- **Características del lenguaje**: Discusión sobre las principales características de C++, como la programación orientada a objetos, la tipificación estática y la eficiencia.

### 2. Estructura Básica de un Programa en C++
- **Sintaxis básica**: Ejemplo de un programa simple en C++.
    ```cpp
    #include <iostream>

    int main() {
        std::cout << "Hola, mundo!" << std::endl;
        return 0;
    }
    ```
- **Explicación de los componentes**: 
  - `#include <iostream>`: Directiva de preprocesador para incluir la librería de entrada/salida.
  - `int main()`: Función principal de donde empieza la ejecución del programa.
  - `std::cout`: Objeto para imprimir en la consola.
  - `return 0;`: Indica que el programa finaliza correctamente.

### 3. Clases y Objetos
- **Definición de una clase**: Cómo se define una clase en C++.
    ```cpp
    class Caja {
    private:
        double largo;
        double ancho;
        double alto;

    public:
        Caja(double l, double a, double h) : largo(l), ancho(a), alto(h) {}
    };
    ```
- **Creación de objetos**: Instanciación de objetos de una clase.
    ```cpp
    Caja caja1(10, 20, 30);
    ```

### 4. Sobrecarga de Operadores
- **Sobrecarga de operadores**: Permitir que los operadores trabajen con objetos de usuario.
    ```cpp
    Caja operator+(const Caja& otraCaja) {
        return Caja(this->largo + otraCaja.largo, this->ancho + otraCaja.ancho, this->alto + otraCaja.alto);
    }
    ```

### 5. Métodos y Constructores
- **Definición de métodos**: Cómo definir y usar métodos dentro de una clase.
    ```cpp
    void imprimir() {
        std::cout << "Largo: " << largo << ", Ancho: " << ancho << ", Alto: " << alto << std::endl;
    }
    ```
- **Constructores y destructores**: Inicialización y limpieza de objetos.
    ```cpp
    Caja(double l, double a, double h) : largo(l), ancho(a), alto(h) {
        cantidadCajas++;
    }

    ~Caja() {
        cantidadCajas--;
    }
    ```

### 6. Variables y Métodos Estáticos
- **Uso de variables estáticas**: Compartir datos entre todas las instancias de una clase.
    ```cpp
    static int cantidadCajas;
    ```

### 7. Entrada y Salida
- **Entrada y salida estándar**: Uso de `std::cin` y `std::cout` para entrada y salida de datos.
    ```cpp
    int numero;
    std::cout << "Ingresa un número: ";
    std::cin >> numero;
    std::cout << "El número ingresado es: " << numero << std::endl;
    ```

### 8. Buenas Prácticas
- **Nombrado de variables y funciones**: Uso de nombres descriptivos y estilo de código.
- **Comentarios**: Importancia de comentar el código para mejorar la legibilidad y mantenimiento.

---

Este archivo README proporciona un resumen de los conceptos y ejemplos cubiertos en la primera clase de C++. Asegúrate de revisar cada sección y practicar con los ejemplos proporcionados para fortalecer tu comprensión.
