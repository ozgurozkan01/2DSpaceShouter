#include <iostream>
#include "Game.h"

void Game::InitWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(75);
}

void Game::InitPlayerHpBar()
{
    playerHpBar.setSize(sf::Vector2f(250.f,20.f));
    playerHpBar.setFillColor(sf::Color::Red);
    playerHpBar.setPosition(50.f,10.f);

    playerRestHpBar_x = 250.f;
    playerRestHpBar_y = 20.f;

    playerRestHpBar.setSize(sf::Vector2f(playerRestHpBar_x, playerRestHpBar_y));
    playerRestHpBar.setFillColor(sf::Color::Green);
    playerRestHpBar.setPosition(50.f, 10.f);
}

void Game::MousePosition()
{
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*window));
}

void Game::CalcDeltaTime()
{
    time = clock.restart();
    deltaTime = time.asSeconds();
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
    this->InitWindow();
    this->InitPlayerHpBar();
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

void Game::Timer()
{
    enemySpawnTimer += deltaTime;

    enemyBulletTimer += deltaTime;

    playerHpTimer += deltaTime;

    enemiesHpTimer += deltaTime;
}

void Game::CreatingEnemy()
{
    if(enemies.size() < maxEnemy)
    {
        auto enemy = new Enemy();

        if(enemySpawnTimer >= 3.f)
        {
            enemy->shape.setPosition(
                    static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy->shape.getGlobalBounds().width)),
                    static_cast<float>(rand() % static_cast<int>(window->getSize().y - enemy->shape.getGlobalBounds().height)));

            enemy->AssignPosition();
            enemies.push_back(enemy);

            enemySpawnTimer = 0;
        }
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
    player = new Player(350.f);
}

void Game::DrawPlayerBullets()
{
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

    if(enemyBulletTimer >= 1.f)
    {
        EnemiesFire();
        enemyBulletTimer = 0;
    }
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

void Game::KillingEnemies()
{

    for(int i = 0; i < player->bullets.size(); i++)
    {
        for(int j = 0; j < enemies.size(); j++)
        {
            if(player->bullets[i]->shape.getGlobalBounds().intersects(enemies[j]->shape.getGlobalBounds()))
            {
                    player->bullets.erase(player->bullets.begin() + i);
                    enemies[j]->Hp -= player->damage;
            }
        }
    }

}

void Game::KillingPlayer()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        for(int j = 0; j < enemies[i]->bullets.size(); j++)
        {
            if ((player->shape.getGlobalBounds().intersects(enemies[i]->bullets[j]->shape.getGlobalBounds())))
            {
                playerRestHpBar_x -= enemies[i]->bullets[j]->damage;
                playerRestHpBar.setSize(sf::Vector2f(playerRestHpBar_x, playerRestHpBar_y));

                enemies[i]->bullets.erase(enemies[i]->bullets.begin() + j);
            }

            if(playerRestHpBar_x == 0)
            {
                this->window->close();
                break;
            }
        }
    }
}

void Game::UpdatePlayerHp()
{
    if(playerHpTimer >= 5.f)
    {
        if(playerRestHpBar_x <= 250.f)

            playerRestHpBar_x +=25.f;

            if(playerRestHpBar_x > 250.f)
            {
                playerRestHpBar_x = 250.f;
            }

            playerRestHpBar.setSize(sf::Vector2f(playerRestHpBar_x, playerRestHpBar_y));
            
            playerHpTimer = 0.f;
    }

}

void Game::UpdateEnemiesHp()
{
    if(enemiesHpTimer >= 1.f)
    {
        for(int i = 0; i < enemies.size(); i++)
        {
            enemies[i]->Hp += 3.f;

            if(enemies[i]->Hp > 50.f)
                enemies[i]->Hp = 50.f;

        }
        enemiesHpTimer = 0.f;
    }
}

void Game::UpdateEnemiesColor()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i]->Hp >= 35 && enemies[i]->Hp <= 50)
        {
            enemies[i]->shape.setFillColor(sf::Color::Green);
        }

        else if(enemies[i]->Hp < 35 && enemies[i]->Hp >= 20)
        {
            enemies[i]->shape.setFillColor(sf::Color::Yellow);
        }

        else if(enemies[i]->Hp < 20 && enemies[i]->Hp > 0)
        {
            enemies[i]->shape.setFillColor(sf::Color::Red);
        }

        else if(enemies[i]->Hp <= 0)
        {
            enemies.erase(enemies.begin() + i);
            DeathEnemyCounter();
        }

    }
}

void Game::DeathEnemyCounter()
{
    enemyCounter += 1;

    if(enemyCounter == maxEnemy)
    {
        maxEnemy += 1;
        enemyCounter = 0;
        player->damage += 2.f;
    }
}

const bool Game::CanAttack()
{
    if(this->attackCoolDown >= 0.5f)
    {
        attackCoolDown = 0.f;
        return true;
    }

    return false;
}

void Game:: UpdateAttack()
{
    if(this->attackCoolDown < 0.5f)
        this->attackCoolDown += deltaTime;

}

void Game::DrawPlayerHpBar()
{
    this->window->draw(playerHpBar);
    this->window->draw(playerRestHpBar);
}

void Game::update()
{
    this->Timer();
    this->pollEvent();
    this->MousePosition();
    this->CreatingEnemy();
    this->BulletsMove();
    this->KillingEnemies();
    this->KillingPlayer();
    this->UpdatePlayerHp();
    this->UpdateEnemiesHp();
    this->UpdateAttack();
    this->UpdateEnemiesColor();

    //Player
    this->player->PlayerMovement(window, deltaTime);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && CanAttack())
    {
        PlayerFire();
    }

    // Enemy
    FireEnemiesBullet();
}

void Game::render()
{
    this->window->clear();

    this->DrawPlayer();
    this->DrawEnemies();
    this->DrawBullets();
    this->DrawPlayerHpBar();
    this->window->draw(text);

    this->window->display();
}
























