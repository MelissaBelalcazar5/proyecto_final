//
// Created by Melissa Belalcazar on 12/11/25.
//
#include "Nivel.h"
#include "Jugador.h"
#include "Objeto.h"
#include <iostream>
#include <chrono>
using namespace std;

Nivel::Nivel(string n, string d, Enemigo* e, Objeto* recompensa)
    : nombre(n), descripcion(d), enemigo(e), objetoDelNivel(recompensa) {}

void Nivel::mostrarIntroduccion() {
    cout << "\n🗺️  Nivel: " << nombre << endl;
    cout << descripcion << endl;
    cout << "En este nivel te enfrentarás a " << enemigo->getNombre() << " 💀" << endl;

    enemigo->taunt();

    if (objetoDelNivel != nullptr) {
        cout << "✨ Este nivel contiene un objeto especial: "
             << objetoDelNivel->getNombre() << endl;
    }
}

void Nivel::iniciarCombate(Jugador& jugador) {
    mostrarIntroduccion();

    //Tiempo límite x nivel de 20 segundos
    auto inicio = chrono::steady_clock::now();

    while (jugador.estaViva() && enemigo->estaViva()) {
        auto ahora = chrono::steady_clock::now();
        auto diferencia = chrono::duration_cast<chrono::seconds>(ahora - inicio).count();

        if (diferencia >= 20) {
            cout << "\n⏳ Se acabó el tiempo... ¡" << jugador.getNombre()
                 << " no logró vencer al enemigo!" << endl;
            jugador.recibirDanio(9999);
            return;
        }

        cout << "\n⏱️ Tiempo restante: " << (20 - diferencia) << " segundos\n";

        cout << "\n¿Qué deseas hacer?" << endl;
        cout << "1. Atacar ⚔️" << endl;
        cout << "2. Defender 🛡️" << endl;
        cout << "3. Huir 😨" << endl;
        cout << "4. Moverte (norte/sur/subir/bajar) 🧭" << endl;
        cout << "5. Mostrar inventario 🎒" << endl;
        cout << "6. Usar objeto ✨" << endl;
        cout << "> ";

        int opcion;
        cin >> opcion;

        switch (opcion) {

            case 1:
                jugador.atacar(enemigo);
                break;

            case 2:
                jugador.defender();
                break;

            case 3:
                cout << "😨 " << jugador.getNombre() << " huye del combate." << endl;
                return;

            case 4: {
                string dir;
                cout << "¿A dónde quieres ir? (norte/sur/subir/bajar): ";
                cin >> dir;
                jugador.mover(dir);
                break;
            }

            case 5:
                jugador.mostrarInventario();
                break;

            case 6: {
                jugador.mostrarInventario();
                cout << "Ingresa el índice del objeto a usar: ";
                int idx;
                cin >> idx;
                jugador.usarObjeto(idx);
                break;
            }

            default:
                cout << "❌ Opción no válida." << endl;
                continue;
        }

        if (enemigo->estaViva()) {
            enemigo->atacar(jugador);
        }
    }

    if (jugador.estaViva()) {
        cout << "\n🏆 ¡Has vencido a " << enemigo->getNombre() << "!\n";

        if (objetoDelNivel != nullptr) {
            cout << "🎁 Recibes: " << objetoDelNivel->getNombre() << endl;
            jugador.agregarObjeto(objetoDelNivel);
            objetoDelNivel = nullptr;
        }

        cout << "➡️  Avanzas al siguiente nivel...\n";
    }
    else {
        cout << "\n💀 Has sido derrotado. Fin del juego.\n";
    }
}

