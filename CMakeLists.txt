cmake_minimum_required(VERSION 3.23)
project(proyecto_final)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(proyecto_final
        Entidad.cpp
        Entidad.h
        Jugador.cpp
        Jugador.h
        main.cpp
        Enemigo.cpp
        Enemigo.h
        Orco.cpp
        Orco.h
        Serpiente.cpp
        Serpiente.h
        Caballero.cpp
        Caballero.h
        Zarthon.cpp
        Zarthon.h
        Nivel.cpp
        Nivel.h
        Juego.cpp
        Juego.h
        Objeto.cpp
        Objeto.h
        PocionVida.cpp
        PocionVida.h
        LlavePlata.cpp
        LlavePlata.h
        EspadaLuz.cpp
        EspadaLuz.h
        AmuletoLuz.cpp
        AmuletoLuz.h
        CristalTiempo.cpp
        CristalTiempo.h
        ArmaduraAcero.cpp
        ArmaduraAcero.h
)
