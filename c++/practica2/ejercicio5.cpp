#include<iostream>

using namespace std;
int fechacom(int F){
int total;
for(int i=0;i<F+1;i++){
total+=i;
}
return total;
}
int main(){
    int numero;
   cout << "Ingrese el numero al que quiere calcaular la sumatoria de GAUSS " << endl;
    cin>>numero;
   int final= fechacom(numero);
    cout <<"La ∑ de "<< numero << "es de "<< final<< endl;
    return 0;
}