#include "Libro.hpp"
#include <iostream>

Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

void Libro::mostrarInformacion() const {
    cout << "Libro: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
         << "\nFecha de Publicación: " << fechaPublicacion << "\nResumen: " << resumen
         << "\nEstado: " << (estaPrestado() ? "Prestado" : "Disponible") << endl;
}
