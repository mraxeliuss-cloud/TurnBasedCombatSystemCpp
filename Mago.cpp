#include <iostream>
#include <string>

#include "Jugador.h"
#include "Mago.h"

using namespace std;
Mago::Mago(std::string nombre, int vida, int ataque, int defensa, int velocidad, int fuego) : Jugador(nombre, vida, ataque, defensa, velocidad), fuego(fuego)
{
    this->agregaHabilidad(Habilidad("Rayo", 12, 0, 1.0, nullptr));
    this->agregaHabilidad(Habilidad("Bola de fuego", 20, 0, 0.95, nullptr));
}
void Mago::mostrarEstado() const
{
    cout << "Hola Mago " << Personajes::getNombre() << endl;
    cout << "Tu estado actual es: " << endl;
    if (Personajes::estaVivo())
    {
        cout << Personajes::getVida() << endl;
    }
    else
    {
        cout << "Has muerto, bien jugado" << endl;
    }
}
int Mago::recibirDmg(int dmg)
{
    return Personajes::recibirDmg(dmg);
}
int Mago::calcularDmg(Personajes *objetivo)
{
    return objetivo->recibirDmg(this->getDaño() + fuego);
}