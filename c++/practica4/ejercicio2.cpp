#include <iostream>
#include <fstream>
using namespace std;
double promedio(double vec[],int dim, int max){
    int cantidad=0;
    double promedio=0;
    double sum=0;
    for (int i = 0; i < dim; ++i){
        if(vec[i]>max){
            cantidad++;
            sum+=vec[i];
        }
    }
    promedio=sum/cantidad;
    return cantidad>0?promedio:0;//devuelve nan pero al ser doubule no hace falta aclararlo
}
int main(){
    int pos=0;
    int max=8;
    const int dim=5;
    double vec[dim]{};
    double numero;
    ifstream archilec; //input file stream: para lectura
    archilec.open("archivos/numeros.txt");
    if (!archilec) {
        return 1;
 }
    while(archilec>>numero){
        vec[pos] = numero;
        pos++;
}
archilec.close();
double prom=promedio(vec,dim,max);
cout<<"El promedio es "<<prom<<endl;

    return 0;
}