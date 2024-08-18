#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Triangulo.h"

class Circunferencia {
private:
	double a;
	double b;
	double r;
public:
	Circunferencia(double a1, double b1, double r1) {
		a = a1;
		b = b1;
		r = r1;

	}

	bool Punto_is_Inside(Punto p2) const {
		double d = sqrt(pow((p2.getx() - a), 2) + pow((p2.gety() - b), 2));
		if(d>r) {
			return false;
		}
		else {
			return true;
		}
	}
	void ver() {
		 std::cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<std::endl;
	}
};
double distancia_entre_dos_puntos(Punto p1, Punto p2) {
	return sqrt(pow((p2.getx() - p1.getx()), 2) + pow((p2.gety() - p2.gety()), 2));
}

Circunferencia Circunferencia_dado_un_triangulo(Triangulo t1) {
	double mult = t1.getp2().getx() * t1.getp2().getx() + t1.getp2().gety() * t1.getp2().gety();
	double bc = (t1.getp1().getx() * t1.getp1().getx() + t1.getp1().gety() * t1.getp1().gety() - mult) / 2.0;
	double cd = (mult - t1.getp3().getx() * t1.getp3().getx() - t1.getp3().gety() * t1.getp3().gety()) / 2.0;
	double det = (t1.getp1().getx() - t1.getp2().getx()) * (t1.getp2().gety() - t1.getp3().gety()) - (t1.getp2().getx() - t1.getp3().getx()) * (t1.getp1().gety() - t1.getp2().gety());


	// Centro del cC-rculo
	double cx = (bc * (t1.getp2().gety() - t1.getp3().gety()) - cd * (t1.getp1().gety() - t1.getp2().gety())) / det;
	double cy = ((t1.getp1().getx() - t1.getp2().getx()) * cd - (t1.getp2().getx() - t1.getp3().getx()) * bc) / det;

	double radio = std::sqrt((cx - t1.getp1().getx()) * (cx - t1.getp1().getx()) + (cy - t1.getp1().gety()) * (cy - t1.getp1().gety()));

	Circunferencia c1(cx, cy, radio);
	return c1;
}
