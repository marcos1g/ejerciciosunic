#include<iostream>
using namespace std;
string fecha(int año,int mes, int dia){
string año1=to_string(año);
string mes1=to_string(mes);
string dia1=to_string(dia);
string final=año1+"/"+mes1+"/"+dia1;
return final;
}
int main(){
    int año,mes,dia;

   cout << "Ingrese una fecha" << endl;
    cin>>año>>mes>>dia;
   string final= fecha(año, mes,dia);
    cout <<"La fecha es de "<< final  << endl;

    return 0;
}