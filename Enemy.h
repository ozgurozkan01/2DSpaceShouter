//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_ENEMY_H
#define SFML_ENEMY_H

#include <SFML/Graphics.hpp>

class Shooter;

#include "Shooter.h"

class Enemy : public Shooter{
public:
    sf::CircleShape shape;
    float Hp;

    Enemy()
    {
        InitShape();
    }

    void InitShape();
    void AssignPosition();

};


#endif //SFML_ENEMY_H
