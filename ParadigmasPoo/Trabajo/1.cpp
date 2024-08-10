#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100;
using namespace std;


//Para los puntos.
class Punto{
    private:
        int x;
        int y;
        int z;
        double distancia;
    public:
        Punto();
        Punto(int, int, int, double);
        
        void setx(int a){x = a;}
        void sety(int k){y = k;}
        void setz(int j){z = j;}
        void setdistancia(double d){distancia = d;}
        
        int getx(){ return x; }
        int gety(){ return y; }
        double getDistancia(){ return distancia; }

        void ver();

        double distancia_entre_dos_puntos(Punto p1, Punto p2);
};
Punto::Punto(){
    x = 0;
    y = 0;
    z = 0;
    distancia = 0;
}
Punto::Punto(int a, int b, int c, double d){
    x = a;
    y = b;
    z = c;
    distancia = d;
}
void Punto::ver(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}
double Punto::distancia_entre_dos_puntos(Punto p1, Punto p2) {
    return std::sqrt(std::pow((p2.getx() - p1.getx()), 2) + std::pow((p2.gety() - p2.gety()), 2));    
}

//Para la lista enlazada.
typedef struct Nodo{
    Punto p1;
    Punto p2;
    struct Nodo *link;
}Nodo;

typedef Nodo *Lista;
    Lista L;
    
void mostrar(Lista L){
    Lista p = L;
    while(p!=NULL){
        p1.ver();
        p2.ver();
        p = p->link;
    }
}

void agregarDer(Lista &L, Punto p1, Punto p2){
    Lista p;
    Lista q;
    p = L;
    while(p->link!=NULL){
        p = p->link;
    }
    q = new(Nodo);
    q->p = p1;
    q->link = NULL;
    p->link = q;
    
    q2 = new(Nodo);
    q2->p2 = p2;
    q2->link = NULL;
    p2->link = q2;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i].getDistancia();
        int j = i - 1;
        while (j >= 0 && arr[j].getDistancia > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1].setdistancia(key);
    }
}

void ordena_lista(Punto array_puntos[], int cant_puntos){
    int i = 1, dist = 0;
    array_puntos_ordenada[100];
    array_puntos_ordenada[0] = array_puntos[0];
    
    while(i<cant_puntos){
        dist = distancia_entre_dos_puntos(array_puntos[i], array_puntos_ordenada[0]);
        array_puntos_ordenada[i] = array_puntos[i];
        i = i+1;
    }
    insertionSort(array_puntos_ordenada, cant_puntos);
}    

int main(){
    
    //Leer los puntos e inicializarlos en un array cualquiera[100]. Parte del Azi.
    //Ordenar la lista según distancia con ordena_lista.
    //montar grafo usando lista enlazada de a pares punto p1 hace arista con punto p2 y eso conoforma el primer elemento.
    
    return 0;   
}
