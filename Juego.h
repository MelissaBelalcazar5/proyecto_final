//
// Created by Melissa Belalcazar on 12/11/25.
//

#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Jugador.h"
#include "Nivel.h"
using namespace std;

class Juego {
private:
    Jugador jugador;
    vector<Nivel*> niveles;

public:
    Juego();
    ~Juego();
    void iniciar();
    void jugar();
};

#endif

