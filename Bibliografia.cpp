#include "Bibliografia.h"
#include "usaLibro.cpp"
#include <cstring>

using namespace std;


void iniciar(tbibliografia &b){
    b=nullptr;
}

void anadir(tbibliografia &b, libro l) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = l;
    nuevo->sig = nullptr;
    Nodo *aux = b;
    Nodo *anterior = nullptr;
    char isbn[10],isbnaux[10];
    obtenerISBN(l,isbn);
    if(aux!= nullptr){
        obtenerISBN(aux->dato,isbnaux);
        while (aux != nullptr && strcmp(isbnaux, isbn) < 0) {
            anterior = aux;
            aux = aux->sig;
            if(aux != nullptr)
                obtenerISBN(aux->dato,isbnaux);
        }
    }

    nuevo->sig = aux;
    if (anterior != nullptr)
        anterior->sig = nuevo;
    else
        b = nuevo;

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


void modificarAnnoLibro(tbibliografia &b, char ISBN[], int anio)
//{Pre: ISBN es un ISBN de los libros de la bibliografía b}
//{Post: Modifica el año de publicación del libro de la bibliografía b cuyo ISBN es ISBN poniendo como nuevo año de publicación anio.}
{
    libro l;
    int numLibros = numeroLibros(b);
    for (int i = 0; i < numLibros; ++i) {
        extraerPosicion(b, i, l);
        char isbn_temp[10];
        obtenerISBN(l, isbn_temp);
        if (strcmp(isbn_temp, ISBN) == 0) {
            modificarAnioLibro(l, anio);
            eliminar(b, ISBN);
            anadir(b, l);
            break;
        }
    }
}
void masNuevo(tbibliografia b, libro & l)
//{Pre: la bibliografía b no debe estar vacía}
//{Post: l es el libro cuyo año de publicación es el mayor de la bibliografía b. En caso de haber varios libros con el mismo año de publicación, solo devuelve uno.}
{
    libro temp;
    l.anno = 0; // Inicializar año con un valor muy pequeño
    int anno,anno2;
    int numLibros = numeroLibros(b);
    for (int i = 0; i < numLibros; ++i) {
        extraerPosicion(b, i, temp);
        obteneranno(temp,anno);
        obteneranno(l,anno2);
        if (anno > anno2){
            copiarLibro(temp, l);
        }
    }}