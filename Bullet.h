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


class Bullet {
public:
    sf::CircleShape shape;
    sf::Vector2f currVelocity; // anlık hız
    float maxSpeed;

    Bullet(float radius = 5.f):currVelocity(0.f,0.f), maxSpeed(10.f)
    {
        this->shape.setRadius(radius);
        this->shape.setFillColor(sf::Color::White);
    }
};


#endif //SFML_BULLET_H
