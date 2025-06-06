#include<iostream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
 bool final=false;
bool fechacom(int año,int mes, int dia){
   
if(año >= 1800 && mes >=1 && mes <= 12){
switch (mes)
{
case 1:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 2:
bool a;
año%4==0&&(año%100!=0||año%400==0)?a=true:a=false;
if(a==true){
    if(dia>0 && dia<=29){
        final=true;
    }final=false;
}else if(a==false){
    if(dia>0 && dia<=28){
        final=true;
    }final=false;
}
    /* code */
    break;
case 3:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 4:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 5:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
    
case 6:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 7:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;

case 8:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 9:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
case 10:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;

case 11:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
    case 12:
if(dia>0 && dia<=30)
final=true;
    /* code */
    break;
}

}
return final;
}
int main(){
   int año, mes, dia;
cout << "Ingrese datos" << endl;
    cin>>año>>mes>>dia;
   
   bool valido= fechacom(año,mes,dia);
    cout <<"La fecha es "<< valido  << endl;

    return 0;
}