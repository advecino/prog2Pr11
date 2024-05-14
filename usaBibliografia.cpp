#include "Bibliografia.h"
#include "Libro.h" // Asegúrate de incluir el archivo de encabezado que contiene la declaración de copiarLibro
#include <cstring>

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