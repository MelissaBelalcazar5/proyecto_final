//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef PROYECTO_FINAL_ORCO_H
#define PROYECTO_FINAL_ORCO_H

#pragma once
#include "Enemigo.h"

class Orco : public Enemigo {
public:
    Orco(string nombre) : Enemigo(nombre, 50, "Orco de la Cueva", 10) {}

    void rugirAmenazante() {
        cout << "🗣️ " << getNombre() << " ruge con furia, levantando su hacha oxidada." << endl;
    }
};
#endif //PROYECTO_FINAL_ORCO_H