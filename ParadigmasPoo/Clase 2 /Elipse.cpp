/* Problema:
defina una clase para manipular elipses en un plano cartesiano. La clase debe tener los siguientes métodos:
1. Considere atributos publicos y privados para la clase. justifique su elección.
2. Defina atributos y funciones para mantener:
    - semieje mayor a
    - semieje menor b
    - focos -sqrt(a^2 - b^2) y sqrt(a^2 - b^2)
    - excentricidad  e = sqrt(sqrt(a^2 - b^2)/a)
    - distancia focal 
    - area
    - perimetro:
      - aproximacion de ramanujan: 2 * pi *(3(a + b  - sqrt((3a + b) (a + 3b))))
      - ramanujan II: pi (a + b) (1 + 3 h / (10 + sqrt(4 - 3 h))), h = (a - b) ^ 2 / (a + b) ^ 2
      - gauss-kummer : pi (a + b) (1 + (1/4) h / (1 + (9/64) h / (1 + (25/256) h / (1 + (49/625) h / ...))))
    -haga una definicion del operador == (sobregarca):
        - para areas iguales 
        - para perimetros iguales (ramaunjan II)
        - para perimetros iguales(Gaus-kummer)
*/

#include <cmath>
#include <iostream>

class Elipse {
private:
    double semiejeMayor;
    double semiejeMenor;

public:
    // Constructor
    Elipse(double a, double b) : semiejeMayor(a), semiejeMenor(b) {}

    // Getter methods
    double getSemiejeMayor() const {
        return semiejeMayor;
    }

    double getSemiejeMenor() const {
        return semiejeMenor;
    }

    // Calculating methods
    double getFocoX() const {
        return sqrt(pow(semiejeMayor, 2) - pow(semiejeMenor, 2));
    }

    double getFocoY() const {
        return 0;
    }

    double getExcentricidad() const {
        return sqrt(1 - pow(semiejeMenor / semiejeMayor, 2));
    }

    double getDistanciaFocal() const {
        return 2 * getFocoX();
    }

    double getArea() const {
        return M_PI * semiejeMayor * semiejeMenor;
    }

    double getPerimetroRamanujan() const {
        double h = pow(semiejeMayor - semiejeMenor, 2) / pow(semiejeMayor + semiejeMenor, 2);
        return 2 * M_PI * (3 * (semiejeMayor + semiejeMenor) - sqrt((3 * semiejeMayor + semiejeMenor) * (semiejeMayor + 3 * semiejeMenor)));
    }

    double getPerimetroRamanujanII() const {
        double h = pow(semiejeMayor - semiejeMenor, 2) / pow(semiejeMayor + semiejeMenor, 2);
        return M_PI * (semiejeMayor + semiejeMenor) * (1 + 3 * h / (10 + sqrt(4 - 3 * h)));
    }

    double getPerimetroGaussKummer() const {
        double h = pow(semiejeMayor - semiejeMenor, 2) / pow(semiejeMayor + semiejeMenor, 2);
        double result = M_PI * (semiejeMayor + semiejeMenor);
        double denominator = 1;
        for (int i = 1; i <= 10; i++) {
            denominator = 1 + (i * i * h) / denominator;
            result *= denominator;
        }
        return result;
    }

    // Operator overloading
    bool operator==(const Elipse& other) const {
        return getArea() == other.getArea();
    }

    bool operator==(double perimetro) const {
        return getPerimetroRamanujanII() == perimetro;
    }

    bool operator==(int perimetro) const {
        return getPerimetroGaussKummer() == perimetro;
    }
};
int main() {
    // Create an instance of Elipse
    Elipse elipse(5, 3);

    // Print the attributes and calculated values
    std::cout << "pi " << M_PI<< std::endl;
    std::cout << "Semieje Mayor: " << elipse.getSemiejeMayor() << std::endl;
    std::cout << "Semieje Menor: " << elipse.getSemiejeMenor() << std::endl;
    std::cout << "Foco X: " << elipse.getFocoX() << std::endl;
    std::cout << "Foco Y: " << elipse.getFocoY() << std::endl;
    std::cout << "Excentricidad: " << elipse.getExcentricidad() << std::endl;
    std::cout << "Distancia Focal: " << elipse.getDistanciaFocal() << std::endl;
    std::cout << "Area: " << elipse.getArea() << std::endl;
    std::cout << "Perimetro (Ramanujan): " << elipse.getPerimetroRamanujan() << std::endl;
    std::cout << "Perimetro (Ramanujan II): " << elipse.getPerimetroRamanujanII() << std::endl;
    std::cout << "Perimetro (Gauss-Kummer): " << elipse.getPerimetroGaussKummer() << std::endl;

    // Check if the elipse has the same area as another elipse
    Elipse otherElipse(4, 2);
    if (elipse == otherElipse) {
        std::cout << "The elipses have the same area." << std::endl;
    } else {
        std::cout << "The elipses do not have the same area." << std::endl;
    }

    // Check if the elipse has the same perimetro as a given value
    double perimetro = 30.0;
    if (elipse == perimetro) {
        std::cout << "The elipse has the same perimetro (Ramanujan II) as " << perimetro << std::endl;
    } else {
        std::cout << "The elipse does not have the same perimetro (Ramanujan II) as " << perimetro << std::endl;
    }

    // Check if the elipse has the same perimetro as a given value
    int perimetroInt = 40;
    if (elipse == perimetroInt) {
        std::cout << "The elipse has the same perimetro (Gauss-Kummer) as " << perimetroInt << std::endl;
    } else {
        std::cout << "The elipse does not have the same perimetro (Gauss-Kummer) as " << perimetroInt << std::endl;
    }

    return 0;
}