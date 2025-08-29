#include <iostream>
#include <fstream>

using namespace std;
int observadas(int cantproducts[],int product){
int total=0;
for(int i=1;i<product-1;i++){
if(cantproducts[i]>cantproducts[i-1]&&cantproducts[i]<(0.9)*(cantproducts[i+1]))
total++;
}
return total;
}
int main()
{
    int codproducto=6;
    int codsucursal=8;
    int cantidad,peso;
    int cantproducts[codproducto];
    int cantidadgeneral[codproducto][codsucursal];
    int pesogeneral[codproducto][codsucursal];
    int entregados[codproducto];
    ifstream archilec;
    archilec.open("archivo.txt");
    int produc,sucursal,cantidad,peso;
    
    while(archilec>>produc>>sucursal>>cantidad>>peso){
    cantproducts[sucursal]+=cantidad;
    cantidadgeneral[produc][sucursal]+=cantidad;
    pesogeneral[produc][sucursal]+=peso;
    }
    int cant=observadas(cantproducts,codproducto);
//punto 3
for(int i=0;i<codproducto;i++){
for(int j=0; j<codsucursal;j++){

entregados[i]+=pesogeneral[i][j]/cantidadgeneral[i][j];
}

}


    return 0;
}