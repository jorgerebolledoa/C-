#include <iostream>
using namespace std;
class Fecha
{
private:
    int dia;
    int mes;
    int year;
public:
    Fecha();
    Fecha(int,int,int);
    void mostrar();
    void setDia(int);
    void setMes(int);
    void setYear(int);
    int getDia();
    int getMes();
    int getYear();
};

Fecha::Fecha()
{
    dia=8;
    mes=5;
    year=2023;
}

void Fecha::mostrar(){
    cout << dia<< "-" << mes<< "-"<<year << endl;
}
void Fecha::setDia(int x){
    dia = x;
}
void Fecha::setMes(int x){
    mes= x;
}
void Fecha::setYear(int x){
    year= x; 
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getYear(){
    return year;
}