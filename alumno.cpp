#include "alumno.hpp"
#include <iostream>
#include <limits>

namespace GestionEscolar {

    Alumno::Alumno() : nombre(""), edad(0), promedio(0.0f) {}

    void Alumno::pedirDatos(int numeroAlumno) {
        std::cout << "\n--- Datos del Alumno " << numeroAlumno << " ---\n";
        std::cout << "Ingrese Nombre: ";
        std::getline(std::cin >> std::ws, nombre); 

        std::cout << "Ingrese Edad: ";
        while (!(std::cin >> edad) || edad < 0) {
            std::cout << "Edad inválida. Intente de nuevo: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Ingrese Promedio: ";
        while (!(std::cin >> promedio) || promedio < 0.0f || promedio > 10.0f) {
            std::cout << "Promedio inválido (0.0 - 10.0). Intente de nuevo: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void Alumno::mostrarDatos() const {
        std::cout << "\n=====================================\n";
        std::cout << "   DATOS DEL ALUMNO CON MEJOR PROMEDIO \n";
        std::cout << "=====================================\n";
        std::cout << "Nombre:   " << nombre << "\n";
        std::cout << "Edad:     " << edad << " años\n";
        std::cout << "Promedio: " << promedio << "\n";
        std::cout << "=====================================\n";
    }

    float Alumno::obtenerPromedio() const {
        return promedio;
    }

    // Lógica corregida: Utiliza un puntero para iterar y encontrar el mejor promedio
    const Alumno* buscarMejorPromedio(const Alumno* ptrArreglo, int cantidad) {
        if (cantidad <= 0 || ptrArreglo == nullptr) return nullptr;

        // Inicializamos el puntero al "mejor" apuntando al primer alumno
        const Alumno* ptrMejor = ptrArreglo; 

        // Recorremos el resto de los alumnos comparando sus promedios
        for (int i = 1; i < cantidad; ++i) {
            // Comparamos el promedio del alumno actual con el del mejor guardado hasta ahora
            if (ptrArreglo[i].obtenerPromedio() > ptrMejor->obtenerPromedio()) {
                ptrMejor = &ptrArreglo[i]; // Asignamos la dirección de memoria del nuevo mejor alumno
            }
        }
        
        return ptrMejor; // Retorna el puntero al alumno con la nota más alta
    }
}
