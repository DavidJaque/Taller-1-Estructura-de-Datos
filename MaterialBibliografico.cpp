#include "MaterialBibliografico.hpp"
#include <iostream>

//  constructor
MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(false) {}

// destructor
MaterialBibliografico::~MaterialBibliografico() {}

void MaterialBibliografico::prestar() {
    prestado = true;
}

void MaterialBibliografico::devolver() {
    prestado = false;
}

bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

//  se crea un método para obtener el ISBN q es invisible desde otra clase
string MaterialBibliografico::getISBN() const {
    return isbn;
}


