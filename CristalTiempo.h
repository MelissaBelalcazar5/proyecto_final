//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef CRISTAL_TIEMPO_H
#define CRISTAL_TIEMPO_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

class CristalTiempo : public Objeto {
public:
    CristalTiempo()
        : Objeto("Cristal del Tiempo",
                 "Objeto mágico que detiene brevemente el tiempo.",
                 "Especial") {}

    void usar(Jugador& j) override {
        std::cout << "🕯️ El tiempo se detiene. Esquivarás el próximo ataque enemigo.\n";
        j.activarEsquiva();
    }
};

#endif
