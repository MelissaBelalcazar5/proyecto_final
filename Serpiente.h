//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef SERPIENTE_H
#define SERPIENTE_H

#include "Enemigo.h"
#include <iostream>

class Serpiente : public Enemigo {
public:
    Serpiente(std::string n, int v = 40)
        : Enemigo(n, v, "Serpiente", 10) {}

    void taunt() override {
        std::cout << nombre << " sisea: 'Ssss... te inyectaré mi veneno mortal...'" << std::endl;
    }
};

#endif


