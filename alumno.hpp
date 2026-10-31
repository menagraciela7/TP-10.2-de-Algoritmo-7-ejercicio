#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>

namespace GestionEscolar {

    // Estructura Alumno con encapsulamiento
    struct Alumno {
    private:
        std::string nombre;
        int edad;
        float promedio;

    public:
        Alumno();

        // Métodos para interactuar con la estructura
        void pedirDatos(int numeroAlumno);
        void mostrarDatos() const;
        float obtenerPromedio() const;
    };

    // Función que recibe un puntero al arreglo para evaluar y devolver al mejor
    const Alumno* buscarMejorPromedio(const Alumno* ptrArreglo, int cantidad);
}

#endif // ALUMNO_HPP
