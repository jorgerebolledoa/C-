/******************************************************************************
clase fraccion

*******************************************************************************/
#include <iostream>

using namespace std;

//declaracion
class Fraccion{
    private:
        int num, den;
    public:
        Fraccion();
        Fraccion(int);
        Fraccion(int, int);
        Fraccion(const Fraccion &);
        
        void setNum(int a){ num = a; }
        void setDen(int a){ den = a; }
        
        int getNum() { return num; }
        int getDen() { return den; }
        
        void mostrar();
        
        void sumar(Fraccion F);
        void resta(Fraccion F);
        void multiplicar(Fraccion F);
        void dividir(Fraccion F);
};

// implementacion de funciones miembros
Fraccion::Fraccion()  //sin argumentos
{
    num = 0;
    den = 1;
}
Fraccion::Fraccion(int a)   //con 1 argumento
{
    num = a;
    den = 1;
}
Fraccion::Fraccion(int a, int b)   //con 2 argumento
{
    num = a;
    den = b;
}
Fraccion::Fraccion(const Fraccion &X)   //constructor copia
{
    num = X.num;
    den = X.den;
}
void Fraccion::mostrar()
{
    cout << "F : " << num << "/" << den << endl;
}

void Fraccion::resta(Fraccion F)  //función miembro
{
    int aux1 = F.den * den;
    int aux2 = F.den*num + F.num*den;
    num = aux2;
    den = aux1;
}
void Fraccion::sumar(Fraccion F)  //función miembro
{
    int aux1 = F.den * den;
    int aux2 = F.den*num - F.num*den;
    num = aux2;
    den = aux1;
}
void Fraccion::multiplicar(Fraccion F)  //función miembro
{
    int aux1 = F.den * den;
    int aux2 = F.num *num;
    num = aux2;
    den = aux1;
}
void Fraccion::dividir(Fraccion F)  //función miembro
{
    int aux1 = F.den * num;
    int aux2 = F.num *den;
    num = aux2;
    den = aux1;
}
//////////////////////////////
//funcion externa
void sumando(Fraccion F1, Fraccion F2)
{
    int auxDen = F1.getDen() * F2.getDen();
    int auxNum = F1.getDen() * F2.getNum() + F2.getDen() * F1.getNum();
    Fraccion aux;
    aux.setNum(auxNum);
    aux.setDen(auxDen);
    aux.mostrar();
}
void restando(Fraccion F1, Fraccion F2)
{
    int auxDen = F1.getDen() * F2.getDen();
    int auxNum = F1.getDen() * F2.getNum() - F2.getDen() * F1.getNum();
    Fraccion aux;
    aux.setNum(auxNum);
    aux.setDen(auxDen);
    aux.mostrar();
}
void multiplicando(Fraccion F1, Fraccion F2)
{
    int auxDen = F1.getDen() * F2.getDen();
    int auxNum = F2.getNum()  * F1.getNum();
    Fraccion aux;
    aux.setNum(auxNum);
    aux.setDen(auxDen);
    aux.mostrar();
}
void dividiendo(Fraccion F1, Fraccion F2)
{
    int auxDen = F1.getDen() * F2.getNum();
    int auxNum = F1.getNum()  * F2.getDen();
    Fraccion aux;
    aux.setNum(auxNum);
    aux.setDen(auxDen);
    aux.mostrar();
}


// interfaz
int main()
{
    cout<<"principal" << endl;
    Fraccion F1;
    F1.setNum(9);
    F1.setDen(8);
    F1.mostrar();
    
    Fraccion F2(5);
    F2.mostrar();
    
    Fraccion F3(2,3);
    F3.mostrar();
    
    Fraccion F4(F3);
    F4.mostrar();

    F4.sumar(F3);
    cout << "sumar : " << endl;
    F4.mostrar();
    F4.resta(F3);
    cout << "resta : " << endl;
    F4.mostrar();
    
    cout << "sumando ..." << endl;
    sumando(F1,F2);
    cout << "restando ..." << endl;
    restando(F1,F2);
    
    F1.dividir(F2);
    cout << "dividiendo ..." << endl;
    F1.mostrar();
   
    cout << "dividiendo ..." << endl;
    dividiendo(F1,F2);
    

    return 0;
}

