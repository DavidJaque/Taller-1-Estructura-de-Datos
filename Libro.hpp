#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.hpp"

class Libro : public MaterialBibliografico {
private:
    string fechaPublicacion;
    string resumen;

public:
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
    void mostrarInformacion() const override;
};

#endif // LIBRO_HPP
