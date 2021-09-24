//
// Created by ozgur on 9/18/2021.
//
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "math.h"
#include <iostream>
void Player::initPlayer()
{
    player.setFillColor(sf::Color::Red);
    player.setRadius(25.f);
    player.setPosition(sf::Vector2f(375.f,450.f));

}

void Player::PlayerMovement(sf::RenderTarget* target)
{
    // MOVEMENT OF PLAYER
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
        player.move(-5.f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
        player.move(0.f,5.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
        player.move(5.f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
        player.move(0.0f,-5.f);
    }

    // BOUNDS OF WINDOW
    if(player.getGlobalBounds().left <= 0.f)
        player.setPosition(0.f, player.getGlobalBounds().top);

    if(player.getGlobalBounds().left + player.getGlobalBounds().width >= target->getSize().x)
        player.setPosition(target->getSize().x - player.getGlobalBounds().width, player.getGlobalBounds().top);

    if(player.getGlobalBounds().top <= 0.f)
        player.setPosition(player.getGlobalBounds().left, 0.f);

    if(player.getGlobalBounds().top + player.getGlobalBounds().height >= target->getSize().y)
        player.setPosition(player.getGlobalBounds().left, target->getSize().y - player.getGlobalBounds().height);

}

void Player::PlayerCenter()
{
    playerCenter = sf::Vector2f(
            player.getPosition().x + player.getRadius(),
            player.getPosition().y + player.getRadius());
}
