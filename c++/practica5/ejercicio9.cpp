#include <iostream>

#include <fstream>
using namespace std;

struct Nodo
{
	int dato;  // valor que contiene el nodo
	Nodo *sig; // puntero al siguiente nodo
};

template <typename T>
void push(Nodo *&pila, T valor)
{
	Nodo *nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(Nodo *&pila)
{
	int valor = pila->dato;
	Nodo *aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

template <typename T>
void agregar(Nodo *&cola, T valor)
{
	Nodo *nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr)
	{
		cola = nuevo;
	}
	else
	{
		Nodo *aux = cola;
		while (aux->sig != nullptr) // mientras que no sea el último
			aux = aux->sig;			// avanzo al siguiente
		aux->sig = nuevo;
	}
}

// ============ ENTEROS
int criterio_int(int a, int b)
{
	return a - b;
}

// ============ STRING
int criterio_str(string a, string b)
{
	return (a < b) ? -1 : (a > b);
}

template <typename T>
void mostrar(Nodo *lista)
{
	while (lista != nullptr)
	{
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T>
bool buscar_lineal(T clave, Nodo *lista, int (*criterio)(T, T))
{
	while (lista != nullptr)
	{
		if (criterio(lista->dato, clave) == 0)
			return true;
		lista = lista->sig;
	}
	return false;
}
Nodo *concatenacion(Nodo *pila, Nodo *pila2)
{
	Nodo *pilafinal = nullptr;
	while (pila != nullptr)
	{
		if (pila != nullptr)
		{
			push(pilafinal, pop(pila))
		}
	}
}

int main()
{
	string nose;
	Nodo *pila = nullptr;
	Nodo *pila2 = nullptr;
	cout << "palabra";
	cin >> nose;
	push(pila, 43);
	push(pila, 3);
	push(pila, 73);
	push(pila, 92);
	push(pila, 2);
	push(pila2, 43);
	push(pila2, 3);
	push(pila2, 73);
	push(pila2, 92);
	push(pila2, 2);

	int final = mayor(pila);
	cout << "el mayor es " << final;
	while (pila != nullptr)
	{
		pop(pila);
	}

	/*
	push(pila, 1);
	push(pila, 2);
	push(pila, 3);
	cout << "Pila (1 2 3)" << endl;
	mostrar(pila);
	cout << endl << "Eliminamos" << endl;
	while (pila != nullptr)
		cout << pop(pila) << endl;
	cout << endl << "Confirmamos pila vacía:" << endl;
	mostrar(pila);
	cout << "fin mostrar pila" << endl;

	Nodo<string> *cola = nullptr;
	/* En la sentencia siguiente, si no especifico <string> da error
	  no matching function for call to
	  agregar(Nodo<std::__cxx11::basic_string<char> >*&, const char [4]
	  Esto se debe a que los literales cadena no son string sino arreglo
	  de caracteres
	agregar<string>(cola, "uno");
	agregar(cola, "dos"s); //Esta alternativa válida de C++14 en adelante
	agregar(cola, string("tres")); //Otra es construir un string
	cout << endl << "Cola (uno dos tres)" << endl;
	mostrar(cola);
	cout << endl << "Eliminamos" << endl;
	while (cola != nullptr)
		cout << pop(cola) << endl;
	cout << endl << "Confirmamos cola vacía:" << endl;
	mostrar(cola);
	cout << "fin mostrar cola" << endl;

	agregar<string>(cola, "Juan");
	agregar(cola, "Pedro"s);
	agregar(cola, string("María"));
	cout << endl << "Datos" << endl;
	mostrar(cola);
	string nombre;
	cout << endl << "Ingrese el nombre a buscar: ";
	while (cin >> nombre) {
		if (buscar_lineal(nombre, cola, criterio_str))
			cout << nombre << " SI está en la lista" << endl;
		else
			cout << nombre << " NO está en la lista" << endl;
		cout << "Ingrese el nombre a buscar: ";
	}/**/
	return 0;
}
