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

        cout << lista->valor << "";
        lista = lista->sig;
    }

    cout << "Fin de la lista";
}
void duplicar(Nodo *&lista)
{
    if (lista != nullptr)
    {
        int valor1 = pop(lista);
        push(lista, valor1);
        push(lista, valor1);
    }
}
int main()
{
    Nodo *lista = nullptr;
    push(lista, 89);
    push(lista, 69);
    push(lista, 76);
    push(lista, 5);
    push(lista, 10);
    mostrar(lista);
    duplicar(lista);
    mostrar(lista);
    while (lista != nullptr)
    {
        pop(lista);
    }
    return 0;
}
