#include "alumno.hpp"
#include <iostream>
#include <limits>

int main() {
    const int TOTAL_ALUMNOS = 3;
    GestionEscolar::Alumno alumnos[TOTAL_ALUMNOS];

    // Puntero auxiliar para recorrer el arreglo y pedir los datos
    GestionEscolar::Alumno* ptrAuxiliar = alumnos;
    for (int i = 0; i < TOTAL_ALUMNOS; ++i) {
        ptrAuxiliar->pedirDatos(i + 1);
        ptrAuxiliar++; // Avanza a la dirección del siguiente alumno
    }

    // Llamamos a la función pasando el puntero al arreglo para calcular el ganador
    const GestionEscolar::Alumno* mejorAlumno = GestionEscolar::buscarMejorPromedio(alumnos, TOTAL_ALUMNOS);

    // Si encontramos al mejor, mostramos sus datos en pantalla
    if (mejorAlumno != nullptr) {
        mejorAlumno->mostrarDatos();
    } else {
        std::cout << "\nNo se pudieron procesar los alumnos.\n";
    }

    // Bloqueo portátil de consola: Asegura que la terminal no se apague sola
    std::cout << "\nPresione ENTER para salir...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 

    return 0;
}
