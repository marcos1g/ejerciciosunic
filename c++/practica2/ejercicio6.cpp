#include<iostream>
#include <string>
#include <algorithm>
#include<cassert>

using namespace std;
int fecha(int num1,int num2){/*
    string Num1=to_string(num1);
char Num2='0'+num2;
    int contador=0, contador2=0;
    while(num1>0){
        num1/=10;
        contador++;
    }
   Num1.erase(std::remove(Num1.begin(),Num1.end(),Num2),Num1.end());
    int final=stoi(Num1);
     while(final>0){
        final/=10;
        contador2++;
    }
    int F=contador-contador2;
return F;*/
int contador=0;
while(num1!=0){
if(num1%10==num2){
contador ++;
}
num1/=10;  //El hecho de convertir a string o biseversa ocupa demasiada memoria y tarda mas tiempo
}
return contador;

}
int main(){
    int num1,num2;

   cout << "Ingrese 2 numeros" << endl;
    cin>>num1>>num2;
    assert(num2<10);
   int final= fecha(num1,num2);
    cout <<"El numero se repetia "<< final  <<"veces"<< endl;

    return 0;
}