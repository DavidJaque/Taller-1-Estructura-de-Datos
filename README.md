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


*Funcionalidades Específicas*
    • Agregar Material a la Biblioteca:
        Implementar funciones para agregar nuevos libros o revistas al array biblioteca.
        Validar que no se exceda el tamaño máximo del array.
    • Mostrar Información de los Materiales:
        Implementar un menú que permita a los usuarios listar todos los materiales en la biblioteca con su información detallada.
    • Buscar Material:
        Función para buscar materiales por título o autor utilizando búsquedas lineales en el array.
    • Prestar y Devolver Material:
        Implementar la lógica de préstamo y devolución de materiales. Actualizar el estado prestado del material y registrarlo en el array materialesPrestados del Usuario.
    • Gestión de Usuarios:
        Implementar la funcionalidad para crear, buscar y eliminar usuarios. Asociar materiales prestados a usuarios específicos.

*Manejo de Errores y Validaciones*
    Verificar que los usuarios no puedan prestar más de 5 materiales al mismo tiempo.
    Asegurarse de que los materiales no se presten si ya están prestados.
    Implementar manejo básico de errores para casos como arrays llenos, materiales no encontrados, etc.

*Entrada y Salida de Datos*
    • Interfaz de Usuario:
        Crear un menú simple en consola para interactuar con el simulador (opciones como agregar libros, prestar materiales, listar materiales, etc.).
    • Persistencia de Datos:
        Agregar la funcionalidad de guardar y cargar el estado de la biblioteca y los usuarios desde archivos de texto, utilizando fstream de C++.