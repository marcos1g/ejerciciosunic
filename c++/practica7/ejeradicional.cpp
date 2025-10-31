#include <fstream>
#include <iostream>
using namespace std;
template<typename T>struct Nodo{
T dato;
Nodo<T>* sig;
};
struct Pedidos{
int ID;
string Zona;
string prodcuto;
int cantidad;
};
const int Longzona=10;
const int Longproduc=15;
struct Productos{
string producto;
int cantidad;
};
struct Representante{
int ID;
string Zona;
int pedidos;
int cantidad;
Nodo<Pedidos>*=nullptr;
};

int main(){
fstream Archilec;
Archilec.open("archivos/datos",ios::binary|ios::in);
if (!Archilec){
cout<<"hubo un error";
}
Nodo<Representante>*=nullptr;
Nodo<Representante> reprefinal;
Pedidos pedido;
pedido.cantidad=0;
while(Archilec>>pedido){
Representante repre;
repre.ID=pedido.ID;
repre.Zona=pedido.Zona;



}




};