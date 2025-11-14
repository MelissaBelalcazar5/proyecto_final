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
    Juego();                      // Constructor que crea todo el juego
    void iniciar();               // Muestra la introducción y arranca el juego
    void jugar();                 // Recorre todos los niveles uno por uno
};

#endif
