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
        Nodo *aux = lista;
        while (aux != nullptr)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
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
void rotar(Nodo *&lista)
{
    int i = 0;
    Nodo *aux = lista;
    while (aux != nullptr)
    {
        aux = aux->sig;
        i++;
    }
    if (i >= 3)
    {
        int val1 = pop(lista);
        int val2 = pop(lista);
        int val3 = pop(lista);
        push(lista, val1);
        push(lista, val2);
        push(lista, val3);
    }
    else
    {
        cout << "la cantidad de elementos es insuficiente la lista queda inalterada";
    }
}
int main()
{
    Nodo *lista = nullptr;
    push(lista, 89);
    push(lista, 86);
    push(lista, 21);

    mostrar(lista);
    rotar(lista);
    mostrar(lista);
    while (lista != nullptr)
    {
        pop(lista);
    }
    return 0;
}