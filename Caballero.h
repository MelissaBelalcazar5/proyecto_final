//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef PROYECTO_FINAL_CABALLERO_H
#define PROYECTO_FINAL_CABALLERO_H

#pragma once
#include "Enemigo.h"

class Caballero : public Enemigo {
public:
    Caballero(string nombre) : Enemigo(nombre, 70, "Caballero Oscuro", 15) {}

    void desafiar() {
        cout << "🛡️ " << getNombre() << " levanta su espada brillante y grita: '¡Por el honor de Zarthon!'" << endl;
    }
};
#endif //PROYECTO_FINAL_CABALLERO_H