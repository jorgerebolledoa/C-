#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Punto.h"
class Triangulo {
    private: 
        Punto p1, p2, p3;
    public:
        Triangulo(const Punto& punto1, const Punto& punto2, const Punto& punto3) 
            : p1(punto1), p2(punto2), p3(punto3) {}
        
        Punto CalcularCentroide()  {
            double xCentroide = (p1.getx() + p2.getx() + p3.getx()) / 3;
            double yCentroide = (p1.gety() + p2.gety() + p3.gety()) / 3;
            return Punto(xCentroide, yCentroide, -1, -1);
        }
        Punto getp1()const { return p1; }
        Punto getp2()const { return p2; }
        Punto getp3()const { return p3; }
        void mostrar()const;
};
void Triangulo::mostrar()const{
    p1.ver();
    p2.ver();
    p3.ver();
}

#endif // TRIANGULO_H