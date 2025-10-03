#include <iostream>
#include <fstream>
using namespace std;

struct Compras{
int id;
string cliente;
string producto;
int cantidad;
};
template<typename T>struct Nodo{
T dato;
Nodo<T>* sig;
};
int cliente=8;
int producto=10;
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
ostream& operator << (ostream &os, Compras& p)
{
	os << p.id << " con nombre" << p.cliente<<" y "<<p.cantidad<<"del producto"<<p.producto;
	return os;
}
fstream &operator>>(fstream &fs,Compras  &compra)
{
 fs.read(reinterpret_cast<char *>(&compra.id), sizeof(compra.id));
    compra.cliente = readstring(fs, cliente);
   
    compra.producto = readstring(fs, producto);
    fs.read(reinterpret_cast<char *>(&compra.cantidad), sizeof(compra.cantidad));
   
    return fs;
}
int criterio_cliente(Compras a, Compras b)
{
	return (a.name == b.name) ? criterioproduc(a,b) : (a.name > b.name);
}
int criterioproduct(Compras a, Compras b)
{
	return (a.producto < b.producto) ?-1 : a.promedio > b.promedio;
}
int criterioID(Compras a,Compras b){
return (a.id-b.id);

}
int criterioclipro(Compras a,Compras b){
return(a.cliente==b.cliente&&a.producto==b.producto)?0:1;

}
template <typename T>
void insertar(T valor, Nodo<T> *&lista, int (*criterio)(T, T))
{
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T> **pp = &lista;
	/* en tanto haya algo apuntado y el que quiero insertar sea posterior
	   al dato apuntado: avanzo*/
	while (*pp != nullptr && criterio(nuevo->dato, (*pp)->dato) >= 0)
		pp = &(*pp)->sig; // Equivalente a pp = &((*pp)->sig);
	nuevo->sig = *pp;	  // asigna nullptr si llegó al final de la lista
	*pp = nuevo;
}
template <typename T>void mostrar(Nodo<T>*lista){
while (lista != nullptr)
	{
		cout << lista->dato << endl;
		lista = lista->sig;
	}



}
template <typename T> Nodo<T>* buscar(T clave, Nodo<T>* lista, int (*criterio)(T, T))
{

	while (lista != nullptr && criterio(clave, lista->dato) > 0)
		lista = lista->sig;

	return lista != nullptr && criterio(clave, lista->dato) == 0 ? lista : nullptr;
}
template <typename T> bool borrar(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* extraido = extraer(clave, lista, criterio);
	if (extraido) {
		delete extraido;
		return true;
	} else {
		return false;
	}
}

template <typename T> Nodo<T>* extraer(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T> *aux;
	Nodo<T> **pp = &lista;

	while (*pp != nullptr && criterio(clave, (*pp)->dato) > 0)
		pp = &(*pp)->sig;

	if (*pp != nullptr && criterio(clave, (*pp)->dato) == 0) {
		aux = *pp; //guardo para poder retornarlo
		*pp = (*pp)->sig; //el que apunta al que quiero borrar, que apunte al siguiente
		return aux; //Para borrado directo delete aux; return true;
	} else {
		return nullptr; //Para borrado directo return false;
	}
}
Compras *busquedalineal(string cliente,string producto, int dim, Compras *vec, int &encontrados)
{
 encontrados = 0;
    int i;
    for (i = 0; i < dim; i++)
    {

        if (vec[i].cliente == cliente&&vec[i].producto==producto)
        {
            encontrados++;
        }
    }
    if (encontrados == 0)
    {

        return nullptr;
    }
    Compras *seleccionados = new Compras[encontrados];
    int j = 0;
    for (i= 0; i< dim; i++)
    {

        if (vec[i].cliente == cliente&&vec[i].producto==producto)
        {
            usuarios[j] = vec[i];
            j++;
        }
    }
    return seleccionados;
}

int main(){
fstream Archilec;
Archilec.open("archivos/datoos02.bin",ios::binary | ios::in);
Archilec.seekg(0, ios::end);
int bytes=Archilec.tellg();
int cantstruct=bytes/sizeof(Compras);
Compras* compra=new Compras[cantstruct];
Nodo<Compras>* lista=nullptr;
Nodo<Compras>* lista2=nullptr;
if(!Archilec){

    cout<<"error";
}
for(int i=0;i<cantstruct;i++){
Archilec<<compra[i];

}
for(int j=0;j<cantstruct;j++){
insertar(compra[j],lista,criterio_cliente);
insetar(compra[j],lista2,criterioID);
}
int ID;
cout<<"Ingrese el numero de id a buscar"<<end1;
Nodo<Compras>* str=nullptr;
while(cin>>ID && ID>=0){
str=buscar(ID,lista2,criterioID);
if(str!=nullptr){

    cout<<"El usuario encontrado es"<<str->dato<<end1;
}
else{
    cout<<"no se encontraron usuarios con ese ID";
}
cout<<"Ingrese el numero de id a buscar"<<end1;
}
string nombre;
string producto;
int encontrados=0;
while(cin>>nombre&&cin>>producto&&nombre!="Terminar"){
Compras* selec=busquedalineal(nombre,producto,compra,cantstruct,encontrados);
for(int i=0;i<encontrados;i++){
borrar(selec[i],lista,criterioclipro);
borrar(selec[i],lista2,criterioclipro);
}
}

}