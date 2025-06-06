#include<iostream>
#include <string>
#include <algorithm>
#include <iomanip> 
#include <cmath>
using namespace std;
void fechacom(int Fecha){
    int Año, mes,dia;
    int contador=0;
    int fecha2=Fecha;
    while(fecha2>0){
fecha2/=10;
contador++;
    }
    if(contador==6){
 Año=Fecha/100;
 mes=(Fecha/10)%10;
 dia=Fecha%10;
    }else {
 Año=Fecha/10000;//Le quita los ultimos 4 digitos
mes=(Fecha/100)%100;
 dia=Fecha%100 ;
}
 cout <<"La fecha es de "<< setfill('0') << setw(4) << Año<< "/"<<setw(2)<<mes<< "/"<< setw(2)<<dia << endl;//el setfill se mantiene para toda la salida hasta que se cambie
}
int main(){
    string fecha;
int fecha1;
   cout << "Ingrese una fecha con formato aaaa/mm/dd" << endl;
    cin>>fecha1;
   fechacom(fecha1);
    

    return 0;
}