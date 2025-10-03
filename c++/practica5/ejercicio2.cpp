#include <iostream>
#include <fstream>
using namespace std;
struct Nodo
{
    int valor;
    Nodo *sig;
};

void push(Nodo *&lista, int num)
{
    Nodo *nuevo = new Nodo;
    nuevo->valor = num;
    nuevo->sig = lista;
    lista = nuevo;
}
int pop(Nodo *&lista)
{
    int numero = lista->valor;
    Nodo *auxiliar = lista;
    lista = lista->sig;
    delete auxiliar;
    return numero;
}
void agregar(Nodo *&lista, int num)
{
    Nodo *nuevo = new Nodo;
    nuevo->valor = num;
    nuevo->sig = nullptr;
    if (lista == nullptr)
    {
        lista = nuevo;
    }
    else
    {
        while (lista != nullptr)
        {
            lista = lista->sig;
        }
        lista->sig = nuevo;
    }
}
void mostrar(Nodo *lista)
{
    while (lista != nullptr)
    {

        cout << lista->valor << " ";
        lista = lista->sig;
    }

    cout << "Fin de la lista";
}
void invertir(Nodo *&lista)
{
    if (lista != nullptr && lista->sig != nullptr)
    {
        int val1 = pop(lista);
        int val2 = pop(lista);
        push(lista, val1);
        push(lista, val2);
    }
    else
    {

        cout << "No hay suficientes elementos en la lista para hacer la intercalacion";
    }
}
int main()
{
    Nodo *lista = nullptr;
    push(lista, 89);

    mostrar(lista);
    invertir(lista);
    mostrar(lista);
    while (lista != nullptr)
    {
        pop(lista);
    }
    return 0;
}