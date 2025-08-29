
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void ordenamiento(int destino[],int partida, string nombresP[]){
    int momen;
    string moment;
for(int i=0;i<partida;i++){
int base=i;
for(int j=base;j<partida;j++){
    if(destino[j]<destino[base]){
    base=j;
}
momen=destino[i];
destino[i]=destino[base];
destino[base]=momen;
moment=nombresP[i];
nombresP[i]=nombresP[base];
nombresP[base]=moment;


}
}
}
int menortiempo(int viajes[][8],float minimo){
    const int llegada=8;
    int minimo=viajes[minimo][0];
    int indice=0;
for(int i=1;i<llegada;i++){
    if(viajes[minimo][i]<minimo){
    minimo=viajes[minimo][i];
    indice=i;
}
}
return indice;

}

int main(){
  
ifstream archilec;
archilec.open("archivos/parciales2");
int partida=8;
int llegada=8;
string nombresP[partida]={"partida1","partida2","partida3","partida4","partida5","partida6","partida7","partida8"};
string nombresL[llegada]={"llegada1","llegada2","llegada3","llegada4","llegada5","llegada6","llegada7","llegada8",}
int viajes[partida][llegada];
int peso[partida][llegada];
int totales[partida][llegada];
int inicio,final;
int dim=4;
int vec[dim]={3,5,2,1};
float promedio[dim-1]{};
float tiempo,kilos;
int destino[partida]{};
while(archilec>>inicio>>final>>tiempo>>kilos){
viajes[inicio][final]+=tiempo;
totales[inicio][final]++;
peso[inicio][final]+=kilos;
}
//punto1
for(int i=0;i<dim-1;i++){
promedio[i]=totales[vec[i]][vec[i+1]]>0?viajes[vec[i]][vec[i+1]]/totales[vec[i]][vec[i+1]]:0;
}
for(int j=0;j<dim-1;j++){
cout<<"El tiempo promedio de recorrido de el sitio"<<vec[j]<<"hasta"<<vec[j+1]<<"es igual a"<<promedio[j]<<end1;
}
//punto2
float minimo=vec[dim];
int menordist=menortiempo(viajes,minimo);
cout<<"A el destino con menor tiempo que se llega desde "<<minimo<<"es"<<menordist<<"con un tiempo de"<<viajes[minimo][menordist];
//punto3
for(int i=0;i<partida;i++){
for(int j=0;j<llegada;i++){
destino[i]=peso[i][j];
}
}
ordenamiento(destino,partida,nombresP);
for(int o=0;o<partida;o++){
if(destino[o]>9500){
    cout<<"Partida"<<nombresP[o]<<"con un peso total de "<<destino[o]<<end1;
}
}
    return 0;
}