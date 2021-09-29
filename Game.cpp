#include <iostream>
#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(75);
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
    this->initWindow();
    this->CreatePlayer();
    this->CreatingEnemy();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    for(int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}

void Game::DrawPlayer()
{
    window->draw(player->shape);
}

void Game::CreatingEnemy()
{
    if(enemies.size() < maxEnemy)
    {

        auto enemy = new Enemy();

        if(enemySpawnTimer >= enemySpawnTimerMax)
        {
            // Spawn shape
            enemy->shape.setPosition(
                    static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy->shape.getGlobalBounds().width)),
                    static_cast<float>(rand() % static_cast<int>(window->getSize().y - enemy->shape.getGlobalBounds().height)));

            enemy->AssignPosition();
            enemies.push_back(enemy);


            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }
}

void Game::DrawEnemies()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        window->draw(enemies[i]->shape);
    }
}

void Game::DrawEnemyBullets()
{
    for(int j = 0; j < enemies.size(); j++)
    {
        for(int i = 0; i < enemies[j]->bullets.size(); i++)
        {
            window->draw(enemies[j]->bullets[i]->shape);
        }
    }
}

void Game::CreatePlayer()
{
    player = new Player();

}

void Game::DrawPlayerBullets() {

    for(int i = 0; i < player->bullets.size(); i++)
    {
        window->draw(player->bullets[i]->shape);
    }
}

void Game::DrawBullets()
{
    DrawEnemyBullets();
    DrawPlayerBullets();
}

void Game::PlayerFire()
{
    player->Fire(mousePosWindow);
}

void Game::EnemiesFire()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->Fire(player->position);
    }
}

void Game::FireEnemiesBullet()
{

    if(enemyBulletTimer >= enemyBulletTimerMax)
    {
        EnemiesFire();
        enemyBulletTimer = 0.f;
    }
    else
        enemyBulletTimer += 1.f;
}


void Game::PlayerBulletsMove()
{
    for(int i = 0; i < player->bullets.size(); i++)
    {
        player->bullets[i]->Move(i);
    }
}

void Game::EnemiesBulletsMove()
{

    for(int i = 0; i < enemies.size(); i++)
    {
        for(int j = 0; j < enemies[i]->bullets.size(); j++)
        {
            enemies[i]->bullets[j]->Move(j);
        }
    }

}
void Game::BulletsMove()
{
    PlayerBulletsMove();
    EnemiesBulletsMove();
}

void Game::update()
{
    this->pollEvent();
    this->MousePosition();
    this->BulletsMove();

    //Player
    this->player->PlayerMovement(window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        PlayerFire();
    }

    // Enemy
    this->CreatingEnemy();
    FireEnemiesBullet();
}

void Game::render()
{
    this->window->clear();

    this->DrawPlayer();
    this->DrawEnemies();
    this->DrawBullets();

    this->window->display();
}












