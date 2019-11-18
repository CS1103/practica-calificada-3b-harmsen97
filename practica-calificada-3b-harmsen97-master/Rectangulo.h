//
// Created by Jeronimo on 2019-11-17.
//

#include <algorithm>

#ifndef PC3B_RECTANGULO_H
#define PC3B_RECTANGULO_H

struct Rectangulo{
    std::pair<int, int> esquina;
    char accion;
    int alto, largo;
    Rectangulo() = default;
};

#endif //PC3B_RECTANGULO_H
