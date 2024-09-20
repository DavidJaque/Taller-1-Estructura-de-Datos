#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(string nombre, int id) : nombre(nombre), id(id), cantidadMateriales(0) {
    for (int i = 0; i < 5; ++i) {
        materialesPrestados[i] = nullptr;
    }
}

Usuario::~Usuario() {
    for (int i = 0; i < cantidadMateriales; ++i) {
        delete materialesPrestados[i];
    }
}

bool Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (cantidadMateriales < 5 && !material->estaPrestado()) {
        materialesPrestados[cantidadMateriales++] = material;
        material->prestar();
        return true;
    }
    return false;
}

bool Usuario::devolverMaterial(string isbn) {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i]->getISBN() == isbn) {
            materialesPrestados[i]->devolver();
            delete materialesPrestados[i];
            for (int j = i; j < cantidadMateriales - 1; ++j) {
                materialesPrestados[j] = materialesPrestados[j + 1];
            }
            materialesPrestados[--cantidadMateriales] = nullptr;
            return true;
        }
    }
    return false;
}

void Usuario::mostrarMaterialesPrestados() const {
    for (int i = 0; i < cantidadMateriales; ++i) {
        materialesPrestados[i]->mostrarInformacion();
    }
}
