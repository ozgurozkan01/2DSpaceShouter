//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H
#include <SFML/Graphics.hpp>


class Bullet;
class Shooter;

#include "Bullet.h"
#include "Shooter.h"

class Player : public Shooter{
public:

    sf::CircleShape shape;

    Player()
    {
        InitShape();
        AssignPosition();
    }

    void InitShape();
    void AssignPosition();
    void PlayerMovement(sf::RenderTarget* target);

};


#endif //SFML_PLAYER_H
