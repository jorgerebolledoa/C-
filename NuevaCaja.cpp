#include <iostream>
using std::cout;
using std::endl;

class Caja
{
private:
    double largo;
    double ancho;
    double alto;

public:
    // Constructor
    Caja(double l = 0, double a = 0, double h = 0) : largo(l), ancho(a), alto(h) {}

    // Sobrecarga del operador +
    Caja operator+(const Caja& otraCaja)
    {
        return Caja(this->largo + otraCaja.largo, this->ancho + otraCaja.ancho, this->alto + otraCaja.alto);
    }

    // Sobrecarga del operador ==
    bool operator==(const Caja& otraCaja)
    {
        return (this->largo == otraCaja.largo && this->ancho == otraCaja.ancho && this->alto == otraCaja.alto);
    }

    // Método para imprimir las dimensiones de la caja
    void imprimir()
    {
        cout << "Largo: " << largo << ", Ancho: " << ancho << ", Alto: " << alto << endl;
    }
};

int main()
{
    Caja caja1(10, 20, 30);
    Caja caja2(5, 10, 15);
    Caja caja3;

    // Sumar dos cajas usando el operador sobrecargado +
    caja3 = caja1 + caja2;

    cout << "Caja 1: ";
    caja1.imprimir();
    cout << "Caja 2: ";
    caja2.imprimir();
    cout << "Caja 3 (resultado de caja1 + caja2): ";
    caja3.imprimir();

    // Comparar dos cajas usando el operador sobrecargado ==
    if (caja1 == caja2)
    {
        cout << "Caja 1 es igual a Caja 2" << endl;
    }
    else
    {
        cout << "Caja 1 no es igual a Caja 2" << endl;
    }

    return 0;
}
