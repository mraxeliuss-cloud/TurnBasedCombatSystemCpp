#include <iostream>
#include <random>

#include "Jugador.h"
#include "Arquero.h"

// Definimos un generador estático para comparar contra la precisión
std::mt19937 Arquero::generador(std::random_device{}());

Arquero::Arquero(std::string nombre, int vida, int ataque, int defensa, int velocidad, double precision)
    : Jugador(nombre, vida, ataque, defensa, velocidad), precision(precision)
{
    this->agregaHabilidad(Habilidad("Flecha", 12, 0, 1.0));
    this->agregaHabilidad(Habilidad("Flecha pesada", 20, 0, 0.95));
}
int Arquero::calcularDmg(Personajes *objetivo)
{
    // Creamos un número aleatorio entre 0 y 1
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double tirada = dist(generador);

    if (tirada < precision)
    {
        return Personajes::getDaño();
    }
    else
    {
        return 0;
    }
}
void Arquero::mostrarEstado() const
{

    std::cout << "Hola Arquero " << Personajes::getNombre() << std::endl;
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