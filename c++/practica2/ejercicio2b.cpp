#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
string fechacom(string Fecha){
Fecha.erase(std::remove(Fecha.begin(),Fecha.end(),'/'),Fecha.end());
return Fecha;
}
int main(){
    string fecha;
string fecha1;
   cout << "Ingrese una fecha con formato aaaa/mm/dd" << endl;
    cin>>fecha1;
   string final= fechacom(fecha1);
    cout <<"La fecha es de "<< final  << endl;

    return 0;
}