//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef ESPADA_LUZ_H
#define ESPADA_LUZ_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

class EspadaLuz : public Objeto {
public:
    EspadaLuz()
        : Objeto("Espada de Luz",
                 "Espada legendaria con brillo celestial.",
                 "Ofensivo") {}

    void usar(Jugador& j) override {
        std::cout << "⚔️ Empuñas la Espada de Luz. Tu daño aumenta permanentemente en +10.\n";
        j.incrementarDanio(10);
    }
};

#endif

