//
// Created by Melissa Belalcazar on 12/11/25.
//

#include "Juego.h"
#include "Orco.h"
#include "Serpiente.h"
#include "Caballero.h"
#include "Zarthon.h"
#include <iostream>
using namespace std;

Juego::Juego() : jugador("Arion", 100) {

    // Nivel 1
    niveles.push_back(new Nivel(
        "Bosque de los Rugidos",
        "🌲 El viento sopla entre los árboles y los rugidos se escuchan a lo lejos...",
        new Orco("Goruk (Orco de la Cueva)", 50)
    ));

    // Nivel 2
    niveles.push_back(new Nivel(
        "Pantano del Veneno",
        "💀 El suelo burbujea y un olor a veneno llena el aire. Cuidado donde pisas...",
        new Serpiente("Nehra (Serpiente del Pantano)", 40)
    ));

    // Nivel 3
    niveles.push_back(new Nivel(
        "Castillo de las Sombras",
        "🏰 Un castillo en ruinas rodeado de silencio... un caballero oscuro te espera.",
        new Caballero("Sir Draven (Caballero de las Sombras)", 60)
    ));

    // Nivel Final
    niveles.push_back(new Nivel(
        "La Torre del Hechicero",
        "🌌 Subes la torre. Las paredes brillan con símbolos mágicos. Zarthon te espera al final...",
        new Zarthon("Zarthon el Hechicero", 120)
    ));
}

void Juego::iniciar() {
    cout << "✨ BIENVENIDO AL JUEGO: RESCATE EN LA TORRE DE CRISTAL ✨" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "👑 Tu misión es rescatar a la princesa antes de que Zarthon la sacrifique..." << endl;
    cout << "⚔️  Prepárate, valiente guerrero." << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nIngresa el nombre de tu héroe: ";
    string nombre;
    getline(cin, nombre);
    if (!nombre.empty()) jugador = Jugador(nombre, 100);

    cout << "\n🧝‍♂️ Bienvenido, " << jugador.getNombre() << ". Tu aventura comienza..." << endl;
    jugar();
}

void Juego::jugar() {
    for (int i = 0; i < niveles.size(); i++) {
        cout << "\n==============================" << endl;
        cout << "    🌟 Nivel " << i + 1 << " de " << niveles.size() << " 🌟" << endl;
        cout << "==============================" << endl;

        niveles[i]->iniciarCombate(jugador);

        if (!jugador.estaViva()) {
            cout << "\n💀 " << jugador.getNombre() << " ha caído en batalla..." << endl;
            cout << "La princesa sigue prisionera en la torre. 💔" << endl;
            return;
        }

        cout << "\n✅ Has superado el nivel. Te preparas para continuar...\n";
    }

    cout << "\n🎉 ¡FELICIDADES, " << jugador.getNombre() << "! Has derrotado a Zarthon y rescatado a la princesa 👸💖" << endl;
    cout << "🏰 El reino vuelve a la paz." << endl;
}
