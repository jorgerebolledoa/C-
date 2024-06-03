#include<iostream>
using namespace std;
#include"Rut.h"
#include"Fecha.h"
#include"Persona.h"
#include"Alumno.h"
#include"Profesor.h"


 int main()
 {
    cout<<"Uso de herencias"<<endl;
    
    Rut aziel;
    aziel.mostrar();
    aziel.setDv('k');
    aziel.mostrar();
    Fecha hoy;
    hoy.mostrar();
    Persona Az("aziel",hoy,aziel);
    
 }