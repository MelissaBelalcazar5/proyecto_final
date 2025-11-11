//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef PROYECTO_FINAL_ZARTHON_H
#define PROYECTO_FINAL_ZARTHON_H

#pragma once
#include "Enemigo.h"

class Zarthon : public Enemigo {
public:
    Zarthon() : Enemigo("Zarthon el Hechicero", 120, "Jefe Final", 25) {}

    void invocarHechizoOscuro() {
        cout << "🌀 " << getNombre() << " lanza un hechizo oscuro que sacude la torre." << endl;
    }
};
#endif //PROYECTO_FINAL_ZARTHON_H