#include <iostream>
#include "Bibliografia.h"

using namespace std;

int main() {
    int n = 0,anno;
    char isbn[10];
    tbibliografia b;
    iniciar(b);
    libro l;

    while (n != 9) {
        cout << "Introduzca el número correspondiente a la operación que desea realizar:" << endl;
        cout << "1. Añadir libro" << endl;
        cout << "2. Modificar año de un libro" << endl;
        cout << "3. Listar libros por ISBN" << endl;
        cout << "4. Listar libros por orden decreciente de año" << endl;
        cout << "5. Buscar libro por ISBN" << endl;
        cout << "6. Eliminar libro por ISBN" << endl;
        cout << "7. Indicar el número de libros que existen" << endl;
        cout << "8. Copiar una bibliografía" << endl;
        cout << "9. Terminar" << endl;

        cin >> n;

        switch (n) {
            case 1: {
                leerLibro(l);
                anadir(b,l);
                break;
            }
            case 2: {
                cout << "Introduzca el año a modificar: ";
                cin >> anno;
                cout << "Introduzca el año a ISBN del libro: ";
                cin >> isbn;
                modificarAnnoLibro(b,isbn,anno);
                break;
            }
            case 3: {
                if(!bibliografiaSinLibros(b)){
                mostrarBibliografia(b);
                }
                else{
                    cout << "no hay libros"<<endl;
                }
                break;
            }
            case 4: {
                // Agrega tu código para la opción 4 aquí
                break;
            }
            case 5: {
                // Agrega tu código para la opción 5 aquí
                break;
            }
            case 6: {
                // Agrega tu código para la opción 6 aquí
                break;
            }
            case 7: {
                // Agrega tu código para la opción 7 aquí
                break;
            }
            case 8: {
                // Agrega tu código para la opción 8 aquí
                break;
            }
            case 9: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese un número válido del menú." << endl;
                break;
            }
        }
    }

    return 0;
}
