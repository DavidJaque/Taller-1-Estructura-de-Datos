#include "MaterialBibliografico.hpp"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(false) {}

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
