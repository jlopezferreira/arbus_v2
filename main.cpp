#include <iostream>
#include "Arbus.h"

using namespace std;

int main()
{
    Arbus<int> arbol;
    arbol.agregar(5);
    arbol.agregar(2);
    arbol.agregar(10);
    arbol.agregar(25);
    arbol.agregar(15);

    if (arbol.pertenece(16))
        cout << "Pertenece" << endl;
    else
        cout << "No pertenece" << endl;

    int cantElem = arbol.cantidadElementos();
    cout << "Cantidad de elementos: " << cantElem << endl;

    int profundidad = arbol.profundidad();
    cout << "Profundidad: " << profundidad << endl;

    cout << "Frontera: " << endl;
    arbol.mostrarFrontera();
    cout << "En orden: " << endl;
    arbol.mostrarEnOrden();
    return 0;
}
