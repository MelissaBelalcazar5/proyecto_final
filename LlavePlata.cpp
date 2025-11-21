//
// Created by Melissa Belalcazar on 17/11/25.
//

#include "LlavePlata.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

void LlavePlata::usar(Jugador& j) {
    cout << "🔑 Inserta la Llave de Plata en la puerta del castillo...\n";
    cout << "🚪 La puerta se abre con un brillo mágico.\n\n";

    cout << "👸 La princesa aparece envuelta en una luz dorada y dice:\n";
    cout << "   \"Gracias mi héroe, " << j.getNombre()
         << ", por rescatarme del hechicero.\n";
    cout << "    Acepta este pañuelo como símbolo de mi gratitud.\"\n\n";

    cout << "🏰 ¡Has completado el juego! El reino vuelve a la paz.\n";
}

