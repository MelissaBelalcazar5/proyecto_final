//
// Created by Melissa Belalcazar on 12/11/25.
//

#include "Nivel.h"
#include <iostream>
using namespace std;

Nivel::Nivel(string n, string d, Enemigo* e)
    : nombre(n), descripcion(d), enemigo(e) {}

void Nivel::mostrarIntroduccion() {
    cout << "\n🗺️  Nivel: " << nombre << endl;
    cout << descripcion << endl;
    cout << "En este nivel te enfrentarás a " << enemigo->getNombre() << " 💀" << endl;
}

void Nivel::iniciarCombate(Jugador& jugador) {
    mostrarIntroduccion();

    while (jugador.estaViva() && enemigo->estaViva()) {
        cout << "\n¿Qué deseas hacer?" << endl;
        cout << "1. Atacar ⚔️" << endl;
        cout << "2. Defender 🛡️" << endl;
        cout << "3. Huir 😨" << endl;
        cout << "> ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugador.atacar(enemigo);
                break;
            case 2:
                cout << "🛡️  " << jugador.getNombre() << " se defiende." << endl;
                break;
            case 3:
                cout << "😨 " << jugador.getNombre() << " huye del combate." << endl;
                return;
            default:
                cout << "Opción no válida." << endl;
                continue;
        }

        if (enemigo->estaViva()) {
            enemigo->atacar(&jugador);
        }
    }

    if (jugador.estaViva())
        cout << "\n🏆 ¡Has vencido a " << enemigo->getNombre() << "! Continúa al siguiente nivel.\n";
    else
        cout << "\n💀 Has sido derrotado. Fin del juego.\n";
}
