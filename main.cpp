#include <iostream>
#include <fstream>
#include <string>
#include "Libro.hpp"
#include "Revista.hpp"
#include "Usuario.hpp"

using namespace std;

const int MAX_MATERIALES = 100;
const int MAX_USUARIOS = 50;

MaterialBibliografico* biblioteca[MAX_MATERIALES];  // Array para almacenar los materiales de la biblioteca
Usuario* usuarios[MAX_USUARIOS];  // Array para almacenar los usuarios
int cantidadMateriales = 0;
int cantidadUsuarios = 0;

// Función para agregar un nuevo libro
void agregarLibro() 
{
    if (cantidadMateriales < MAX_MATERIALES) {
        string nombre, isbn, autor, fechaPublicacion, resumen;
        cout << "Ingrese nombre del libro: ";
        cin >> nombre;
        cout << "Ingrese ISBN: ";
        cin >> isbn;
        cout << "Ingrese autor: ";
        cin >> autor;
        cout << "Ingrese fecha de publicacion: ";
        cin >> fechaPublicacion;
        cout << "Ingrese resumen: ";
        cin >> resumen;

        biblioteca[cantidadMateriales++] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
        cout << "Libro agregado exitosamente" << endl;
    } else {
        cout << "La biblioteca está llena" << endl;
    }
}

// Función para agregar una nueva revista
void agregarRevista() 
{
    if (cantidadMateriales < MAX_MATERIALES) {
        string nombre, isbn, autor, mesPublicacion;
        int numeroEdicion;
        cout << "Ingrese nombre de la revista: ";
        cin >> nombre;
        cout << "Ingrese ISBN: ";
        cin >> isbn;
        cout << "Ingrese autor: ";
        cin >> autor;
        cout << "Ingrese numero de edicion: ";
        cin >> numeroEdicion;
        cout << "Ingrese mes de publicacion: ";
        cin >> mesPublicacion;

        biblioteca[cantidadMateriales++] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
        cout << "Revista agregada " << endl;
    } else {
        cout << "La biblioteca esta llena " << endl;
    }
}

// Función para mostrar todos los materiales
void mostrarMateriales() 
{
    for (int i = 0; i < cantidadMateriales; ++i) {
        biblioteca[i]->mostrarInformacion();
        cout << "--------------------------------------" << endl;
    }
}

// Función para buscar material por título o autor
void buscarMaterial() 
{
    string termino;
    cout << "Ingrese el nombre o autor del material que desea buscar: ";
    cin >> termino;

    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getISBN() == termino) {  // Puedes modificar esta parte si quieres buscar por otro atributo
            biblioteca[i]->mostrarInformacion();
            return;
        }
    }
    cout << "Material no encontrado " << endl;
}

// Función para prestar un material a un usuario
void prestarMaterial() 
{
    int idUsuario;
    string isbn;
    
    cout << "Ingrese el ID del usuario: ";
    cin >> idUsuario;
    cout << "Ingrese el ISBN del material: ";
    cin >> isbn;

    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getISBN() == isbn && !biblioteca[i]->estaPrestado()) {
            for (int j = 0; j < cantidadUsuarios; ++j) {
                if (usuarios[j]->prestarMaterial(biblioteca[i])) {
                    cout << "Material prestado " << endl;
                    return;
                }
            }
        }
    }
    cout << "No se pudo prestar el material" << endl;
}

// Funcion para devolver un material
void devolverMaterial() 
{
    int idUsuario;
    string isbn;

    cout << "Ingrese el ID del usuario: ";
    cin >> idUsuario;
    cout << "Ingrese el ISBN del material a devolver: ";
    cin >> isbn;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->devolverMaterial(isbn)) {
            cout << "Material devuelto exitosamente." << endl;
            return;
        }
    }
    cout << "No se pudo devolver el material." << endl;
}

// Función para agregsr un usuario
void agregarUsuario() 
{
    if (cantidadUsuarios < MAX_USUARIOS) {
        string nombre;
        int id;
        cout << "Ingrese nombre del usuario: ";
        cin >> nombre;
        cout << "Ingrese ID del usuario: ";
        cin >> id;

        usuarios[cantidadUsuarios++] = new Usuario(nombre, id);
        cout << "Usuario agregado exitosamente" << endl;
    } else {
        cout << "La lista de usuarios está llena" << endl;
    }
}

// metodo para buscar un usuario
void buscarUsuario() 
{
    int ID;
    cout << "Ingrese el ID del usuario que desea buscar: ";
    cin >> ID;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getID() == ID) {
            cout << "Usuario encontrado: " << usuarios[i]->getNombre() << endl;
            return;
        }
    }
    cout << "Usuario no encontrado" << endl;
}



// Función para eliminar un usuario
void eliminarUsuario() 
{
    int id;
    cout << "Ingrese el ID del usuario que desea eliminar: ";
    cin >> id;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i]->getID() == id) {
            // liberar memoria
            delete usuarios[i];

            // mover los usuarios restantes hacia la izquierda
            for (int j = i; j < cantidadUsuarios - 1; ++j) {
                usuarios[j] = usuarios[j + 1];
            }
            usuarios[--cantidadUsuarios] = nullptr; // reduce cantidad y limpia el último
            cout << "Usuario eliminado " << endl;
            return;
        }
    }
    cout << "Error: el usuario no se encuentra registrado " << endl;

}




// Menu principal
void menu() 
{
    int opcion;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Agregar libro\n";
        cout << "2. Agregar revista\n";
        cout << "3. Mostrar materiales\n";
        cout << "4. Buscar material\n";
        cout << "5. Prestar material\n";
        cout << "6. Devolver material\n";
        cout << "7. Agregar usuario\n";
        cout << "8. Buscar usuario\n";
        cout << "9. Eliminar usuario\n";

        cout << "0. Salir\n";
        cout << "Ingrese opcion (0 para salir): ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarLibro(); break;
            case 2: agregarRevista(); break;
            case 3: mostrarMateriales(); break;
            case 4: buscarMaterial(); break;
            case 5: prestarMaterial(); break;
            case 6: devolverMaterial(); break;
            case 7: agregarUsuario(); break;
            case 8: buscarUsuario(); break;
            case 9: eliminarUsuario(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invvalida " << endl;
        }
    } while (opcion != 0);
}

int main() 
{
    menu();
    return 0;
}
