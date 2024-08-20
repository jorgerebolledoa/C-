#ifndef PUNTO_H
#define PUNTO_H
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
class Punto{
    private:
        double x;
        double y;
        double z;
        double distancia;
    public:
        Punto();
        Punto(double, double, double, double);
        
        void setx(int a){x = a;}
        void sety(int k){y = k;}
        void setz(int j){z = j;}
        void setdistancia(double d){distancia = d;}
        
        int getx(){ return x; }
        int gety(){ return y; }
        int getz(){ return z; }
        double getDistancia(){ return distancia; }
        
        void ver();

};
Punto::Punto(){
    x = 0;
    y = 0;
    z = 0;
    distancia = 0;
}
Punto::Punto(double a, double b, double c, double d){
    x = a;
    y = b;
    z = c;
    distancia = d;
}
void Punto::ver(){
    std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}
#endif // PUNTO_H
