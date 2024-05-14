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

void eliminar(tbibliografia &b, char ISBN[]){
    Nodo *aux;
    Nodo* anterior;
    char isbn[10];
    obtenerISBN(aux->dato,isbn);
    while(aux!=nullptr && strcmp(isbn,ISBN)!=0){
        anterior=aux;
        aux=aux->sig;
        obtenerISBN(aux->dato,isbn);
    }
    anterior->sig=aux->sig;
    delete(aux);
}

void extraerISBN(tbibliografia b, char ISBN[], libro & l){
    Nodo * aux;
    aux=b;
    char isbnaux[10];
    obtenerISBN(aux->dato,isbnaux);
    while(aux!=nullptr && strcmp(isbnaux,ISBN)==0){
        aux = aux->sig;
        obtenerISBN(aux->dato,isbnaux);
    }
    copiarLibro(aux->dato,l);
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
    Nodo * aux;
    aux=b;
    iniciar(b1);
    while(aux!=nullptr){
        b1=b1->sig;
        b1= aux;
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

