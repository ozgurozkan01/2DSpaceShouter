//
// Created by ozgur on 9/18/2021.
//

#ifndef SFML_ENEMY_H
#define SFML_ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Shooter.h"

class Enemy : public Shooter {
public:
    sf::CircleShape enemy;

    sf::Vector2f enemyCenter;

    std::vector<sf::CircleShape> enemies;

    // Game Logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemy;



    void initEnemy();
    void EnemyCenter();
    void CreatingEnemy(sf::RenderWindow* window);
};


#endif //SFML_ENEMY_H
