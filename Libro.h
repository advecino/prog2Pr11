#ifndef DESKTOP_LIBRO_H
#define DESKTOP_LIBRO_H


struct libro {
    char ISBN[10];
    char titulo[30];
    int anno;
};

void crearLibro(libro &l,char ISBN[],char titulo[],int anno);

void modificarAnnoLibro(libro l,int annoNew);

void obtenerTitulo(libro l,char titulo[]);

void obteneranno(libro l,int anno);

void obtenerISBN(libro l,char ISBN[]);

#endif //DESKTOP_LIBRO_H
