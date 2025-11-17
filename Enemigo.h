//
// Created by Melissa Belalcazar on 11/11/25.
//
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Entidad.h"
#include <iostream>

class Jugador;

class Enemigo : public Entidad {
protected:
    std::string tipo;
    int dano;

public:
    Enemigo(const std::string& n, int v, const std::string& t, int d)
        : Entidad(n, v), tipo(t), dano(d) {}

    virtual ~Enemigo() = default;

    std::string getTipo() const { return tipo; }

    virtual void taunt() {
        std::cout << nombre << " te observa con hostilidad..." << std::endl;
    }

    virtual void atacar(Jugador& jugador);
};

#endif


