//
// Created by ozgur on 9/18/2021.
//
#include "Enemy.h"
#include <iostream>
void Enemy::initEnemy()
{
    enemySpawnTimerMax = 500.f;
    enemySpawnTimer = enemySpawnTimerMax;
    maxEnemy = 3;

    enemy.setRadius(25.f);
    enemy.setFillColor(sf::Color::Cyan);
    enemy.setOutlineColor(sf::Color::Red);
    enemy.setOutlineThickness(10.f);
}

void Enemy::EnemyCenter()
{
    // Center of Enemy
    enemyCenter = sf::Vector2f(
            enemy.getPosition().x + enemy.getRadius(),
            enemy.getPosition().y + enemy.getRadius());
}

void Enemy::CreatingEnemy(sf::RenderWindow* window)
{
    if(enemies.size() < maxEnemy)
    {
        if(enemySpawnTimer >= enemySpawnTimerMax)
        {
            // Spawn enemy
            enemy.setPosition(
                    static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getGlobalBounds().width)),
                    static_cast<float>(rand() % static_cast<int>(window->getSize().y - enemy.getGlobalBounds().height)));

            enemies.push_back(enemy);

            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }
}



