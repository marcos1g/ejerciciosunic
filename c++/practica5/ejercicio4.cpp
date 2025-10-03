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
        while (aux->sig != nullptr)
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
Nodo *concatenacionA(Nodo *&lista, Nodo *&lista2)
{
    Nodo *nueva = nullptr;

    while (lista != nullptr)
    {
        agregar(nueva, pop(lista));
    }
    while (lista2 != nullptr)
    {
        agregar(nueva, pop(lista2));
    }
    return nueva;
}
Nodo *concatenacionB(Nodo *&lista, Nodo *&lista2)
{

    Nodo *nueva = nullptr;
    Nodo *aux = nullptr;

    while (lista != nullptr)
    {
        int val1 = pop(lista);
        agregar(nueva, val1);
        agregar(aux, val1);
    }
    lista = aux;
    aux = nullptr;
    while (lista2 != nullptr)
    {
        int val2 = pop(lista2);
        agregar(nueva, val2);
        agregar(aux, val2);
    }
    lista2 = aux;
    aux = nullptr;
    return nueva;
}
int main()
{
    Nodo *lista = nullptr;
    Nodo *lista2 = nullptr;
    push(lista, 89);
    push(lista, 86);
    push(lista, 21);
    push(lista2, 43);
    push(lista2, 23);
    push(lista2, 87);

    mostrar(lista);
    mostrar(lista2);
    Nodo *resultado = concatenacionB(lista, lista2);
    mostrar(resultado);
    mostrar(lista);
    mostrar(lista2);
    while (lista != nullptr)
    {
        pop(lista);
    }
    while (lista2 != nullptr)
    {
        pop(lista2);
    }
    while (resultado != nullptr)
    {
        pop(resultado);
    }
    return 0;
}