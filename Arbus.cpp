#include <iostream>
#include "Arbus.h"

// Contructor
template <typename T>
Arbus<T>::Arbus()
{
    raiz = NULL;
}

// Destructor
template <typename T>
Arbus<T>::~Arbus()
{
    raiz = NULL;
}

// Agregar elementos
template <typename T>
void Arbus<T>::agregar(T elemento)
{
    if (raiz == NULL) {
        crearNodo(elemento, raiz);
    } else {
        crearArbol(raiz, elemento);
    }
}

template <typename T>
void Arbus<T>::crearArbol(Nodo * & raiz, T elemento)
{
    if (elemento < raiz->elemento) {
        if (raiz->izq != NULL) {
            crearArbol(raiz->izq, elemento);
        } else {
            crearNodo(elemento, raiz->izq);
        }
    } else if (elemento > raiz->elemento) {
        if (raiz->der != NULL) {
            crearArbol(raiz->der, elemento);
        } else {
            crearNodo(elemento, raiz->der);
        }
    }
}

template <typename T>
void Arbus<T>::crearNodo(T elemento, Nodo * & padre)
{
    Nodo * nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    padre = nuevo;
}

// Vacio
template <typename T>
bool Arbus<T>::esVacio()
{
    return raiz == NULL;
}
// Pertenece
template <typename T>
bool Arbus<T>::pertenece(T elemento)
{
    return existeElemento(raiz, elemento);
}

template <typename T>
bool Arbus<T>::existeElemento(Nodo * raiz, T elemento)
{
    if (raiz->elemento == elemento) {
        return true;
    } else if (elemento < raiz->elemento) {
        if (raiz->izq != NULL)
            return existeElemento(raiz->izq, elemento);
        else
            return false;
    } else if (elemento > raiz->elemento) {
        if (raiz->der != NULL)
            return existeElemento(raiz->der, elemento);
        else
            return false;
    }
}

template <typename T>
bool Arbus<T>::esHoja(Nodo * raiz)
{
    return raiz->izq == NULL && raiz->der == NULL;
}

// Cantidad de elementos
template <typename T>
int Arbus<T>::cantidadElementos()
{
    return contar(raiz);
}

template <typename T>
int Arbus<T>::contar(Nodo * raiz)
{
    int contador = 1;
    if (raiz->izq != NULL)
        contador += contar(raiz->izq);
    if (raiz->der != NULL)
        contador += contar(raiz->der);
    return contador;
}

template class Arbus<int>;
