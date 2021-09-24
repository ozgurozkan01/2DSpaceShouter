//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "vector"
#include "Bullet.h"

class Player : public Shooter{
public:

    sf::CircleShape player;
    sf::Vector2f playerCenter;

    void initPlayer();

    void PlayerCenter();
    void PlayerMovement(sf::RenderTarget* target);

    void Shooting(sf::Vector2f mp);
    void MoveBullets();

};


#endif //SFML_PLAYER_H
