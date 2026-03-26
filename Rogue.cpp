#include <iostream>

#include "Jugador.h"
#include "Rogue.h"
#include "Veneno.h"

using namespace std;

Rogue::Rogue(string nombre, int vida, int ataque, int defensa, int velocidad)
    : Jugador(nombre, vida, ataque, defensa, velocidad), primerGolpe(true)
{
    this->agregaHabilidad(Habilidad("Puñalada", 12, 0, 1.0, nullptr));
    this->agregaHabilidad(Habilidad("Estocada", 20, 0, 0.95, nullptr));
    this->agregaHabilidad(Habilidad("Golpe venenoso", 10, 0, 0.95, std::make_unique<Veneno>(3, 5)));
}

int Rogue::recibirDmg(int dmg)
{
    return Personajes::recibirDmg(dmg);
}
void Rogue::mostrarEstado () const
{
    cout << "Hola picaro " << Personajes::getNombre() << endl;

    if (Personajes::estaVivo())
    {
        cout << "Tu estado actual es" << endl;
        cout << Personajes::getVida() << endl;
    }
    else
    {
        cout << "Has muerto, bien jugado" << endl;
    }
}
int Rogue::calcularDmg(Personajes *objetivo)
{
    if (primerGolpe)
    {
        primerGolpe = false;
        return objetivo->recibirDmg(this->getDaño() * 2);
    }
    return objetivo->recibirDmg(this->getDaño());
}
void Rogue::prepararCombate()
{
    primerGolpe = true;
}