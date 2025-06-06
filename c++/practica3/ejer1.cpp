#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int num;
    int contador;
    float total=0;
    float promedio;
 ifstream archiesc; //ouput file stream: para escritura
 archiesc.open("Archivo.txt");
 if (!archiesc) {
 cout << "Error al abrir el archivo" << endl;
 return 1;
 }
 while(archiesc>>num){
total=total+num;
cout << num << endl;
contador++;
 }
 promedio=total/contador;
 cout << "La cantidad de numeros subidos son "<<contador << "su sumatoria es "<< total<< "y su promedio es de "<< promedio<< endl;

 archiesc.close();
 return 0;
}