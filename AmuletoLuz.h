//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef AMULETO_LUZ_H
#define AMULETO_LUZ_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

class AmuletoLuz : public Objeto {
public:
    AmuletoLuz()
        : Objeto("Amuleto de la Luz",
                 "Joya mágica que protege al portador.",
                 "Defensivo") {}

    void usar(Jugador& j) override {
        std::cout << "🔮 El Amuleto de la Luz reduce el daño recibido en un 20%.\n";
        j.activarAmuleto();
    }
};

#endif
