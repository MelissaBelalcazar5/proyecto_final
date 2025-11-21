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
#include <fstream>
using namespace std;

Juego::Juego() : jugador("Arion", 100) {

    niveles.push_back(new Nivel("Bosque de los Rugidos",
        "🌲 El viento sopla entre los árboles...",
        new Orco("Goruk, Orco de la Cueva", 50), new PocionVida()));

    niveles.push_back(new Nivel("Pantano del Veneno",
        "💀 El fango burbujea...",
        new Serpiente("Nehra, Serpiente del Pantano", 40), new CristalTiempo()));

    niveles.push_back(new Nivel("Castillo de las Sombras",
        "🏰 Un castillo derruido...",
        new Caballero("Sir Draven, Caballero de las Sombras", 60), new EspadaLuz()));

    niveles.push_back(new Nivel("Lago de los Susurros",
        "🌊 Una niebla pálida flota...",
        new Serpiente("Azhyra, Serpiente del Lago", 80), new AmuletoLuz()));

    niveles.push_back(new Nivel("Torre del Hechicero",
        "🌌 La torre brilla con energía oscura...",
        new Zarthon("Zarthon, Señor del Caos", 100), new LlavePlata()));
}

void Juego::menuPrincipal() {
    cout << "\n✨ RESCATE EN LA TORRE DE CRISTAL ✨\n";
    cout << "1. Nueva partida\n";
    cout << "2. Cargar partida\n";
    cout << "> ";

    int op;
    cin >> op;
    cin.ignore();

    if (op == 1) iniciarNuevaPartida();
    else if (op == 2) {
        if (cargarPartida()) jugarDesde(nivelActual);
        else iniciarNuevaPartida();
    }
}

void Juego::iniciarNuevaPartida() {
    cout << "\nNombre del héroe: ";
    string nombre;
    getline(cin, nombre);

    jugador = Jugador(nombre, 110);
    nivelActual = 0;
    finalDesbloqueado = false;

    jugarDesde(0);
}

void Juego::jugarDesde(int inicio) {

    for (int i = inicio; i < niveles.size(); i++) {

        niveles[i]->iniciarCombate(jugador);
        nivelActual = i;

        if (!jugador.estaViva()) return;

        if (i == 2) {
            cout << "\n🛡️ Obtienes la ARMADURA DE HIERRO (reduce 30% de daño)\n";
            jugador.activarArmadura();
        }

        guardarPartida();

        if (i == 4) {
            cout << "\n🎁 Obtuviste la Llave de Plata.\n";
            cout << "🔑 Debes usarla desde el inventario para rescatar a la princesa.\n";
            guardarPartida();

            menuFinal();

            return;
        }

    }
}

void Juego::activarFinal() {
    cout << "\n🔓 Usas la Llave de Plata para abrir las puertas del castillo...\n\n";
    cout << "👸 \"Gracias mi héroe, " << jugador.getNombre()
         << ", por rescatarme del hechicero...\n"
         << "Te ofrezco este pañuelo como muestra de gratitud.\" 💖\n\n";
    cout << "🏰 El reino ha sido salvado. FIN DEL JUEGO.\n";

    remove("partida_guardada.txt");
}

void Juego::menuFinal() {
    cout << "\n🎉 ¡HAS DERROTADO A ZARTHON! 🎉\n";
    cout << "Para rescatar a la princesa debes usar la Llave de Plata.\n\n";

    int opcion = 0;

    while (opcion != 3) {
        cout << "\n--- MENÚ FINAL ---\n";
        cout << "1. Mostrar inventario\n";
        cout << "2. Usar objeto\n";
        cout << "3. Salir del juego\n";
        cout << "> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugador.mostrarInventario();
                break;

            case 2: {
                jugador.mostrarInventario();
                cout << "Ingrese el índice del objeto a usar: ";
                int idx;
                cin >> idx;
                jugador.usarObjeto(idx);
                break;
            }

            case 3:
                cout << "\n👋 Gracias por jugar.\n";
                return;

            default:
                cout << "❌ Opción inválida.";
        }
    }
}

Juego::~Juego() {
    for (Nivel* n : niveles) delete n;
}

void Juego::guardarPartida() {
    ofstream file("partida_guardada.txt");

    file << jugador.getNombre() << endl;
    file << jugador.getVida() << endl;
    file << jugador.getDanioTotal() << endl;
    file << jugador.tieneAmuleto() << endl;
    file << jugador.tieneArmadura() << endl;
    file << nivelActual << endl;
    file << finalDesbloqueado << endl;

    file << jugador.getInventario().size() << endl;
    for (auto obj : jugador.getInventario())
        file << obj->getNombre() << endl;
}

bool Juego::cargarPartida() {
    ifstream file("partida_guardada.txt");
    if (!file.is_open()) return false;

    string nombre;
    int vida, danioTotal;
    bool tieneAmuleto, tieneArmadura;

    getline(file, nombre);
    file >> vida;
    file >> danioTotal;
    file >> tieneAmuleto;
    file >> tieneArmadura;
    file >> nivelActual;
    file >> finalDesbloqueado;

    int cant;
    file >> cant;
    file.ignore();

    jugador = Jugador(nombre, vida);
    jugador.setDanioBase(danioTotal - 15);

    if (tieneAmuleto) jugador.activarAmuleto();
    if (tieneArmadura) jugador.activarArmadura();

    jugador.limpiarInventario();

    for (int i = 0; i < cant; i++) {
        string nombreObj;
        getline(file, nombreObj);

        if (nombreObj == "Llave de Plata") jugador.agregarObjeto(new LlavePlata());
        else if (nombreObj == "Poción de Vida") jugador.agregarObjeto(new PocionVida());
        else if (nombreObj == "Espada de Luz") jugador.agregarObjeto(new EspadaLuz());
        else if (nombreObj == "Amuleto de la Luz") jugador.agregarObjeto(new AmuletoLuz());
        else if (nombreObj == "Cristal del Tiempo") jugador.agregarObjeto(new CristalTiempo());
    }

    return true;
}




