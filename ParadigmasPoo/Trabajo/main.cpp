#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "Punto.h"
#include "Triangulo.h"
#include "Circunferencia.h"
#define SIZE 4
using namespace std;
//Para la lista enlazada.
typedef struct Nodo {
	Punto p1;
	Punto p2;
	struct Nodo *link;
} Nodo;

typedef Nodo *Lista;
Lista L;

void mostrar(Lista L) {
	Lista p = L;
	int i = 0;
	while(p!=NULL) {
		cout<<"Par "<<i<<":"<<endl;
		p->p1.ver();
		p->p2.ver();
		p = p->link;
		i = i+1;
	}
}

void agregarDer(Lista &L, Punto p1) {
	Lista p;
	Lista q;
	p = L;
	while(p->link!=NULL) {
		p = p->link;
	}
	q = new(Nodo);
	q->p1 = p1;
	q->link = NULL;
	p->link = q;

}

void agregarDerPares(Lista &L, Punto p1, Punto p2) {
	Lista p = L;
	Lista q = new Nodo;
	q->p1 = p1;
	q->p2 = p2;
	q->link = NULL;

	if (p == NULL) {
		L = q;
	} else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = q;
	}
}

void insertionSort(Punto arr[], int n)
{
	for (int i = 1; i < n; ++i) {
		double key = arr[i].getDistancia();
		int j = i - 1;
		while (j >= 0 && arr[j].getDistancia() > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1].setdistancia(key);
	}
}

void ordena_lista(Punto array_puntos[], int cant_puntos) {
	int i = 1;
	double dist;
	Punto array_puntos_ordenada[100];
	array_puntos_ordenada[0] = array_puntos[0];

	while(i<cant_puntos) {
		dist = distancia_entre_dos_puntos(array_puntos[i], array_puntos_ordenada[0]);
		array_puntos_ordenada[i] = array_puntos[i];
		i = i+1;
	}
	insertionSort(array_puntos_ordenada, cant_puntos);
}

typedef struct Nodo_M {
    Punto centroide;
    struct Nodo_M* link;
} Nodo_M;

typedef Nodo_M* Lista_M;

void AgregarCentroide(Lista_M& L, const Punto& centroide) {
    Nodo_M* nuevoNodo_M = new Nodo_M;
	nuevoNodo_M->centroide = centroide;
    nuevoNodo_M->link = L;
    L = nuevoNodo_M;
}
//recorre la Lista_M
void MostrarLista_M(Lista_M L) {//se uniran los centroides con un -->
    Nodo_M* p = L;
    while (p != nullptr) {
        p->centroide.ver();
        if (p->link != nullptr) {
            cout << " --> ";
        }
        p = p->link;
    }
    cout << endl;
}

vector<Punto> leer_puntos_desde_csv(const string& nombre_archivo) {
    vector<Punto> puntos;
    ifstream archivo(nombre_archivo);
    string linea;
    
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        double x, y, z;
        char separador;
        
        ss >> x >> separador >> y >> separador >> z;
        
        if (ss.fail()) {
            // Si hay un fallo, inicializamos z a 0
            ss.clear();
            ss.str(linea);
            ss >> x >> separador >> y;
            z = 0;
        }
        
        puntos.emplace_back(x, y, z, 0);
    }
    
    return puntos;
}
void guardar_lista_pares_en_csv(Lista L, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "Punto1_X,Punto1_Y,Punto1_Z,Punto2_X,Punto2_Y,Punto2_Z" << endl;
    Lista p = L;
    while (p != NULL) {
        archivo << p->p1.getx() << "," << p->p1.gety() << "," << p->p1.getz() << ",";
        archivo << p->p2.getx() << "," << p->p2.gety() << "," << p->p2.getz() << endl;
        p = p->link;
    }
    archivo.close();
    cout << "Lista de pares guardada en " << nombre_archivo << endl;
}
int main() {
    // Leer puntos desde un archivo CSV
    string nombre_archivo = "puntos.csv";
    vector<Punto> puntos = leer_puntos_desde_csv(nombre_archivo);
    
    if (puntos.size() < SIZE) {
        cout << "Error: El archivo CSV debe contener al menos " << SIZE << " puntos." << endl;
        return 1;
    }
    
    // Convertir el vector a un array para el uso posterior
    Punto lista_puntos[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        lista_puntos[i] = puntos[i];
    }
    
    // Ordenamos la lista_puntos
    ordena_lista(lista_puntos, SIZE);
    
    // Mostrar puntos ordenados
    cout << "Puntos ordenados" << endl;
    for (int i = 0; i < SIZE; ++i) {
        lista_puntos[i].ver();
    }
    
    // Ahora agregamos los puntos a la lista de Pares
    Lista lista_punto_pares = NULL;
    for (int i = 0; i < SIZE - 1; i += 2) {
        agregarDerPares(lista_punto_pares, lista_puntos[i], lista_puntos[i+1]);
    }
    
    // Mostrar lista de pares
    mostrar(lista_punto_pares);
	// Guardar la lista de pares en un archivo CSV
    guardar_lista_pares_en_csv(lista_punto_pares, "pares_puntos.csv");

	//Leer los puntos e inicializarlos en un array cualquiera[100]. Parte del Azi.
	//Ordenar la lista segC:n distancia con ordena_lista.
	//montar grafo usando lista enlazada de a pares punto p1 hace arista con punto p2 y eso conoforma el primer elemento.

	//Definimos listas
    //Punto lista_puntos[SIZE];
	//Punto aux[SIZE];
	//Lista lista_punto_pares = NULL;
	//Definimos Puntos
	//Punto p1(0,0,0,0);
	//Punto p2(4,5,0,0);
	//Punto p3(-3,10,0,0);
	//Punto p4(7,-9,0,0);
	//Agregamos a lista
	//lista_puntos[0] = p1;
	//lista_puntos[1] = p2;
	//lista_puntos[2] = p3;
	//lista_puntos[3] = p4;
	//Ordenamos la lista_puntos
	//ordena_lista(lista_puntos, 3);
	//mostrar
	//cout<<"Puntos ordenados"<<endl;
	//lista_puntos[0].ver();
	//lista_puntos[1].ver();
	//lista_puntos[2].ver();
	//lista_puntos[3].ver();
	//FUNCIONC
	//Ahora agregamos los puntos a la lista de Pares;
	//int i = 0;
	//while(i<SIZE) {
	//	agregarDerPares(lista_punto_pares, lista_puntos[i], lista_puntos[i+1]);
		//i = i+2;
	//}
	//mostrar(lista_punto_pares);
	//mostrar


	return 0;
}

