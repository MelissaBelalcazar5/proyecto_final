//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef PROYECTO_FINAL_ENEMIGO_H
#define PROYECTO_FINAL_ENEMIGO_H
#pragma once
#include "Entidad.h"
#include <iostream>
#include <string>
using namespace std;

class Enemigo : public Entidad {
protected:
    string tipo;
    int danioBase;

public:
    Enemigo(string n, int v, string t, int d) : Entidad(n, v), tipo(t), danioBase(d) {}

    string getTipo() { return tipo; }

    void atacar(Entidad* objetivo) override;
};
#endif