#include "Bibliografia.h"
#include <cstring>

using namespace std;


void iniciar(tbibliografia &b){
    b=nullptr;
}

void anadir(tbibliografia &b, libro l) {
    Nodo *nuevo = new Nodo;
    copiarLibro(l,nuevo->dato);
    Nodo *aux = b;
    Nodo *anterior = nullptr;
    char isbn[10],isbnaux[10];
    obtenerISBN(l,isbn);

    if(aux!=nullptr){
        obtenerISBN(aux->dato,isbnaux);
    while (aux != nullptr && strcmp(isbnaux, isbn) < 0) {
        anterior = aux;
        aux = aux->sig;
        if(aux != nullptr)
            obtenerISBN(aux->dato,isbnaux);
    }
    }
    nuevo->sig = aux;
    if (anterior == nullptr)
        b = nuevo;
    else
        anterior->sig = nuevo;
}


void eliminar(tbibliografia &b, char ISBN[]) {
    if (b == nullptr)
        return;
    Nodo *aux = b;
    Nodo *anterior = nullptr;
    char isbnaux[10];
    if(aux!=nullptr){
        obtenerISBN(aux->dato,isbnaux);
    while(strcmp(isbnaux,ISBN)!=0) {
        anterior = aux;
        aux = aux->sig;
        obtenerISBN(aux->dato,isbnaux);
    }
    }

    if (aux == nullptr)
        return;

    if (anterior != nullptr)
        anterior->sig = aux->sig;
    else
        b = aux->sig;

    delete aux;
}

void extraerISBN(tbibliografia b, char ISBN[], libro & l) {
    if (b == nullptr) {
        return;
    }

    Nodo *aux = b;

    while (aux != nullptr) {
        if (strcmp(aux->dato.ISBN, ISBN) == 0) {
            l = aux->dato; // Copia el libro encontrado
            return;
        }
        aux = aux->sig;
    }

}


void extraerPosicion(tbibliografia b, int pos, libro & l){
    Nodo * aux;
    aux=b;
    int num=0;
    while(num<pos){
        num++;
        aux = aux->sig;
    }
    copiarLibro(aux->dato,l);
}

bool bibliografiaSinLibros (tbibliografia b){
    return b==nullptr;
}

int numeroLibros (tbibliografia b){
    int num=0;
    Nodo * aux;
    aux=b;
    while(aux!=nullptr){
        aux = aux->sig;
        num++;
    }
    return num;
}

void copiarBibliografia(tbibliografia b, tbibliografia &b1){
    if (b == nullptr) {
        b1 = nullptr;
        return;
    }
    iniciar(b1);
    Nodo *aux = b;
    while (aux != nullptr) {
        anadir(b1, aux->dato);
        aux = aux->sig;
    }
}

void mostrarBibliografia(tbibliografia b){
    Nodo * aux;
    aux=b;
    while(aux!=nullptr){
        mostrarLibro(aux->dato);
        aux = aux->sig;
    }
}

