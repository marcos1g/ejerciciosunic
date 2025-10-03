#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
struct Nodo
{
	T dato;		  // valor que contiene el nodo
	Nodo<T> *sig; // puntero al siguiente nodo
};

struct Alumno
{

	string name;
	int legajo;
	double promedio;
};
ostream& operator << (ostream &os, Alumno& p)
{
	os << p.name << " con legajo " << p.legajo<<"y promedio"<<p.promedio;
	return os;
}
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
int criterio_nombre(Alumno a, Alumno b)
{
	return (a.name < b.name) ? -1 : (a.name > b.name);
}
int criterio_promedio(Alumno a, Alumno b)
{
	return (a.promedio == b.promedio) ? criterio_nombre(a, b) : a.promedio - b.promedio;
}

// ============ STRING

template <typename T>
void insertar(T valor, Nodo<T> *&lista, int (*criterio)(T, T))
{
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T> **pp = &lista;
	/* en tanto haya algo apuntado y el que quiero insertar sea posterior
	   al dato apuntado: avanzo*/
	while (*pp != nullptr && criterio(nuevo->dato, (*pp)->dato) <= 0)
		pp = &(*pp)->sig; // Equivalente a pp = &((*pp)->sig);
	nuevo->sig = *pp;	  // asigna nullptr si llegó al final de la lista
	*pp = nuevo;
}
template <typename T>
void mostrar(T baja[], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		cout << baja[i].name;
		cout << baja[i].legajo ;
		cout << baja[i].promedio ;
	}
}
int criterioextraer(Alumno alu,Alumno alu2){
if(alu.name==alu2.name&&alu.legajo==alu2.legajo&&alu.promedio==alu2.promedio)
{
return 1;
}else{

	return 0;
}
}
template <typename T>
Nodo<T> *extraer(T clave, Nodo<T> *&lista,int (*criterio)(T, T))
{
	Nodo<T> *aux;
	Nodo<T> **pp = &lista;

	while (*pp != nullptr && criterio(clave,(*pp)->dato)>0)
		pp = &(*pp)->sig;

	if (*pp != nullptr && criterio(clave,(*pp)->dato)==0)
	{
		aux = *pp;		  // guardo para poder retornarlo
		*pp = (*pp)->sig; // el que apunta al que quiero borrar, que apunte al siguiente
		return aux;		  // Para borrado directo delete aux; return true;
	}
	else
	{
		return nullptr; // Para borrado directo return false;
	}
}
void mostrarlista(Nodo<Alumno> *lista)
{
	while (lista != nullptr)
	{
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}
int main()
{
	int dim = 9;
	int dim2 = 3;
	Alumno presentes[dim]{"Maria", 721, 8.4, "Pedro", 847, 7.2, "Ana", 614, 9.1, "Jose", 578, 8.9, "Juan", 927, 8.4, "Unai", 325, 8.1, "Ramon", 418, 8.4, "Elaia", 892, 9.6, "Carlos", 733, 8.5};
	Alumno baja[dim2]{"Pedro", 847, 7.2, "Ramon", 418, 8.4, "Unai", 325, 8.1};
	Nodo<Alumno> *pila = nullptr;
	for (int i = 0; i < dim; i++)
	{

		insertar(presentes[i], pila, criterio_promedio);
	}
	mostrarlista(pila);

	mostrar(baja, dim2);
	for (int j = 0; j < dim2; j++)
	{
		extraer(baja[j], pila,criterioextraer);
	}
	mostrarlista(pila);
	while(pila!=nullptr){

		pop(pila);
	}
}
