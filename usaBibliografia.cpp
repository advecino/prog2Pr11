//
// Created by advecino on 13/05/2024.
//

#include "Bibliografia.h"
#include <cstring>

bool existe (tbibliografia b, char ISBN[])
//{Pre: b es una bibliografía iniciada}
//{Post: Devuelve true si en la bibliografía b hay un libro cuyo ISBN es ISBN, y devuelve false en caso contrario.}
{
    Nodo* aux;
    libro l;
    aux=b;
    char isbnaux[10];
    if(!bibliografiaSinLibros(b)){
        extraerISBN(b,ISBN,l);
        obtenerISBN(l,isbnaux);
        if(strcmp(ISBN,isbnaux)==0){
            return true;
        }
        eliminar(b,isbnaux);
    }
    return false;
}


void modificarAnioLibro(tbibliografia &b, char ISBN[], int anio)
//{Pre: ISBN es un ISBN de los libros de la bibliografía b}
//{Post: Modifica el año de publicación del libro de la bibliografía b cuyo ISBN es ISBN poniendo como nuevo año de publicación anio.}
{
    Nodo * aux;
    libro l;
    char isbnaux[10];
    aux=b;
    extraerISBN(b,  ISBN, l);
    modificarAnnoLibro(l,anio);
}
void masNuevo(tbibliografia b, libro & l)
//{Pre: la bibliografía b no debe estar vacía}
//{Post: l es el libro cuyo año de publicación es el mayor de la bibliografía b. En caso de haber varios libros con el mismo año de publicación, solo devuelve uno.}
{
    Nodo * aux;
    aux=b;
    int anno,anno2;
    while(aux!= nullptr){
        obteneranno(l,anno);
        if(anno>anno2){
            extra
        }
    }

}
