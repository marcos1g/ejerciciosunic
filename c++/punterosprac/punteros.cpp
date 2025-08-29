#include <iostream>
#include <fstream>
#include <random>
using namespace std;
random_device rd;   // fuente de entropía
mt19937 gen(rd());
void saludodia(){
 cout << "Buenos dias" << endl;
}
void saludonoche(){
 cout << "Buenos noches"<< endl;

}
bool esdia(){
uniform_int_distribution<> distt2(1, 2);
int num=distt2(gen);
if(num==2){

  return true;
}
else{
  return false;
}
}
void mostrar(int vec[],int dim){
 cout << "Algunos pares del numero elegido son:" << endl;
for(int i=0;i<dim;i++){

   cout<<vec[i]<<";"<< endl;
}

}
 
int main(){
int var;
int var2;
cout << "ingrese la cantidad de elementos de su array" << endl;
cin>>var2;
cout << "ingrese num para sus multiplos" << endl;
 cin>>var;
  
int *vec=new int[var2];//nuestra variable *vec guarda la primer direccion de memoria de un espacio reservado para un array de tipo int 
  // generador Mersenne Twister
    uniform_int_distribution<> distt(0, 10); // rango [0,9]

for(int i=0;i<var2;i++){
    int num = distt(gen);
    vec[i]=var*num;
   }
mostrar(vec,var2);
delete [] vec;
 bool dia=esdia();
void (*saludo)(void);//Puntero a las funciones de este tipo es decir de tipo void que no reciben ningun parametro
if(dia){
saludo=saludodia;
}
else{
  saludo=saludonoche;
}
saludo();
return 0;
}