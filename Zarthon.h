//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef ZARTHON_H
#define ZARTHON_H

#include "Enemigo.h"
#include <iostream>

class Zarthon : public Enemigo {
public:
    Zarthon(std::string n, int v = 120)
        : Enemigo(n, v, "Hechicero Supremo", 20) {}

    void taunt() override {
        std::cout << nombre << " ruge: 'Has llegado lejos... pero aquí termina tu historia.'" << std::endl;
    }
};

#endif


