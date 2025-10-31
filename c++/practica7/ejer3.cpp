#include <iostream>
#include <fstream>
#include "listas.hpp"
using namespace std;

struct Registros
{
	string ciudad;
	string producto;
	string Medpago;
	int cantidad;
	float monto;
};
const int Longciudad = 10;
const int Longproducto = 18;
const int LongMedpago = 2;
struct Producto
{
	string producto;
	int montvend=0;
	int totalvent=0;
	int MP[4] = {0, 0, 0, 0};
};
struct Ciudad
{
	string ciudad;
	int cantprod=0;
	int unidvend=0;
	Nodo<Producto> *produc = nullptr;
};

int critciu(Ciudad a, Ciudad b)
{
	return a.ciudad.compare(b.ciudad);
}

//por producto ascendente
int critprod(Producto a, Producto b)
{
	return a.producto.compare(b.producto);
}
const int Medpagolong{4};
int MedPagoTotal[Medpagolong]{};
string Medpago[Medpagolong] = {"BV", "EF", "TC", "TD"};
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
	os << p.ciudad << "   Productos diferentes:" << p.cantprod << "   cantidad de unidades: " << p.unidvend ;
	return os;
}
ostream &operator<<(ostream &os, Producto &p)
{
	os << p.producto << "    " << p.montvend << "     " << p.totalvent<<"  " ; 
	for (int i {}; i < Medpagolong; ++i)
		os << p.MP[i] << "\t";;
	return os;
}
fstream &operator>>(fstream &fs, Registros &regis)
{
	regis.ciudad = readstring(fs, Longciudad);
	regis.producto = readstring(fs, Longproducto);
	regis.Medpago = readstring(fs, LongMedpago);

	fs.read(reinterpret_cast<char *>(&regis.cantidad), sizeof(regis.cantidad));
	fs.read(reinterpret_cast<char *>(&regis.monto), sizeof(regis.monto));

	return fs;
}
template <typename T>
int buscar_lineal_ord(T clave, T vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] < clave; i++)
		;
	return (i < dim && vec[i] == clave) ? i : -1;
}

int indice(string codigo)
{
	// Precondición, el codigo que nos pasan es uno de los posibles
	int idx = buscar_lineal_ord(codigo, Medpago, Medpagolong);
	assert(idx >= 0);
	return idx;
}
template <typename T>
void listar(Nodo<T> *lista)
{
	while (lista != nullptr)
	{
		cout << lista->dato<<endl;
		mostrar(lista->dato.produc);
		lista = lista->sig;
	}
}
template <typename T>
void sumarMP(Nodo<T> *lista, int MP[], int dim)
{
	while (lista != nullptr)
	{
		for (int i = 0; i < dim; i++)
		{
			MP[i] += lista->dato.MP[i];
		}

		lista = lista->sig;
	}
}
template <typename T>
int Ventasypago(Nodo<T> *lista, T dato)
{
	int total = 0;
	int ind = indice(dato.Medpago);
	Nodo<Producto>*productZ;
	while (lista != nullptr)
	{
		if (lista->dato.producto == dato.roducto)
		{
			productZ=buscar(dato,lista->dato.product,critprod);
			if(productZ!=nullptr){

				total+=productZ->dato.MP[ind];
			}
		}

		lista = lista->sig;
	}
	return total;
}
int producto_medio(Nodo<Ciudad> *lista, Producto prod, string medio_cod)
{
	int idx = indice(medio_cod);
	int vtas {};
	while (lista != nullptr) {
		Nodo<Producto> *lisprod = buscar(prod, lista->dato.produc, critprod);
		if (lisprod != nullptr)
			vtas += lisprod->dato.MP[idx];
		lista = lista->sig;
	}
	return vtas;
}



int main()
{
	fstream Archilec;
	Archilec.open("archivos/datos03.bin", ios::binary | ios::in);
	Nodo<Ciudad> *lista = nullptr;
	Nodo<Ciudad> *resultado;
	Nodo<Producto> *result2;

	Ciudad ciudad1;
	Producto product;
	Registros regis;
	regis.cantidad = 0;

	if (!Archilec)
	{
		cout << "Se produjo un error";
	}
	while (Archilec >> regis)
	{ // punto1
		ciudad1.ciudad = regis.ciudad;
		resultado = insertar_unico(ciudad1, lista, critciu);
		
		resultado->dato.unidvend += regis.cantidad;
		product.producto = regis.producto;
		result2 = insertar_unico(product, resultado->dato.produc, critprod);
		if (result2->dato.totalvent == 0){
			resultado->dato.cantprod++;
		}
		result2->dato.montvend += regis.monto;
		result2->dato.totalvent++;
		result2->dato.MP[indice(regis.Medpago)]++;
	}
	listar(lista); // punto2
	
	while (lista != nullptr)
	{
		sumarMP(lista->dato.produc, MedPagoTotal, Medpagolong);
		lista = lista->sig;
	}
	cout << "Los pagos por villeteras virtuales fueron los siguiente" <<endl;
	for (int i = 0; i < Medpagolong; i++)
	{

		cout << MedPagoTotal[i] << "con la villetera virtual" << Medpago[i];
	}
 // punto3
	int MedPagoproducto[Medpagolong]{};
	
	int total;
	string mp;
	cout << "Ingrese el nombre de el producto";
	if (getline(cin, product.producto))
	{

		cout << "Ingrese el codigo de el medio de pago";
		while (cin >> mp)
		{
			total=producto_medio(lista, product, mp);
			cout<<"El total de ventas de el producto"<<product.producto<<"con el medio de pago"<<mp<<"es de "<<total;
			cout << "Ingrese el nombre de el producto";
			if (getline(cin, product.producto))
			{

				cout << "Ingrese el codigo de el medio de pago";
			}

	}
}
}