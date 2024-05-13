#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;

void crearLibro(libro &l,char ISBN[],char titulo[],int anno){
    strcpy(l.ISBN,ISBN);
    strcpy(l.titulo,titulo);
    l.anno=anno;
}

void modificarAnioLibro(libro l,int annoNew){
    l.anno=annoNew;
}

void obtenerTitulo(libro l,char titulo[]){
    strcpy(l.titulo,titulo);
}

void obteneranno(libro l,int anno){
    anno=l.anno;
}

void obtenerISBN(libro l,char ISBN[]){
    strcpy(l.ISBN,ISBN);
}

void copiarLibro(libro l, libro &copia){
    char isbn[10],titulo[30];
    int anno;
    obtenerISBN(l, isbn);
    obtenerTitulo(l,titulo);
    obteneranno(l,anno);
    crearLibro(copia,isbn,titulo,anno);
}

void mostrarLibro(libro l){
    char isbn[10],titulo[30];
    int anno;
    obtenerISBN(l, isbn);
    obtenerTitulo(l,titulo);
    obteneranno(l,anno);
    cout << "El ISBN es: "<< isbn<<endl;
    cout << "El titulo es: "<< titulo<<endl;
    cout << "El anno es: "<< anno<<endl;
}

void leerLibro(libro &l){
    char isbn[10],titulo[30];
    int anno;
    cout <<"Introduzca el ISBN: "<<endl;
    cin>>isbn;
    cout <<"Introduzca el Titulo: "<<endl;
    cin>>titulo;
    cout <<"Introduzca el anno: "<<endl;
    cin>>anno;
    crearLibro(l,isbn,titulo,anno);
}

