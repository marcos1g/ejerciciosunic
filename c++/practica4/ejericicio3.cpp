#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int alumnos(double prom,double vec[],int dim){
    int cant=0;
     for (int i = 0; i < dim; ++i){
      if (vec[i]>prom)
      {
          cant++;
      } 
    }
return cant;
}
double promedio(double vec[],int dim){
    double sum=0;
 for (int i = 0; i < dim; ++i){
      sum+=vec[i];
    }
return sum/dim;
}
int main(){
    ifstream archilec;
    double num;
    int pos=0;
    archilec.open("archivos/datos3.txt");
    int dim=5;
    double vec[dim]{};
    while (archilec>>num)
    {
        vec[pos]=num;
        pos++;
    }
    archilec.close();
    double prom=promedio(vec,dim);
    cout<<"El promedio de notas de los esudiantes es de"<<prom<<endl;

    int canti=alumnos(prom,vec,dim);
    cout<<"La cantidad de alumnos por encima del promedio son: "<<canti<<endl;

    return 0;

}