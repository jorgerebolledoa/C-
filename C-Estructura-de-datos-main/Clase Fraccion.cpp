/******************************************************************************
Clase Fraccion
*******************************************************************************/
#include <iostream>

using namespace std;

//Definicion
class Fraccion{
    private:
        int num;
        int den;
    public:
        Fraccion(); //constructor
        void mostrar();
        void setNum(int);
        void setDen(int);
        int getNum();
        int getDen();
        void sumar(Fraccion);  //permite sumar 2 fracciones
        void simplicar();
        void multiplicacion(Fraccion);
};

//Implementación
Fraccion::Fraccion()
{
    num = 0;
    den = 1;        //no se usa 0/0 para que no se indetermine
}

void Fraccion::mostrar()
{
    cout << num << "/" << den << endl;
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

void Fraccion::setNum(int x)
{
    num = x;
}

void Fraccion::setDen(int x)
{
    den = x;
}
// Recibe como argumento una fraccion y lo suma con la misma Fraccion
//el resultado lo deja en la misma fraccion.
void Fraccion::sumar(Fraccion F)
{
    int aux1, aux2;
    aux1 = F.den * den; 
    aux2 = F.den*num + F.num*den; 
    num = aux2;
    den = aux1;
}
void Fraccion::simplicar(){
    int n = 2;
    int m = 0;
    while(m<100){// while 1 para repetir la busqueda de numero en caso de necesitar  repitiendo el siguiente 100 veces
        while(n<100){// while 2 para probar si es dividible por todos los numeros desde 2 a 100
            while(den %n == 0 and num%n==0   ){// me da como resultado el numero simplificado por n en caso de que el numerador y divisor sean divisibles por n
                den=den/n;
                num=num/n;
            };
         n+=1;
        };
        m+=1;
    };

};
void Fraccion::multiplicacion(Fraccion F)//rescatar la funcion suma y modificar para que multiplique 
{
    int aux1, aux2;
    aux1 = F.den * den; 
    aux2 = F.num*num  ;
    num = aux2;
    den = aux1;
}

// Interfaz
int main()
{
    cout<<"Clase Fraccion" << endl;
    Fraccion F1;
    F1.setNum(2);
    F1.setDen(3);
    
    Fraccion F2;
    F2.setNum(4);
    F2.setDen(8);
    
    cout << "Fraccion F1 : ";
    F1.mostrar();
    
    cout << "Fraccion F2 : ";
    F2.mostrar();
    
    cout << "sumando ... " << endl;
    F1.sumar(F2);  // F1  = F1 + F2
    F1.mostrar();
    
    //completar
    cout << "simplicando... " << endl;
    F1.simplicar();    //simplifica una fraccion
    F1.mostrar();
    cout << "multiplicando... " << endl;
    //implementar la multiplicacion de fracciones
    F1.multiplicacion(F2);    //simplifica una fraccion
    F1.mostrar();
    cout << "simplicando la multiplicacion... " << endl;
    F1.simplicar();    //simplifica una fraccion
    F1.mostrar();
    return 0;
}

