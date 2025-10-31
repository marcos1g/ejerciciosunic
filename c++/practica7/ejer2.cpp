#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
struct Nodo
{
	T dato;
	Nodo<T> *sig; /* data */
};
struct Registros
{
	string ciudad;
	string modelo;
	int cantidad;
	/* data */
};
struct Venta
{
	string modelo;
	int cantidad;
};
struct Ciudad
{
	string ciudad;
	int ventregis = 0;
	int venttotal = 0;
	Nodo<Venta> *venta=nullptr;
};

const int Longciudad = 12;
const int Longmodelo = 10;

template <typename T>
T pop(Nodo<T> *&pila)
{
	if (pila == nullptr)
	{
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		// modo no recomendado de terminar, en particular si uso objetos
	}
	T valor = pila->dato;
	Nodo<T> *aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}
template <typename T>
void mostrar(Nodo<T> *lista)
{ // Presupone que de ser neceario se hizo la sobrecarga de << para dato
	while (lista != nullptr)
	{
		std::cout << lista->dato << std::endl;
		lista = lista->sig;
	}
}

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
ostream &operator<<(ostream &os, Ciudad &p)
{
	os << p.ciudad << " con una cantidad de " << p.ventregis << "registros y de" << p.venttotal << "de ventas";
	return os;
}
ostream &operator<<(ostream &os, Venta &p)
{
	os << p.modelo << " con una cantidad de " << p.cantidad ;
	return os;
}
fstream &operator>>(fstream &fs, Registros &venta)
{
	venta.ciudad = readstring(fs, Longciudad);
	venta.modelo = readstring(fs, Longmodelo);

	fs.read(reinterpret_cast<char *>(&venta.cantidad), sizeof(venta.cantidad));

	return fs;
}

int criterioigual(Ciudad ciudad1, Ciudad ciudad2)
{
	return ciudad1.ciudad.compare(ciudad2.ciudad);
}


template <typename T>
Nodo<T> *insertar_unico(T valor, Nodo<T> *&lista, int criterio(T, T))
{
	Nodo<T> **pp = &lista;
	while (*pp != nullptr && criterio(valor, (*pp)->dato) > 0)
		pp = &(*pp)->sig;
	if (*pp != nullptr && criterio(valor, (*pp)->dato) == 0)
	{

		return *pp; // devuelvo el que ya estaba y acabo de encontrar
	}
	else
	{
		Nodo<T> *nuevo = new Nodo<T>; // Genero nodo
		nuevo->dato = valor;		  // y guardo el valor
		// Ahora lo inserto en su lugar
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	}
}
template <typename T>
Nodo<T>*buscar_lno(T clave, Nodo<T> *lista, int (*criterio)(T, T))
{
	while (lista != nullptr)
	{
		if (criterio(lista->dato, clave) == 0)
			return lista;
		lista = lista->sig;
	}
	return nullptr;
}
template <typename T> void agregar(Nodo<T>*& cola, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	Nodo<T>** pp = &cola;
	while (*pp != nullptr) //avanzo hasta el que no tiene siguiente
		pp = &(*pp)->sig;
	*pp = nuevo; // atrás del último, agrego el nuevo
}
int main()
{
	fstream Archilec;
	Archilec.open("archivos/datos02.bin", ios::binary | ios::in);

	Nodo<Ciudad> *lista = nullptr;

	if (!Archilec)
	{
		cout << "Hubo un error";
	}
	Registros registro;
	registro.cantidad = 0;
	Venta venta;
	Ciudad ciudad;
	Nodo<Ciudad> *final2;

	while (Archilec >> registro)
	{
		ciudad.ciudad = registro.ciudad;
		final2 = insertar_unico(ciudad, lista, criterioigual);
		final2->dato.ventregis++;
		final2->dato.venttotal += registro.cantidad;
		venta.modelo = registro.modelo;
		venta.cantidad = registro.cantidad;
		agregar(final2->dato.venta, venta);
	}
	cout << "Listado de las ciudades de manera acendente" << endl; // punto1
	mostrar(lista);

	cout << "Escribir nombre de la ciudad"; // punto2
	Ciudad Ciudadencon;
	Nodo<Ciudad> *resultado;
	while (cin >> Ciudadencon.ciudad && Ciudadencon.ciudad != "EOF")
	{
		resultado = buscar_lno(Ciudadencon, lista, criterioigual);
		if (resultado != nullptr)
		{
			cout << "La ciudad es " << resultado->dato.ciudad;
			mostrar(resultado->dato.venta);
		}else{

cout << "Mo hay resultado de la abusqueda"; 

		}
		cout << "Escribir nombre de la ciudad"; 
	}

	cout << "Escribir el nombre de la ciudad a buscar" <<endl;
	cin.clear();
	int minimo;
	while (cin >> Ciudadencon.ciudad && cin >> minimo)
	{
		resultado = buscar_lno(Ciudadencon, lista, criterioigual);
		int contador = 0;
		if (resultado != nullptr)
		{
			Nodo<Venta> *ventas = resultado->dato.venta;
			while (ventas)
			{
				if (ventas->dato.cantidad > minimo)
				{
					contador++;
				}
				ventas = ventas->sig;
			}
			cout << "La cantidad de ventas que superaron la cantidad minima en " << Ciudadencon.ciudad << "son" << contador;
		}
		else{

			cout<<"No se encontraron ciudades" <<endl;
		}
		
	}
	while (lista != nullptr)
	{

		pop(lista);
	}
}