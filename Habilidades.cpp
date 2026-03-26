#include "Habilidades.h"

#include "Personaje.h"
#include <iostream>
#include <memory>
#include <random>

std::mt19937 Habilidad::generador(std::random_device{}());

Habilidad::Habilidad(const std::string &nom, int dmg, int cost, double precision, std::unique_ptr<Efectos> efecto)
    : nombre(nom), dañoBase(dmg), coste(cost), punteria(precision), efecto(std::move(efecto)){
    }

int Habilidad::ejecutarAtaque(Personajes *usuario, Personajes *objetivo) const
{
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double tirada = dist(generador);

    if (tirada < punteria)
    {
        if(efecto){
        objetivo->agregaEfecto(efecto->clone());     
        }
        
        std::uniform_real_distribution<double> distanci(0.0, 1.0);
        double crit = distanci(generador);
        if (crit < 0.2)
        {
            int dañoFinal = 2 * dañoBase; // Crítico
            std::cout << "Golpe crítico " << std::endl;
            objetivo->recibirDmg(dañoFinal);
            return dañoFinal;
        }
        else
        {

            int dañoFinal = dañoBase;
            objetivo->recibirDmg(dañoFinal);
            return dañoFinal;
        }
    }
    else
    {
        return 0;
    }
}