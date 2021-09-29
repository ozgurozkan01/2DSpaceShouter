#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    sf::RenderWindow* window;
    sf::Event evnt;

    std::vector<Enemy*> enemies;

    // Game Logic
    float enemySpawnTimerMax = 250.f;
    float enemySpawnTimer;

    int maxEnemy = 3;

    float enemyBulletTimerMax = 100.f;
    float enemyBulletTimer;


    Player* player;

    sf::Vector2f mousePosWindow;

    void initWindow();

    Game();
    virtual ~Game();

    const bool running() const;
    void pollEvent();
    void MousePosition();
    void DrawBullets();
    void BulletsMove();

    // PLAYER
    void CreatePlayer();
    void DrawPlayerBullets();
    void DrawPlayer();
    void PlayerFire();
    void PlayerBulletsMove();

    // ENEMY
    void DrawEnemyBullets();
    void CreatingEnemy();
    void DrawEnemies();
    void EnemiesFire();
    void EnemiesBulletsMove();
    void FireEnemiesBullet();

    // GAME
    void update();
    void render();
};

#endif //SFML_GAME_H
