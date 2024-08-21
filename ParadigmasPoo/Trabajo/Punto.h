#ifndef PUNTO_H
#define PUNTO_H
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
class Punto{
    private:
        int x;
        int y;
        int z;
        int distancia;
    public:
        Punto();
        Punto(int, int, int, int);
        
        void setx(int a){x = a;}
        void sety(int k){y = k;}
        void setz(int j){z = j;}
        void setdistancia(int d){distancia = d;}
        
        int getx() const { return x; }
        int gety() const { return y; }
        int getz() const { return z; }
        int getDistancia(){ return distancia; }
        
        
        void ver()const ;

        bool operator<(const Punto& other) const {
            if (x == other.x) {
                return y < other.y;
            }
            return x < other.x;
        }

        bool operator==(const Punto& other) const {
            return x == other.x && y == other.y;
        }

};
Punto::Punto(){
    x = 0;
    y = 0;
    z = 0;
    distancia = 0;
}
Punto::Punto(int a, int b, int c, int d){
    x = a;
    y = b;
    z = c;
    distancia = d;
}
void Punto::ver()const {
    std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}
#endif // PUNTO_H
