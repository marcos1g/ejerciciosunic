#include <iostream>
#include <fstream>
using namespace std;
int primerminimo(int vector[],int dim){
    int minimo=vector[0];
    int pos=0;
for(int i=1;i<dim;i++){
if(vector[i]<minimo){
minimo=vector[i];
pos=i;
}
}
return pos;
}
int ultimominimo(int vector[],int dim){
 int minimo=vector[0];
    int pos=0;
for(int i=1;i<dim;i++){
if(vector[i]<=minimo){
minimo=vector[i];
pos=i;
}
}
return pos;
}
int repetidas(int vector[],int dim, int primer){
int minimo=vector[primer];
    int cont=0;
    for(int i=0;i<dim;i++){
        if(vector[i]==minimo){
            cont++;
        }
    }
    return cont;
}

int main(){
     int dim=10;
    int vec[dim]{12,43,45,78,3,45,3,67,8,78};
   int primermin=primerminimo(vec,dim);
   int ultimomin=ultimominimo(vec,dim);
   int repetidas2=repetidas(vec,dim,primermin);
   cout<<"La posicion del primer minimo es "<< primermin<<"y la posicion del segundo minimo es "<<ultimomin<<", este minimo re repite "<<repetidas2<<"veces"<<endl;
  cout<<vec[primermin];

    return 0;
}