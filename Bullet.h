//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_BULLET_H
#define SFML_BULLET_H
#include <SFML/Graphics.hpp>

class Shooter;
#include "Shooter.h"

class Bullet {
public:

    sf::CircleShape shape;
    sf::Vector2f currVelocity; // anlık hız

    Shooter *owner;
    float damage;

    Bullet(sf::Vector2f currVelocity, Shooter * owner)
    {
        this->currVelocity = currVelocity;
        this->owner = owner;
        InitBullet();
    }

    void InitBullet();
    void Move(int bulletIndex);
    void OnDelete(int bulletIndex);


};


#endif //SFML_BULLET_H
