//
// Created by Jeronimo on 2019-11-17.
//

#ifndef PC3B_FUNCIONES_H
#define PC3B_FUNCIONES_H

#include <vector>
#include <fstream>
#include "Rectangulo.h"

bool estaDentro(Rectangulo a, Rectangulo b){
    if((b.esquina.first < a.esquina.first &&  b.esquina.first+b.largo > a.esquina.first + a.largo)
       && (b.esquina.second > a.esquina.second && b.esquina.second-b.alto < a.esquina.second - a.alto))
        return true;
    return false;
}

bool esValido(Rectangulo a, std::vector<Rectangulo> rectangulos){
    for(auto&b:rectangulos){
        std::pair<int, int> l1 = a.esquina;
        std::pair<int, int> l2 = b.esquina;

        std::pair<int, int> r1 = std::make_pair(a.esquina.first+a.largo, a.esquina.second-a.alto);
        std::pair<int, int> r2 = std::make_pair(b.esquina.first+b.largo, b.esquina.second-b.alto);

        if(estaDentro(a,b) or estaDentro(b,a)) {
            continue;
        }

        if( l1.first < r2.first && r1.first > l2.first &&
            l1.second > r2.second && r1.second < l2.second)
            return false;
    }
    return true;
}

bool comp(Rectangulo& a, Rectangulo& b){
    if(a.esquina.first != b.esquina.first){
        return a.esquina.first < b.esquina.first;
    }
    else{
        if(a.esquina.second != b.esquina.second)
            return a.esquina.second < b.esquina.second;
        else
            return (a.alto * a.largo) < (b.alto * b.largo);
    }
}

std::vector<Rectangulo> leer(std::string filename){
    std::ifstream input(filename, std::ios::in);

    int n, fil, col;
    input>>n>>fil>>col;

    std::vector<Rectangulo> tablero;

    for(int i=0; i<n; ++i){
        Rectangulo r;
        input>>r.accion>>r.esquina.first>>r.esquina.second>>r.alto>>r.largo;
        if(esValido(r, tablero))
            tablero.push_back(r);
    }

    std::sort(tablero.begin(), tablero.end(), comp);

    return tablero;
}

void escritura(std::string file, std::vector<Rectangulo> tablero){

    std::fstream out(file, std::ios::out);

    for(auto&i:tablero)
        out<<i.accion<<' '<<i.esquina.first<<' '<<i.esquina.second<<' '<<i.alto<<' '<<i.largo<<'\n';
}

#endif //PC3B__FUNCIONES_H
