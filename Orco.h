//
// Created by Melissa Belalcazar on 11/11/25.
//
#ifndef ORCO_H
#define ORCO_H

#include "Enemigo.h"
#include <iostream>

class Orco : public Enemigo {
public:
    Orco(std::string n, int v = 50)
        : Enemigo(n, v, "Orco", 12) {}

    void taunt() override {
        std::cout << nombre << " gruñe: '¡Tu cabeza adornará mi lanza!'" << std::endl;
    }
};

#endif


