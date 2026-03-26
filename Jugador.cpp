#include <iostream>
#include <string>
#include <memory>
#include <utility>

#include "Jugador.h"
class Personaje;

Jugador::Jugador(std::string nombre, int vida, int ataque, int defensa, int velocidad) 
: Personajes(  nombre, vida, ataque, defensa, velocidad)
{}
void Jugador::agregarObjeto(std::unique_ptr<Objetos> obj){
    inventario.push_back(std::move(obj));
}
void Jugador::mostrarInventario() const{
    using namespace std;
    //Se puede hacer más bonito, pero no voy a implementar más objetos
    //Voy a dejaar estos 3, no voy a meter más, si lo hago, cambio y busco una solución elegante
    int pocionDeCuracion = 0;
    int pocionDeDaño = 0;
    int pocionBuffDmg = 0;
    for(int i = 0; i < inventario.size(); i++){
        if(inventario[i]->getNombre() == "Pocion de Curacion"){
            pocionDeCuracion++;
        }
        if(inventario[i]->getNombre() == "Poción de Ataque"){
            pocionBuffDmg++;
        }
        if(inventario[i]->getNombre() == "Bomba"){
            pocionDeDaño++;
        }
    }

    cout << "En el inventario tienes: " << endl;
    cout << "1. " << to_string(pocionDeCuracion) << " Pociones de vida" << endl;
    cout << "2. " << to_string(pocionBuffDmg) << " Pociones de ataque" << endl;
    cout << "3. " << to_string(pocionDeDaño) << " Bombas" << endl;
}
bool Jugador::usarObjeto(int indice, Personajes* objetivo){

    // 1. Validar índice
    if (indice < 0 || indice >= static_cast<int>(inventario.size())) {
        std::cout << "Índice de objeto no válido." << std::endl;
        return false;
    }
    // 2. Transferir propiedad del objeto fuera del vector
    std::unique_ptr<Objetos> obj = std::move(inventario[indice]);
    // 3. Usar el objeto sobre el objetivo
    obj->usarObjeto(objetivo);  // aquí se aplica el efecto (p.ej., curación)
    // 4. Eliminar la posición vacía del vector
    inventario.erase(inventario.begin() + indice);

    return true;
}
void Jugador::prepararCombate(){

}