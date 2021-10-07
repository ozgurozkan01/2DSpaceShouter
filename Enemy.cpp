//
// Created by ozgur on 9/18/2021.
//
#include "Enemy.h"


void Enemy::AssignPosition()
{
    // Center of Enemy
    position = sf::Vector2f(
            shape.getPosition().x + shape.getRadius(),
            shape.getPosition().y + shape.getRadius());
}

void Enemy::InitShape()
{
    shape.setRadius(25.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(10.f);
    Hp = 50.f;
}



