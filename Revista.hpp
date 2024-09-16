#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "MaterialBibliografico.hpp"

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    string mesPublicacion;

public:
    Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion);
    void mostrarInformacion() const override;
};

#endif 
