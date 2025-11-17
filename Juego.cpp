//
// Created by Melissa Belalcazar on 12/11/25.
//
#include "Juego.h"
#include "Orco.h"
#include "Serpiente.h"
#include "Caballero.h"
#include "Zarthon.h"

#include "PocionVida.h"
#include "LlavePlata.h"
#include "EspadaLuz.h"
#include "AmuletoLuz.h"
#include "CristalTiempo.h"

#include <iostream>
using namespace std;

Juego::Juego() : jugador("Arion", 100) {
    //NIVEL 1 – BOSQUE
    niveles.push_back(new Nivel(
        "Bosque de los Rugidos",
        "🌲 El viento sopla entre los árboles... Los rugidos resuenan entre la maleza.",
        new Orco("Goruk, Orco de la Cueva", 50),
        new PocionVida()
    ));

    //NIVEL 2 – PANTANO
    niveles.push_back(new Nivel(
        "Pantano del Veneno",
        "💀 El fango burbujea... un veneno denso se respira en el aire.",
        new Serpiente("Nehra, Serpiente del Pantano", 40),
        new LlavePlata()
    ));

    //NIVEL 3 – CASTILLO
    niveles.push_back(new Nivel(
        "Castillo de las Sombras",
        "🏰 Un castillo derruido... ecos de metal chocan dentro.",
        new Caballero("Sir Draven, Caballero de las Sombras", 60),
        new EspadaLuz()
    ));

    //NIVEL 4 – LAGO
    niveles.push_back(new Nivel(
        "Lago de los Susurros",
        "🌊 Una niebla pálida flota sobre aguas oscuras...",
        new Serpiente("Azhyra, Serpiente del Lago", 80),
        new AmuletoLuz()
    ));

    //NIVEL FINAL – TORRE
    niveles.push_back(new Nivel(
        "Torre del Hechicero",
        "🌌 La cima de la torre brilla con energía oscura. Zarthon te espera...",
        new Zarthon("Zarthon, Señor del Caos", 120),
        new CristalTiempo()
    ));
}

void Juego::iniciar() {
    cout << "✨ BIENVENIDO A: RESCATE EN LA TORRE DE CRISTAL ✨\n";
    cout << "-------------------------------------------------------\n";
    cout << "👑 Tu mision: rescatar a la princesa antes del ritual oscuro.\n";
    cout << "⚔️  Sólo los valientes pueden salvar al reino.\n";
    cout << "-------------------------------------------------------\n";

    cout << "\nIngresa el nombre de tu heroe: ";
    string nombre;
    getline(cin, nombre);

    if (!nombre.empty())
        jugador = Jugador(nombre, 100);

    cout << "\n🧙‍♂️ Suerte, " << jugador.getNombre() << "... Tu aventura comienza.\n";

    jugar();
}

void Juego::jugar() {
    for (int i = 0; i < niveles.size(); i++) {

        cout << "\n\n=====================================\n";
        cout << "        🌟 NIVEL " << i + 1 << " DE " << niveles.size() << " 🌟\n";
        cout << "=====================================\n\n";

        niveles[i]->iniciarCombate(jugador);

        if (!jugador.estaViva()) {
            cout << "\n💀 " << jugador.getNombre() << " cayo en batalla...\n";
            cout << "La princesa queda perdida en la torre... 💔\n";
            return;
        }

        cout << "\n✅ Has superado el nivel. Te preparas para avanzar...\n";
    }

    //FINAL DEL JUEGO
    cout << "\n🎉 ¡FELICIDADES, " << jugador.getNombre() << "! 🎉\n";
    cout << "Has derrotado a Zarthon y destruido su magia oscura.\n\n";

    cout << "👸 La princesa aparece entre una luz dorada y te dice:\n";
    cout << "   \"Gracias por rescatarme... sabía que vendrías por mí.\"\n\n";

    cout << "🏰 El reino finalmente vuelve a la paz.\n";
}
Juego::~Juego() {
    for (Nivel* n : niveles) {
        delete n;
    }
}



