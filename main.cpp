#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

#include "Combate.h"
#include "Personaje.h"
#include "Jugador.h"
#include "Guerrero.h"
#include "Arquero.h"
#include "Mago.h"
#include "Rogue.h"

using namespace std;

vector<unique_ptr<Personajes>> crearEnemigos()
{
    vector<unique_ptr<Personajes>> enemigos;
    for (int i = 0; i < 25; i++)
    {
        enemigos.push_back(make_unique<Guerrero>("Guerrero", 60, 12, 20, 10, 5));
        enemigos.push_back(make_unique<Arquero>("Arquero", 40, 20, 10, 25, 0.9));
        enemigos.push_back(make_unique<Mago>("Mago", 20, 30, 5, 40, 10));
        enemigos.push_back(make_unique<Rogue>("Rogue", 30, 18, 10, 30));
    }
    random_device rd;
    mt19937 g(rd());
    std::shuffle(enemigos.begin(), enemigos.end(), g);
    return enemigos;
}

unique_ptr<Personajes> elegirPersonaje(string nombre)
{

    unique_ptr<Personajes> jugador;
    cout << nombre << " selecciona tu clase" << endl;
    cout << "1. Guerrero" << endl;
    cout << "2. Arquero" << endl;
    cout << "3. Mago" << endl;
    cout << "4. Rogue" << endl;
    int elegirPersonaje = 0;
    while (elegirPersonaje < 1 || elegirPersonaje > 4)
    {
        cin >> elegirPersonaje;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    switch (elegirPersonaje)
    {
    case 1:
        jugador = make_unique<Guerrero>(nombre, 60, 12, 20, 10, 5);
        break;
    case 2:
        jugador = make_unique<Arquero>(nombre, 40, 20, 10, 25, 0.9);
        break;
    case 3:
        jugador = make_unique<Mago>(nombre, 20, 30, 5, 40, 10);
        break;
    case 4:
        jugador = make_unique<Rogue>(nombre, 30, 18, 10, 30);
        break;

    default:
        cout << "Esta no es una eleccion valida" << endl;
        break;
    }
    return jugador;
}

int main()
{

    cout << "Hola jugador, dime, como te llamas" << endl;
    string nombre;
    cin >> nombre;

    unique_ptr<Personajes> jugador = elegirPersonaje(nombre);
    vector<unique_ptr<Personajes>> enemigos = crearEnemigos();

    unique_ptr<Combate> combate = make_unique<Combate>(move(jugador), move(enemigos));
    combate->Iniciar();

    return 0;
}

#include <SFML/Graphics.hpp>
