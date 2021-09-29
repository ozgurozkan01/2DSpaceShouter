//
// Created by ozgur on 9/18/2021.
//
#include <SFML/Graphics.hpp>
#include "Player.h"


void Player::PlayerMovement(sf::RenderTarget* target)
{
    // MOVEMENT OF PLAYER
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
        shape.move(-5.f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
        shape.move(0.f, 5.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
        shape.move(5.f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
        shape.move(0.0f, -5.f);
    }

    // BOUNDS OF WINDOW
    if(shape.getGlobalBounds().left <= 0.f)
        shape.setPosition(0.f, shape.getGlobalBounds().top);

    if(shape.getGlobalBounds().left + shape.getGlobalBounds().width >= target->getSize().x)
        shape.setPosition(target->getSize().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);

    if(shape.getGlobalBounds().top <= 0.f)
        shape.setPosition(shape.getGlobalBounds().left, 0.f);

    if(shape.getGlobalBounds().top + shape.getGlobalBounds().height >= target->getSize().y)
        shape.setPosition(shape.getGlobalBounds().left, target->getSize().y - shape.getGlobalBounds().height);


    AssignPosition();

}

void Player::InitShape()
{
    shape.setFillColor(sf::Color::Red);
    shape.setRadius(25.f);
    shape.setPosition(sf::Vector2f(375.f, 450.f));
}


void Player::AssignPosition()
{
    position = sf::Vector2f(
            shape.getPosition().x + shape.getRadius(),
            shape.getPosition().y + shape.getRadius());
}

