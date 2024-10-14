#ifndef MATERIALBIBLIOGRAFICO_HPP
#define MATERIALBIBLIOGRAFICO_HPP
 
#include <string>
using namespace std;

class MaterialBibliografico {

protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;

public:
    MaterialBibliografico(string nombre, string isbn, string autor);
    virtual ~MaterialBibliografico(); // Destructor

    virtual void mostrarInformacion() const = 0; // metodo virtual 
    void prestar();
    void devolver();
    bool estaPrestado() const;
    string getISBN() const;

    
};

#endif // MATERIALBIBLIOGRAFICO_HPP   
