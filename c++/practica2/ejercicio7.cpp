#include<iostream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
bool esbiciesto(int num)
{  
bool a;
num%4==0&&(num%100!=0||num%400==0)?a=true:a=false;
return a; //no se puede usar return en ternarios
}
 
bool fechacom(int año,int mes, int dia){

if(año<1800){
    return false;
}   
if(mes<0 && mes>=12){
return false;
}
switch(mes){
case 4:
case 6:
case 9:
case 11:
        if(dia<=30){
        return true;
        }else {return false;}
        
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
        if(dia<=31){
        return true;
        }else return false;

case 2:
if(esbiciesto(año)){
if(dia<=29){
return true;
}else{ return false;}
}else{
if(dia<=28){
return true;
}else {
    return false;
}
}
}
return false;//todos los caminos de la funcion deben tener un return sino salta error
}
int main(){
   int año, mes, dia;
cout << "Ingrese datos" << endl;
    cin>>año>>mes>>dia;
   
   bool valido= fechacom(año,mes,dia);
    cout <<"La fecha es "<< valido  << endl;

    return 0;
}