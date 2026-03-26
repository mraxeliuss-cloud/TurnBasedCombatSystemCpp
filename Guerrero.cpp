#include <iostream>

#include "Personaje.h"
#include "Guerrero.h"

using namespace std;

#include "Guerrero.h"

Guerrero::Guerrero(std::string nombre, int vida, int ataque, int defensa, int velocidad, int armadura)
    : Jugador(nombre, vida, ataque, defensa, velocidad), armadura(armadura)
{
    this->agregaHabilidad(Habilidad("Corte", 12, 0, 1.0, nullptr));
    this->agregaHabilidad(Habilidad("Ataque pesado", 20, 0, 0.95, nullptr));
}

void Guerrero::mostrarEstado() const
{
    std::cout << "Hola guerrero " << getNombre() << std::endl;
    std::cout << "Tu estado actual es" << std::endl;
    if (estaVivo())
        std::cout << getVida() << std::endl;
    else
        std::cout << "Has muerto, bien jugado" << std::endl;
}

int Guerrero::calcularDmg(Personajes *objetivo)
{
    // Solo devuelve el daño (sin aplicarlo)
    return getDaño(); // o fórmula más elaborada
}

int Guerrero::recibirDmg(int dmg)
{

    int dmgNeto = 0;
    if (dmg <= armadura)
    {

        cout << "El ataque no supera la armadura" << endl;
    }
    else
    {

        dmgNeto = dmg - armadura;
    }
    return Personajes::recibirDmg(dmgNeto);
}
