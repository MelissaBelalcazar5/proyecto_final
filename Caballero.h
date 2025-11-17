//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef CABALLERO_H
#define CABALLERO_H

#include "Enemigo.h"
#include <iostream>

class Caballero : public Enemigo {
public:
    Caballero(std::string n, int v = 60)
        : Enemigo(n, v, "Caballero Oscuro", 15) {}

    void taunt() override {
        std::cout << nombre << " exclama: '¡Por el honor de Zarthon, caerás!'" << std::endl;
    }
};

#endif

