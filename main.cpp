#include <iostream>
#include <string.h>
#include "Libro.h"
#include "Bibliografia.h"
#include "usaLibro.cpp"

using namespace std;

int main() {
    int n=0;
    while(n!=7){
        cout << "Introduzca el apartado a utilizar"<<endl;
        cout << "1. Añadir libro"<<endl;
        cout << "2. Modificar anno libro"<<endl;
        cout << "3. Listar libros por ISBN"<<endl;
        cout << "4. Listar libros decreciente anno"<<endl;
        cout << "5. Buscar libro"<<endl;
        cout << "6. Eliminar libro por ISBN"<<endl;
        cout << "7. Numero de libros"<<endl;
        cout << "8. Copiar bibliograrfia"<<endl;
        cout << "9. Terminar"<<endl;
        cin >> n;
        switch (n) {
            case 1:
                leerPaciente(p);
                annadir(c,p);
                break;
            case 2:
                if(!colaVacia(c)){
                    eliminar(c);
                }
                else{cout << "No hay pacientes"<<endl;}
                break;
            case 3:
                if(!colaVacia(c)){
                    mostrarCola(c);}
                else{cout << "No hay pacientes"<<endl;}
                break;
            case 4:
                cout << "El numero de elementos es" << obtenerNumElem(c)<<endl;
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default: cout << "Error"<<endl;

        }

    }
    return 0;
}