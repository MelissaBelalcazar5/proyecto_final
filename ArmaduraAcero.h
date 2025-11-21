//
// Created by Melissa Belalcazar on 20/11/25.
//

#ifndef ARMADURA_ACERO_H
#define ARMADURA_ACERO_H

#include "Objeto.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

class ArmaduraAcero : public Objeto {
public:
    ArmaduraAcero()
        : Objeto("Armadura de Acero",
                 "Armadura resistente que reduce el daño recibido.",
                 "Defensivo") {}

    void usar(Jugador& j) override {
        cout << "🛡️ Te equipas la Armadura de Acero. Daño reducido 30% permanentemente.\n";
        j.activarArmadura();   // CORRECTO: sin parámetros
    }
};

#endif



