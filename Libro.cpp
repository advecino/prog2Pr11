//
// Created by advecino on 13/05/2024.
//

#include "Libro.h"
#include <cstring>

void crearLibro(libro &l,char ISBN[],char titulo[],int anno){
    strcpy(l.ISBN,ISBN);
    strcpy(l.titulo,titulo);
    l.anno=anno;
}

void modificarAnnoLibro(libro l,int annoNew){
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
