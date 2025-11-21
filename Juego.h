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
    int nivelActual = 0;
    bool finalDesbloqueado = false;

public:
    Juego();
    ~Juego();

    void menuPrincipal();
    void iniciarNuevaPartida();
    void reanudarPartida();
    void menuFinal();

    void jugarDesde(int inicio);

    void guardarPartida();
    bool cargarPartida();

    void activarFinal();
    bool finalListo() const { return finalDesbloqueado; }
};


#endif

