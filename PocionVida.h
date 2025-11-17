//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef POCION_VIDA_H
#define POCION_VIDA_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

class PocionVida : public Objeto {
public:
    PocionVida()
        : Objeto("Poción de Vida",
                 "Frasco brillante con líquido rojo.",
                 "Curativo") {}

    void usar(Jugador& j) override {
        std::cout << "💊 Bebes una Poción de Vida. Recuperas 30 puntos de vida.\n";
        j.curar(30);
    }
};

#endif

