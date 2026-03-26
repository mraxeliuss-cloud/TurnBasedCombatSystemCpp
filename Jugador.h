#ifndef JUGADOR_H
#define JUGADOR_H

#include <memory>
#include <vector>

#include "Personaje.h"
#include "Objetos.h"


class Jugador : public Personajes
{

private:

    std::vector<unique_ptr<Objetos>> inventario;

public:

    Jugador(std::string nombre, int vida, int ataque, int defensa, int velocidad);

    int getInventario() {return inventario.size();}
    void agregarObjeto(std::unique_ptr<Objetos> obj);
    void mostrarInventario() const;
    bool usarObjeto(int indice, Personajes* objetivo);
    int getNumeroObjetos() const {return inventario.size();}
    virtual void prepararCombate();

};

#endif