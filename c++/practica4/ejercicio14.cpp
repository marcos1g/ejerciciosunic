
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int mayor(int vec[],int dim){
int max=vec[0];
int indi=0;
for(int i=1;i<dim;i++){
if(vec[i]>max){
    max=vec[i];
    indi=i;
}
}
return indi;
}
int main(){
    ifstream archilec;
    archilec.open("archivos/datos14.txt");
    int cant=9;
int autos[cant]{};
int datos;
while(archilec>>datos){
autos[datos-15]++;
}
for(int d;d<cant;d++){
      cout<<autos[d]<<endl;
}

int max=mayor(autos,cant);
cout<<"El vehiculo con mayor entregas es el"<<max+15<< "con un total de"<<autos[max]<<"entregas";
    return 0;
}
