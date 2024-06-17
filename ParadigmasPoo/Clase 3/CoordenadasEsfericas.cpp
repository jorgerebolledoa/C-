#include <cmath>
#include <stdexcept>
#include <iostream>

class Point {
private:
    double r;
    double theta;
    double psi;

public:
    Point(double r, double theta, double psi);

    void setR(double r);
    void setTheta(double theta);
    void setPsi(double psi);

    double getR() const;
    double getTheta() const;
    double getPsi() const;

    bool operator==(const Point& other) const;

    int octant() const;
};

Point::Point(double r, double theta, double psi) {
    setR(r);
    setTheta(theta);
    setPsi(psi);
}

void Point::setR(double r) {
    if (r < 0) throw std::invalid_argument("r debe ser no negativo");
    this->r = r;
}

void Point::setTheta(double theta) {
    if (theta < 0 || theta > 2 * M_PI) throw std::invalid_argument("theta debe estar en [0, 2π]");
    this->theta = theta;
}

void Point::setPsi(double psi) {
    if (psi < 0 || psi > M_PI) throw std::invalid_argument("psi debe estar en [0, π]");
    this->psi = psi;
}

double Point::getR() const {
    return r;
}

double Point::getTheta() const {
    return theta;
}

double Point::getPsi() const {
    return psi;
}

bool Point::operator==(const Point& other) const {
    return (r == other.r) && (theta == other.theta) && (psi == other.psi);
}

int Point::octant() const {
    int octante = 0;
    double x = r * sin(psi) * cos(theta);
    double y = r * sin(psi) * sin(theta);
    double z = r * cos(psi);

    if (x >= 0) {
        if (y >= 0) {
            if (z >= 0) {
                octante = 1;
            } else {
                octante = 5;
            }
        } else {
            if (z >= 0) {
                octante = 4;
            } else {
                octante = 8;
            }
        }
    } else {
        if (y >= 0) {
            if (z >= 0) {
                octante = 2;
            } else {
                octante = 6;
            }
        } else {
            if (z >= 0) {
                octante = 3;
            } else {
                octante = 7;
            }
        }
    }
    return octante;
}

int main() {
    try {
        Point p1(3.0, M_PI / 4, M_PI / 6);
        Point p2(3.0, M_PI / 4, M_PI / 6);

        std::cout << "Octante de P1: " << p1.octant() << std::endl;
        std::cout << "Octante de P2: " << p2.octant() << std::endl;

        if (p1 == p2) {
            std::cout << "P1 y P2 son iguales." << std::endl;
        } else {
            std::cout << "P1 y P2 no son iguales." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

