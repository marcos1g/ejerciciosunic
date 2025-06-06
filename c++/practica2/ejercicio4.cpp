#include<iostream>
#include <cassert>

using namespace std;
double fechacom(double F){
double equivalencia=100.00/180.00;
double total =(F-32)*equivalencia;
return total;
}
int main(){
    double F;

   cout << "Ingrese grados en Fahrenheit a convertir en grados celcius" << endl;
    cin>>F;
    assert(F>-459.67);
   double final= fechacom(F);
    cout <<"La fecha es de "<< final  << endl;

    return 0;
}