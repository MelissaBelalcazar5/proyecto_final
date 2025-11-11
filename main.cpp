//
// Created by Melissa Belalcazar on 9/11/25.
//
#include <iostream>
#include "Jugador.h"
#include "Orco.h"
#include "Serpiente.h"
#include "Caballero.h"
#include "Zarthon.h"
using namespace std;

void mostrarMenu() {
    cout << "\n¿Qué deseas hacer?\n";
    cout << "1. Atacar 🗡️\n";
    cout << "2. Defender 🛡️\n";
    cout << "3. Huir 😨\n> ";
}

bool combate(Jugador &jugador, Enemigo &enemigo) {
    cout << "\n⚔️ " << enemigo.getTipo() << " aparece: " << enemigo.getNombre() << " ⚔️" << endl;

    while (jugador.estaViva() && enemigo.estaViva()) {
        mostrarMenu();
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugador.atacar(&enemigo);
                break;
            case 2:
                cout << "🛡️ " << jugador.getNombre() << " se defiende y recibe menos daño." << endl;
                enemigo.atacar(&jugador);
                jugador.recibirDanio(-5); // se cura un poco por defender
                break;
            case 3:
                cout << "😨 " << jugador.getNombre() << " huye del combate..." << endl;
                return false; // termina el combate sin ganar
            default:
                cout << "❌ Opción inválida. Pierdes el turno..." << endl;
                break;
        }

        if (enemigo.estaViva()) {
            enemigo.atacar(&jugador);
        }
    }

    return jugador.estaViva();
}

int main() {
    cout << "🌟 BIENVENIDO A: RESCATE EN LA TORRE DE CRISTAL 🌟" << endl;
    cout << "--------------------------------------------------" << endl;

    string nombreJugador;
    cout << "\n👤 Ingresa el nombre de tu héroe: ";
    cin >> nombreJugador;

    Jugador arion(nombreJugador, 100);

    cout << "\n✨ Bienvenido, " << arion.getNombre() << "! Tu aventura comienza..." << endl;

    // NIVEL 1 - ORCO
    Orco orco("Goruk");
    orco.rugirAmenazante();
    if (!combate(arion, orco)) return 0;

    // NIVEL 2 - SERPIENTE
    Serpiente serp("Nehra");
    serp.siseoVeneno();
    if (!combate(arion, serp)) return 0;

    // NIVEL 3 - CABALLERO
    Caballero cab("Sir Draven");
    cab.desafiar();
    if (!combate(arion, cab)) return 0;

    // NIVEL FINAL - ZARTHON
    Zarthon jefe;
    jefe.invocarHechizoOscuro();
    if (!combate(arion, jefe)) return 0;

    cout << "\n🏆 ¡Has derrotado a Zarthon y rescatado a la princesa! 🎉" << endl;
    cout << "Gracias por jugar, " << arion.getNombre() << ". Tu valor será recordado." << endl;

    return 0;
}


//TEMPORAL MAIN