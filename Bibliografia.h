#ifndef DESKTOP_BIBLIOGRAFIA_H
#define DESKTOP_BIBLIOGRAFIA_H

#include "Libro.h"



struct Nodo {
    libro dato;
    Nodo * sig;
};
typedef Nodo* tbibliografia;

void iniciar(tbibliografia &b);
//{Pre: }
//{Post: Inicia b como una bibliografía sin libros.}
void anadir(tbibliografia &b, libro l);
//{Pre: b es una bibliografía iniciada}
//{Post: Añade el libro l a la bibliografía b.}
void eliminar(tbibliografia &b, char ISBN[]);
//{Pre: ISBN es un ISBN de los libros de la bibliografía b}
//{Post: Elimina el libro cuyo ISBN es ISBN de la bibliografía b.}
void extraerISBN(tbibliografia b, char ISBN[], libro & l);
//{Pre: ISBN es un ISBN de los libros de la bibliografía b}
//{Post: Devuelve de la bibliografía b los datos del libro cuyo ISBN
//        es ISBN.}
void extraerPosicion(tbibliografia b, int pos, libro & l);
//{Pre: pos es un entero menor que el número de libros de la bibliografía b, b es una bibliografía iniciada}
//{Post: Devuelve de la bibliografía b los datos del libro que ocupa
//       la posición pos, empezando a contar en 0, en la bibliografía.}
bool bibliografiaSinLibros (tbibliografia b);
//{Pre: b es una bibliografía iniciada}
//{Post: Devuelve true si la bibliografía no tiene libros y false en caso contrario.}

int numeroLibros (tbibliografia b);
//{Pre: b es una bibliografía iniciada}
//{Post: Devuelve el número de libros de la bibliografía b.}
void copiarBibliografia(tbibliografia b, tbibliografia &b1);
//{Pre: b es una bibliografía ya iniciada}
//{Post: b1 es una copia de b, b no se modifica}
void mostrarBibliografia(tbibliografia b);
//{Pre: b es una bibliografía ya iniciada}
//{Post: muestra los libros almacenados en la bibliografía b, b no se modifica}
//

#endif //DESKTOP_BIBLIOGRAFIA_H
