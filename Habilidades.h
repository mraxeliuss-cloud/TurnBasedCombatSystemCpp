#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>
#include <memory>
#include <random>

#include "Efectos.h"

class Personajes;
class Habilidad {
private:
    std::string nombre;
    int dañoBase;
    int coste;
    double punteria;
    static std::mt19937 generador;
    std::unique_ptr<Efectos> efecto;
public:
    Habilidad(const std::string& nom, int dmg, int cost, double precision, std::unique_ptr<Efectos> efecto);
    int ejecutarAtaque(Personajes* usuario, Personajes* objetivo) const;
    std::string getNombre() const { return nombre; }
    int getCoste() const { return coste; }
};

#endif