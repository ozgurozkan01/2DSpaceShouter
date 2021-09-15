#include <iostream>
#include "Game.h"
#include <math.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
Game::Game()
{
    this->initWindow();
    this->initPlayer();
    this->initBullet();
}

Game::~Game()
{
    delete this->window;
}

void Game::initPlayer()
{
    player.setFillColor(sf::Color::Blue);
    player.setRadius(25.f);
}

void Game::initBullet()
{
    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color::Red);
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My First Game", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(75);
}

void Game::movePlayer()
{
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
}

void Game::PlayerCenter()
{
    playerCenter = sf::Vector2f(
            player.getPosition().x + player.getRadius(),
            player.getPosition().y + player.getRadius());

    // MOUSE POSITION
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*window));

    aimDir = mousePosWindow - playerCenter;

    aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x,2) + pow(aimDir.y,2)));

}

void Game::CreateBullet()
{
    for(int i = 0; i< bullets.size(); i++){
        window->draw(bullets[i]);
        window->draw(shape);
    }}

void Game::ShootBullet()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        shape.setPosition(playerCenter);
        currVelocity = aimDirNorm * maxSpeed;

        bullets.push_back(shape);
    }

    for(int i = 0; i< bullets.size(); i++){
        bullets[i].move(currVelocity.x,currVelocity.y);
    }}

const bool Game::running()const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while(window->pollEvent(evnt)){
        switch (evnt.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(evnt.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                    break;
                }

        }
    }
}

void Game::update()
{
    this->pollEvent();
    this->movePlayer();
    this->PlayerCenter();
    this->ShootBullet();
}

void Game::render()
{

    window->clear();
    window->draw(player);
    window->draw(shape);
    CreateBullet();
    window->display();
}









/**
void Game::initVariables()
{
    this->window = nullptr;

}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My First Game!" , sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(123);
}

void Game::initHero()
{
    this->my_hero.setRadius(50.f);
    this->my_hero.setOrigin(25.f,25.f);
    this->my_hero.setPosition(400,300);
    this->my_hero.setFillColor(sf::Color::Red);

}

Game::Game()
{
    this->initWindow();
    this->initHero();
    this->initVariables();

}

Game::~Game()
{
    delete this->window;
}

const bool Game::ReturnOpen() const
{
    this->window->isOpen();
}

void Game::Keyboard_Instruction()
{
    // MOVEMENT CONTROLS
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
        my_hero.move(-15.f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
        my_hero.move(0.f,15.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
        my_hero.move(15.f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
        my_hero.move(0.0f,-15.f);
    }
}

void Game::MousePosition()
{
    this->mousePosition = sf::Mouse::getPosition(*this->window);
}
void Game::pollEvent()
{
    while(this->window->pollEvent(this->evnt))
    {
        switch (evnt.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(evnt.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                    break;
                }

        }
    }
}

void Game::General_update()
{
    this->pollEvent();
    this->Keyboard_Instruction();
}

void Game::General_render()
{
    this->window->clear();
    this->window->display();
}

*/