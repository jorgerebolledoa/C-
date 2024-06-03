#include<iostream>
using namespace std;
    

class Padre : public Abuelo
{
private:
   int y;
public:
    Padre(){y=1;}
    void setY(int a){y=a;}
     void ver(){cout<< "y:"<< y << endl;}

};
