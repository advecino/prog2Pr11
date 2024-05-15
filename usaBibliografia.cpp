#include "Bibliografia.h"
#include <cstring>
//
bool existe (tbibliografia b, char ISBN[])
//{Pre: b es una bibliografía iniciada}
//{Post: Devuelve true si en la bibliografía b hay un libro cuyo ISBN es ISBN, y devuelve false en caso contrario.}{
{
    libro l;
    bool encontrado = false;
    int numLibros = numeroLibros(b);
    char isbn[10];
    for (int i = 0; i < numLibros; ++i) {
        extraerPosicion(b, i, l);
        obtenerISBN(l,isbn);
        if (strcmp(isbn, ISBN) == 0) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}


void modificarAnnoLibro(tbibliografia &b, char ISBN[], int anio) {
    Nodo *aux = b;
    while (aux != nullptr) {
        char isbn[10];
        obtenerISBN(aux->dato, isbn);
        if (strcmp(isbn, ISBN) == 0) {
            modificarAnioLibro(aux->dato, anio);
            break; // Importante: salir del bucle después de modificar el año del libro
        }
        aux = aux->sig;
    }
}


void masNuevo(tbibliografia b, libro &l) {
    if (b == nullptr)
        return;
    l = b->dato;
    Nodo *aux = b->sig;
    while (aux != nullptr) {
        if (aux->dato.anno > l.anno)
            l = aux->dato;
        aux = aux->sig;
    }
}
