#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int num;
    int minimo;
    int contador=0;
    streampos pos;
 ifstream archilec; //input file stream: para lectura
 archilec.open("Archivo.txt");
 if (!archilec) {
 cout << "Error al abrir el archivo" << endl;
 return 1;
 }
while(archilec>>num){
    contador++;
    if(contador==1){
    minimo=num;}
if(num<minimo){
    minimo=num;
pos=archilec.tellg();
}
}
cout << "El numero mas chico es "<<minimo << "y esta en la posicion"<<pos << endl;//el tellg devuelve -1 si la posicion es en al final del archivo
 archilec.close();
 return 0;
}