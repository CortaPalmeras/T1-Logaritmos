
#include <iostream>
#include <cmath>

#include "tarea1.hpp"

Nodo *crear_nodo() {
    Nodo *n = new Nodo;
    n->size = 0;
    return n;
}

void anadir_entrada(Nodo *n, Punto p) {
    if (n->size >= B) {
        std::cout << "nodo sobrepasa el tamaño máximo en 'anadir_entrada'\n";
        exit(1);
    }
    int s = n->size;
    n->entradas[s].p = p;
    n->entradas[s].a = NULL;
    n->entradas[s].r = 0;
    n->size++;
}

void eliminar_arbol(Nodo *arbol) {
    if (arbol->entradas[0].a != NULL) {
        for (int i = 0; i < arbol->size; i++) {
            eliminar_arbol(arbol->entradas[i].a);
        }
    }
    delete arbol;
}

int altura_arbol(Nodo const &arbol) {
    if (arbol.entradas[0].a == NULL) {
        return 1;
    } else {
        return altura_arbol(*arbol.entradas[0].a) + 1;
    }
}