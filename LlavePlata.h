//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef LLAVE_PLATA_H
#define LLAVE_PLATA_H

#include "Objeto.h"
#include <iostream>

class Jugador; // Declaración adelantada (IMPORTANTE)

class LlavePlata : public Objeto {
public:
    LlavePlata()
        : Objeto("Llave de Plata",
                 "Llave antigua grabada con símbolos mágicos.",
                 "Clave") {}

    void usar(Jugador& j) override;
};

#endif



