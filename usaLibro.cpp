#include "Libro.h"
#include <iostream>

using namespace std;

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

void copiarLibro(libro l, libro &copia){
    char isbn[10],titulo[30];
    int anno;
    obtenerISBN(l, isbn);
    obtenerTitulo(l,titulo);
    obteneranno(l,anno);
    crearLibro(copia,isbn,titulo,anno);
}
