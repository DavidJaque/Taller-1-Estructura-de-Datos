#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "MaterialBibliografico.hpp"

class Usuario 
{
private:
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];  //  <5
    int cantidadMateriales;

public:
    Usuario(string nombre, int id);
    ~Usuario();

    string getNombre() const;
    int getID() const;

    bool prestarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(string isbn);
    void mostrarMaterialesPrestados() const;

};

#endif 
