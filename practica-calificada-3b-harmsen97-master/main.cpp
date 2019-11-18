#include <iostream>

#include "funciones.h"

int main() {
    auto tablero = leer("../rectangulos.in");

    escritura("../rectangulo.out", tablero);

    return 0;
}