/******************************************************************************
Clase PUNTO

*******************************************************************************/
#include <iostream>


using namespace std;
/////////// Definicion de la clase
class Punto{
    private:
        int x;
        int y;
    public:
        Punto();  //constructor
        void mostrar();
        void setX(int a);
        void setY(int a);
};

///////// implementación
Punto::Punto()
{
    x = 0;
    y = 0;
}

void Punto::mostrar()
{
   cout << "Punto : " << x << "," << y << endl; 
}
void Punto::setX(int a)
{
    x = a;
}
void Punto::setY(int a)
{
    y = a;
}

///// interfaz
int main()
{
    Punto P1;
    P1.mostrar();
    P1.setX(4);
    P1.setY(3);
    P1.mostrar();
    
    Punto P2;
    P2.mostrar();

    return 0;
}
