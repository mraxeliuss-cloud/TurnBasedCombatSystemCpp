#include "Personaje.h"
#include "Habilidades.h"
#include "Efectos.h"

#include <memory>
#include <iostream>

using namespace std;

Personajes::Personajes(string s, int v, int a, int d, int r) : nombre(s), vida(v), ataqueBase(a), defensa(d), velocidad(r)
{
    std::vector<std::unique_ptr<Efectos>> estados;
}
int Personajes::recibirDmg(int dmg)
{
    vida = vida - (dmg - (0.5 * defensa));
    return vida;
}
int Personajes::calcularDmgPuro(int dmg)
{
    vida = vida - dmg;
    return vida;
}
bool Personajes::estaVivo() const
{
    return this->vida > 0;
}
int Personajes::getVida() const
{
    return vida;
}
int Personajes::getDaño() const
{
    return ataqueBase;
}
bool Personajes::getVeneno() const
{
    return envenenado;
}
bool Personajes::getFuego() const
{
    return ardiendo;
}
int Personajes::getVelocidad() const
{
    return velocidad;
}
string Personajes::getNombre() const
{
    return nombre;
}
std::string Personajes::getNombreHabilidad(int i) const
{
    if (i >= 0 && i < static_cast<int>(skillSet.size()))
        return skillSet[i].getNombre();
    return "";
}
