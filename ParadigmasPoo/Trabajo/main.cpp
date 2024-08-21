#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "Punto.h"
#include "Triangulo.h"
#include "Circunferencia.h"
#include <numeric>
#define SIZE 5
using namespace std;

// Para la lista enlazada.
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
    while (p != NULL) {
        cout << "Par " << i << ":" << endl;
        p->p1.ver();
        p->p2.ver();
        p = p->link;
        i = i + 1;
    }
}

void agregarDer(Lista &L, Punto p1) {
    Lista p;
    Lista q;
    p = L;
    while (p->link != NULL) {
        p = p->link;
    }
    q = new Nodo;
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

void insertionSort(Punto arr[], int n) {
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

    while (i < cant_puntos) {
        dist = distancia_entre_dos_puntos(array_puntos[i], array_puntos_ordenada[0]);
        array_puntos_ordenada[i] = array_puntos[i];
        i = i + 1;
    }
    insertionSort(array_puntos_ordenada, cant_puntos);
}

typedef struct Nodo_M {
    Punto centroide;
    struct Nodo_M *link;
} Nodo_M;

typedef Nodo_M *Lista_M;

void AgregarCentroide(Lista_M &L, const Punto &centroide) {
    Nodo_M *nuevoNodo_M = new Nodo_M;
    nuevoNodo_M->centroide = centroide;
    nuevoNodo_M->link = L;
    L = nuevoNodo_M;
}

// Recorrer la Lista_M
void MostrarLista_M(Lista_M L) { // Se unirán los centroides con un -->
    Nodo_M *p = L;
    while (p != nullptr) {
        p->centroide.ver();
        if (p->link != nullptr) {
            cout << " --> ";
        }
        p = p->link;
    }
    cout << endl;
}

vector<Punto> leer_puntos_desde_csv(const string &nombre_archivo) {
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

void guardar_lista_pares_en_csv(Lista L, const string &nombre_archivo) {
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

void generar_triangulos(const vector<Punto> &puntos, vector<Triangulo> &triangulos) {
    int n = puntos.size();
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                Triangulo t(puntos[i], puntos[j], puntos[k]);
                triangulos.push_back(t);
            }
        }
    }
}

void guardar_vertices(vector<Punto> &array, const vector<Triangulo> &triangulos) {
    int index = 0;
    for (const auto &triangulo : triangulos) {
        array[index++] = triangulo.getp1();
        array[index++] = triangulo.getp2();
        array[index++] = triangulo.getp3();
    }
}

void mostrar_vertices(const vector<Punto> &array) {
    cout << "Lista de vértices:" << endl;
    for (size_t i = 0; i < array.size(); i += 1) {
        array[i].ver();
    }
}

void mostrar_triangulos(const vector<Triangulo> &triangulos) {
    for (size_t i = 0; i < triangulos.size(); ++i) {
        cout << "Triángulo " << i + 1 << ":" << endl;
        triangulos[i].mostrar();
        cout << endl;
    }
}

void guardar_triangulos_en_csv(const vector<Triangulo> &triangulos, const string &nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "Punto1_X,Punto1_Y,Punto1_Z,Punto2_X,Punto2_Y,Punto2_Z,Punto3_X,Punto3_Y,Punto3_Z" << endl;
    for (const auto &t : triangulos) {
        archivo << t.getp1().getx() << "," << t.getp1().gety() << "," << t.getp1().getz() << ",";
        archivo << t.getp2().getx() << "," << t.getp2().gety() << "," << t.getp2().getz() << ",";
        archivo << t.getp3().getx() << "," << t.getp3().gety() << "," << t.getp3().getz() << endl;
    }

    archivo.close();
    cout << "Triángulos guardados en " << nombre_archivo << endl;
}

void guardar_puntos_en_csv(const vector<Punto> &lista_puntos_voronoi, const string &nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "Punto1_X,Punto1_Y,Punto1_Z,Punto2_X,Punto2_Y,Punto2_Z,Punto3_X,Punto3_Y,Punto3_Z" << endl;
    for (const auto &t : lista_puntos_voronoi) {
        archivo << t.getx() << "," << t.gety() << "," << t.getz() << ",";
    }

    archivo.close();
    cout << "puntos guardados en " << nombre_archivo << endl;
}

void generar_circunferencias(const vector<Triangulo> &triangulos, vector<Circunferencia> &circunferencias) {
    for (const auto &triangulo : triangulos) {
        Circunferencia c = Circunferencia_dado_un_triangulo(triangulo);
        if (c.getradio() != 0.000) {
            circunferencias.push_back(c);
        }
    }
}

void mostrar_circunferencias(const vector<Circunferencia> &circunferencias) {
    for (size_t i = 0; i < circunferencias.size(); ++i) {
        cout << "Circunferencia " << i + 1 << ": Centro (" << circunferencias[i].getx() << ", "
             << circunferencias[i].gety() << "), Radio = " << circunferencias[i].getradio() << endl;
    }
}

void guardar_circunferencias_en_csv(const vector<Circunferencia> &circunferencias, const string &nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "Centro_X,Centro_Y,Radio" << endl;
    for (const auto &c : circunferencias) {
        archivo << c.getx() << "," << c.gety() << "," << c.getradio() << endl;
    }

    archivo.close();
    cout << "Circunferencias guardadas en " << nombre_archivo << endl;
}


bool esValida(const vector<Punto> &puntos) {
    for (size_t i = 0; i + 2 < puntos.size(); ++i) {
        if (puntos[i] == puntos[i + 1] || puntos[i] == puntos[i + 2] || puntos[i + 1] == puntos[i + 2]) {
            return false;
        }
    }
    return true;
}


// Función para imprimir los triángulos
void imprimirTriangulos(const std::vector<std::vector<Punto>> &TotalidadCombinacion) {
    for (const auto &tria : TotalidadCombinacion) {
        cout << "(" << tria[0].getx() << "," << tria[0].gety() << ") "
             << "(" << tria[1].getx() << "," << tria[1].gety() << ") "
             << "(" << tria[2].getx() << "," << tria[2].gety() << ")" << endl;
    }
}
// Función para generar triángulos únicos (n sobre 3 combinaciones de puntos)
std::vector<Triangulo> generarTriangulosUnicos(const std::vector<Punto>& puntos) {
    std::vector<Triangulo> triangulos;
    int n = puntos.size();
    
    // Generar todas las combinaciones de 3 puntos para formar triángulos
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                triangulos.emplace_back(puntos[i], puntos[j], puntos[k]);
            }
        }
    }
    
    return triangulos;
}

// Función para generar todas las combinaciones de (n-2) triángulos
vector<vector<Triangulo>> generarCombinacionesN_2(const vector<Triangulo>& triangulos, int n) {
    int m = triangulos.size();
    vector<vector<Triangulo>> todasLasCombinacionesN_2;

    vector<int> indices(m);
    iota(indices.begin(), indices.end(), 0);  // Llenar el vector con 0, 1, ..., m-1
    
    vector<bool> seleccionados(m, false);
    fill(seleccionados.end() - (n-2), seleccionados.end(), true);

    do {
        vector<Triangulo> combinacionActual;
        
        for (int i = 0; i < m; ++i) {
            if (seleccionados[i]) {
                combinacionActual.push_back(triangulos[indices[i]]);
            }
        }

        todasLasCombinacionesN_2.push_back(combinacionActual);

    } while (next_permutation(seleccionados.begin(), seleccionados.end()));

    return todasLasCombinacionesN_2;
}

bool Not_in(Punto p, const vector<Punto> &lista_b) {
    for (const auto &item : lista_b) {
        if (p.getx() == item.getx() && p.gety() == item.gety()) {
            return false;
        }
    }
    return true;
}

std::vector<Triangulo> condicion(const std::vector<std::vector<Triangulo>>& combinaciones, const std::vector<Punto>& lista_puntos) {
    for (const auto& combinacion : combinaciones) {
        bool puntoDentro = false;

        // Iterar sobre cada triángulo en la combinación actual
        for (const auto& triangulo : combinacion) {
            // Calcula la circunferencia del triángulo
            Circunferencia circunferencia = Circunferencia_dado_un_triangulo(triangulo);

            // Verificar cada punto en la lista
            for (const auto& punto : lista_puntos) {
                // Verificar si el punto no es un vértice del triángulo y está dentro de la circunferencia
                if (punto.getx() != triangulo.getp1().getx() && punto.gety() != triangulo.getp1().gety() &&
                    punto.getx() != triangulo.getp2().getx() && punto.gety() != triangulo.getp2().gety() &&
                    punto.getx() != triangulo.getp3().getx() && punto.gety() != triangulo.getp3().gety() &&
                    circunferencia.Punto_is_Inside(punto)) {
                    puntoDentro = true;
                    break;
                }
            }

            // Si se encontró un punto dentro de la circunferencia, salimos del bucle
            if (puntoDentro) {
                break;
            }
        }

        // Si ningún punto está dentro de las circunferencias de esta combinación, retornamos la combinación
        if (!puntoDentro) {
            return combinacion;
        }
    }

    // Si ninguna combinación cumple la condición, retornamos una lista vacía
    return {};
}
void GrafoVecinoMasCercano(const vector<Punto>& puntos) {
    int n = puntos.size();//para saber el numero de puntos
    
    for (int i = 0; i < n; ++i) { //se va iterando en cada punto
       
        int vecinoMasCercano = -1;
        double distanciaMinima = numeric_limits<double>::max();
        //se inicia con el punto mas alto para siempre encontrar el menor
        
        
        for (int j = 0; j < n; ++j) {//se comparan los puntos expluyendose a si mismo
            if (i != j) {
                double distancia = distancia_entre_dos_puntos(puntos[i], puntos[j]);
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    vecinoMasCercano = j;
                }
            }
        }
        cout<<"Punto ";
        puntos[i].ver();
        cout<<" --> Punto ";
        puntos[vecinoMasCercano].ver();
        cout<<" con una distancia de "<<distanciaMinima<< endl;
    }
}
int main() {
    // Leer puntos desde un archivo CSV
    //
    int cont = 1;
    int n = SIZE;
    string nombre_archivo = "puntos.csv";
    string nombre_archivo_2 = "delaunay.csv";
    string nombre_archivo_3 = "voronoi.csv";
    vector<Punto> puntos = leer_puntos_desde_csv(nombre_archivo);

    if (puntos.size() < SIZE) {
        cout << "Error: El archivo CSV debe contener al menos " << SIZE << " puntos." << endl;
        return 1;
    }

    // Convertir el vector a un array para el uso posterior
    vector<Punto> lista_puntos(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        lista_puntos[i] = puntos[i];
    }

    // Ordenamos la lista_puntos
    ordena_lista(lista_puntos.data(), SIZE);

    // Mostrar puntos ordenados
    cout << "Puntos ordenados" << endl;
    for (int i = 0; i < SIZE; ++i) {
        lista_puntos[i].ver();
    }

    //generar todos los triangulos posibles
    vector<Triangulo> triangulos = generarTriangulosUnicos(lista_puntos);

    // Generar todas las combinaciones de (n-2) triángulos
    vector<vector<Triangulo>> todasLasCombinacionesN_2 = generarCombinacionesN_2(triangulos, n);
    
    // Imprimir las combinaciones (opcional)
    for (const auto& combinacion : todasLasCombinacionesN_2) {
        cout << "Combinación: " <<cont << endl;
        for (const auto& triangulo : combinacion) {
            triangulo.mostrar();
        }
        cont = cont +1;
        cout << endl;
    }

    // generar las circunferencias que abarcan los triangulos
    vector<Circunferencia> circunferencias;
    generar_circunferencias(triangulos, circunferencias);
    mostrar_circunferencias(circunferencias);
    //verificar la condicion
    vector<Triangulo> triangulosClaves = condicion(todasLasCombinacionesN_2, lista_puntos);
    //mostramos resultado
    mostrar_triangulos(triangulosClaves);
    //guardamos en el csv
    guardar_triangulos_en_csv(triangulosClaves, nombre_archivo_2);

    //voronoi
    vector<Punto> lista_puntos_voronoi(triangulosClaves.size());
    for(int i = 0;i< triangulosClaves.size(); i++){
        lista_puntos_voronoi[i] = triangulosClaves[i].CalcularCentroide();
    }
    guardar_puntos_en_csv(lista_puntos_voronoi,nombre_archivo_3);

    GrafoVecinoMasCercano(puntos);
    return 0;

}
