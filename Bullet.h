//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_BULLET_H
#define SFML_BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Enemy.h"

class Bullet {
public:

    sf::CircleShape shape;
    sf::Vector2f currVelocity; // anlık hız

    Shooter *owner;
    int index;

    Bullet(sf::Vector2f currVelocity, Shooter *owner, int index)
    {
        this->currVelocity = currVelocity;
        this->owner = owner;
        this->index = index;
    }

    // Player Functions
    void SpawnPlayerBullet(sf::Vector2f mp, sf::Vector2f playerCenter);
    void MovePlayerBullet(std::vec);
    void Move();
    void OnDelete();

    // Enemy Functions
};


#endif //SFML_BULLET_H
