#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    Fecha FechaNaciomiento;
    Rut MiRut;
public:
    Persona(string,Fecha,Rut);
    Persona();
    void mostrar();
};

Persona::Persona()
{
    nombre="aziel";


}
Persona::Persona(string a, Fecha b, Rut c)
{
    nombre=a;
    FechaNaciomiento = b;
    MiRut = c;


}
void Persona::mostrar(){
    cout << nombre << endl;
    FechaNaciomiento.mostrar();
    MiRut.mostrar();
    
}