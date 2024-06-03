/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>

using namespace std;

//Definicion
class Complejo{
    private:
        int real;
        int imginario;
    public:
        Complejo(); //constructor
        void mostrar();
        void setReal(int);
        void setImaginario(int);
        int getReal();
        int getImaginario();
        void sumarComplejos(Complejo);  
        void restarComplejos(Complejo); 
};
//Implementación 
Complejo::Complejo()
{
    real = 0;
    imginario = 1; 
}

void Complejo::mostrar() // simpre se va a mostrar de la forma a + bi
// si quisiera que se muestre con la forma a-bi se puede con un if simple cuya condicion sea si imaginario es mayor o igual que 0 agregar un + else - 
{
    cout << real << "+" << imginario<< "i" << endl;
}

int Complejo::getReal()
{
    return real;
    cout << real  << endl;
}

int Complejo::getImaginario()
{
    return imginario;
    cout << imginario << "i" << endl;
}

void Complejo::setReal(int x)
{
    real = x;
}

void Complejo::setImaginario(int x)
{
    imginario = x;
}

void Complejo::sumarComplejos(Complejo C)
{
     int aux1, aux2;
    aux1 = C.real+real;
    aux2 = C.imginario+imginario;
    real= aux1;
    imginario = aux2;
}
void Complejo::restarComplejos(Complejo C)
{
     int aux1, aux2;
    aux1 = C.real-real;
    aux2 = C.imginario-imginario;
    real= aux1;
    imginario = aux2;
}



//Interfaz
int main()
{
     cout<<"Clase Complejo" << endl;
    Complejo C1;
    C1.setReal(2);
    C1.setImaginario(1);
    
    Complejo C2;
    C2.setReal(5);
    C2.setImaginario(-8);
    
    cout << "Complejo C1 : ";
    C1.mostrar();
    
    cout << "Complejo C2 : ";
    C2.mostrar();
    
    cout << "sumando ... " << endl;
    C1.sumarComplejos(C2);  
    C1.mostrar();
    cout << "Restando... " << endl;
    C1.sumarComplejos(C2);  // C1  = F1- F2
    C1.mostrar();
    
}
