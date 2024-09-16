#include "Revista.hpp"
#include <iostream>

Revista::Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

void Revista::mostrarInformacion() const {
    cout << "Revista: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
         << "\nNúmero de Edición: " << numeroEdicion << "\nMes de Publicación: " << mesPublicacion
         << "\nEstado: " << (estaPrestado() ? "Prestado" : "Disponible") << endl;
}
