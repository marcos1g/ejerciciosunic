#include <iostream>
#include <fstream>
using namespace std;
int main()
{
int num;
streampos pos;
 ifstream archilec; //input file stream: para lectura
 ofstream archilec2, archilec3; 
 archilec.open("Archivo.txt");
 archilec2.open("Archivo2.txt");
 archilec3.open("Archivo3.txt");
 if (!archilec) {
 cout << "Error al abrir el archivo" << endl;
 return 1;
 }
 while(archilec>>num){
if(num%2==0){
 archilec2<< num << endl;
}else {
    archilec3 <<num<< endl;
}}
archilec.close();
archilec2.close();
archilec3.close();
return 0;
}