#include <iostream>

#include "Rut.h"
#include "Fecha.h"
#include "Persona.h"

using namespace std;
int main(){
    Rut aziel;
    aziel.mostrar();
    aziel.setDv('k');
    aziel.mostrar();
    Fecha hoy;
    hoy.mostrar();
    Persona Az("aziel",hoy,aziel);
    

}
