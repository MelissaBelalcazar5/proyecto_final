//
// Created by Melissa Belalcazar on 11/11/25.
//

#ifndef PROYECTO_FINAL_SERPIENTE_H
#define PROYECTO_FINAL_SERPIENTE_H

#pragma once
#include "Enemigo.h"

class Serpiente : public Enemigo {
public:
    Serpiente(string nombre) : Enemigo(nombre, 40, "Serpiente del Pantano", 8) {}

    void siseoVeneno() {
        cout << "🐍 " << getNombre() << " sisea lanzando un chorro de veneno tóxico." << endl;
    }
};



#endif //PROYECTO_FINAL_SERPIENTE_H