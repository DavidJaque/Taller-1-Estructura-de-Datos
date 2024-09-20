#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "MaterialBibliografico.hpp"    // hereda de MaterialBibliografico

class Libro : public MaterialBibliografico {
private:
    string fechaPublicacion;
    string resumen;

public:
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
    void mostrarInformacion() const override;
};

#endif // LIBRO_HPP
