#include <iostream>
#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My First Game", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(75);
}

void Game::MousePosition()
{
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*window));
}

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

Game::Game()
{
    pG.initPlayer();
    eG.initEnemy();
    this->initWindow();
    MousePosition();

}

Game::~Game()
{
    delete this->window;
}


void Game::update()
{
    this->pollEvent();
    MousePosition();

    pG.PlayerMovement(window);
    pG.PlayerCenter();

    bG.SpawnPlayerBullet(mousePosWindow, pG.playerCenter);
    bG.MovePlayerBullet();
    // ENEMY

    this->eG.EnemyCenter();
    this->eG.CreatingEnemy(this->window);

}

void Game::render()
{
    this->window->clear();

    window->draw(pG.player);

    for(int i = 0; i < eG.enemies.size(); i++)
    {
        window->draw(eG.enemies[i]);
    }

    for(int i = 0; i < bG.bullets.size(); i++)
    {
        window->draw(bG.bullets[i]);
    }

    this->window->display();
}
