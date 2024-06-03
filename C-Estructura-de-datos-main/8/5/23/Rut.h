#include <iostream>

using namespace std;

class Rut{
    private:
        int num;
        char dv;
    public:
        Rut(); 
        Rut(int,char);
        void mostrar();
        void setNum(int);
        void setDv(char);
        int getNum();
        char getDv();
        
        };
Rut::Rut()
{
    num = 20713367;
    dv = '1';        
}
  
void Rut::mostrar()
{
    cout << num << "-" << dv << endl;
}

int Rut::getNum()
{
    return num;
}

char Rut::getDv()
{
    return dv;
}

void Rut::setNum(int x)
{
    num = x;
}

void Rut::setDv(char x)
{
    dv = x;
}



