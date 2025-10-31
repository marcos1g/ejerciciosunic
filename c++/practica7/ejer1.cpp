#include <iostream>
#include <fstream>
using namespace std;
template<typename T>struct Nodo{
T dato;
Nodo<T>* sig;
};
struct Venta{
string modelo;
int cantvend;

};
template <typename T> T pop(Nodo<T>* &pila)
{
	if (pila == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		//modo no recomendado de terminar, en particular si uso objetos
	}
	T valor = pila->dato;
	Nodo<T>* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}
template <typename T> void mostrar(Nodo<T>* lista)
{ //Presupone que de ser neceario se hizo la sobrecarga de << para dato
	while (lista != nullptr) {
		std::cout << lista->dato << std::endl;
		lista = lista->sig;
	}
}
const int Longmodelo=10;
string readstring(fstream &fs, int largo)
{
    // char buffer[largo + 1];
    char *buffer = new char[largo + 1];
    buffer[largo] = '\0';
    fs.read(buffer, largo);
    string str(buffer);
    delete[] buffer;
    return str;
}
ostream& operator << (ostream &os, Venta& p)
{
	os << p.modelo << " con una cantidad de " << p.cantvend;
	return os;
}
fstream &operator>>(fstream &fs,Venta  &venta)
{

    venta.modelo = readstring(fs, Longmodelo);
   
   
    fs.read(reinterpret_cast<char *>(&venta.cantvend), sizeof(venta.cantvend));
   
    return fs;
}

template<typename T>int criterioigual(T venta1,T venta2){
if(venta1.modelo==venta2.modelo){
    return 0;
}else{
    return  1;
}


}
template <typename T> Nodo<T>* insertar_unico(T valor, Nodo<T>*& lista, int criterio(T, T))
{
	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(valor, (*pp)->dato) > 0)
		pp = &(*pp)->sig;
	if (*pp != nullptr && criterio(valor, (*pp)->dato) == 0) {
		(**pp).dato.cantvend+=valor.cantvend;
        return *pp; //devuelvo el que ya estaba y acabo de encontrar
	} else {
		Nodo<T>* nuevo = new Nodo<T>; //Genero nodo
		nuevo->dato = valor; // y guardo el valor
		//Ahora lo inserto en su lugar
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	}
}

int main(){
fstream Archilec;
Archilec.open("archivos/datos01.bin",ios::binary|ios::in);
if(!Archilec){
    cout<<"hubo un error";
}
Nodo<Venta>* pila=nullptr;
Venta Ventanormal;
Ventanormal.cantvend=0;
while(Archilec>>Ventanormal){
insertar_unico(Ventanormal,pila,criterioigual);


}
mostrar(pila);
while(pila!=nullptr){

		pop(pila);
	}
}