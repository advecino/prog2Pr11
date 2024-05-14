#include "Libro.h"
#include <cstring>

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
    strcpy(titulo,l.titulo);
}

void obteneranno(libro l,int &anno){
    anno=l.anno;
}

void obtenerISBN(libro l,char ISBN[]){
    strcpy(ISBN,l.ISBN);
}

