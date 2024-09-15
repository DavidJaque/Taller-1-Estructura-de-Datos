# Taller-1-Estructura-de-Datos
Desarrollar una biblioteca digital para el Taller 1 de Estructura de Datos

El proyecto consiste en crear un sistema que permita a los usuarios de la biblioteca realizar acciones como agregar nuevos libros, buscar libros por título o autor, y gestionar el préstamo de libros.

Organización del Código: El proyecto debe estar dividido en varios archivos .cpp y .h para fomentar una buena organización y modularidad del código.


*Clases*
    • Clase MaterialBibliografico con atributos nombre, isbn, autor y prestado (prestado hace referencia al estado de si el material esta prestado o no) y con un método virtual llamado mostrarInformación.

    • Clase Libro hereda de MaterialBibliografico, con atributos extras fechaPublicacion y resumen, y debe implementar el método mostrarInformación.

    • Clase Revista que hereda de MaterialBibliografico, con atributos extras numeroEdicion y mesPublicacion, y debe implementar el método mostrarInformación.
    
    • Clase Usuario con atributos nombre, id y un array de un máximo de 5 que se llama MaterialBibligrafico (MaterialBibliografico* materialesPrestados[5]) y con los métodos prestarMaterial, devolverMaterial y mostrarMaterialesPrestados.


*Gestión de Memoria y Punteros*
• Punteros:
    Utilizar punteros para gestionar los objetos de MaterialBibliografico y sus derivados (Libro, Revista).

    Implementar asignación dinámica de memoria para los objetos MaterialBibliografico usando new y liberar la memoria adecuadamente con delete.

• Array de Objetos:
    Almacenar los objetos Libro y Revista en arrays estáticos de tamaño limitado.
    Ejemplo: MaterialBibliografico* biblioteca[100];