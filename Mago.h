#ifndef MAGO_H
#define MAGO_H

#include "Jugador.h"

class Mago : public Jugador{
    private:
    int fuego;

    public:
    Mago(std::string nombre, int vida, int ataque, int defensa, int velocidad, int fuego);
    void mostrarEstado();
    int calcularDmg(Personajes *objetivo);
    int recibirDmg(int dmg);


};

#endif