#include <iostream>

class Punto {
    public:
        Punto();
        Punto(int x, int y);
        ~Punto();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        void imprimir();    
    private:
        int x;
        int y;
};
Punto::Punto() {
    x = 0;
    y = 0;
}
Punto::Punto(int x, int y) {
    this->x = x;
    this->y = y;
}
Punto::~Punto() {
    std::cout << "Destructor" << std::endl;
}
void Punto::setX(int x) {
    this->x = x;
}
void Punto::setY(int y) {
    this->y = y;
}
int Punto::getX() {
    return x;
}
int Punto::getY() {
    return y;
}
void Punto::imprimir() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

int main() {
    Punto p1;
    p1.setX(5);
    p1.setY(10);
    p1.imprimir();
    Punto p2(3, 7);
    p2.imprimir();
    return 0;
}