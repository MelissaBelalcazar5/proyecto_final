//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef LLAVE_PLATA_H
#define LLAVE_PLATA_H

#include "Objeto.h"
#include <iostream>

class LlavePlata : public Objeto {
public:
    LlavePlata()
        : Objeto("Llave de Plata",
                 "Llave antigua grabada con símbolos mágicos.",
                 "Clave") {}

    void usar(Jugador& j) override {
        std::cout << "🔑 Inserta la Llave de Plata... ¡la puerta del Castillo Interior se abre!\n";
    }
};

#endif
