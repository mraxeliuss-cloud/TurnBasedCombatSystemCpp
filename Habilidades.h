#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>
#include <random>
#include "Personaje.h"
#include "Efectos.h"

class Habilidad {
private:
    std::string nombre;
    int dañoBase;
    int coste;
    double punteria;
    static std::mt19937 generador;
    std::unique_ptr<Efectos> efecto;
public:
    Habilidad(const std::string& nom, int dmg, int cost = 0, double precision, std::unique_ptr<Efectos> efecto);
    int ejecutarAtaque(Personajes* usuario, Personajes* objetivo) const;
    std::string getNombre() const { return nombre; }
    int getCoste() const { return coste; }
};

#endif