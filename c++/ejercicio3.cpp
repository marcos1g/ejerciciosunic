#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
string fechacom(int Fecha){
int Año=Fecha/10000;//Le quita los ultimos 4 digitos
int mes=(Fecha/100)%100;
int dia=Fecha%100 ;
string AñoF=to_string(Año);
string MesF=to_string(mes);
string DiaF=to_string(dia);
string final4=DiaF+"/"+MesF+"/"+AñoF;

return final4;
}
int main(){
    string fecha;
int fecha1;
   cout << "Ingrese una fecha con formato aaaa/mm/dd" << endl;
    cin>>fecha1;
   string final= fechacom(fecha1);
    cout <<"La fecha es de "<< final  << endl;

    return 0;
}