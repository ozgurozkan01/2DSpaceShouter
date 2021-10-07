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

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerRestHpBar;

    float playerRestHpBar_x;
    float playerRestHpBar_y;

    // Game Logic
    float enemySpawnTimerMax;
    float enemySpawnTimer;

    int maxEnemy = 3;
    int enemyCounter = 0;

    float enemyBulletTimerMax;
    float enemyBulletTimer;

    float playerHpTimerMax;
    float playerHpTimer;

    float enemiesHpTimerMax;
    float enemiesHpTimer;

    float attackCoolDownMax;
    float attackCoolDown;

    Player* player;

    sf::Vector2f mousePosWindow;

    Game();
    virtual ~Game();

    void InitWindow();
    const bool running() const;
    void pollEvent();
    void MousePosition();
    void DrawBullets();
    void BulletsMove();
    void KillingEnemies();
    void KillingPlayer();
    void DeathEnemyCounter();
    void IncreaseEnemySpawnRate();
    void InitTimerVariables();
    void InitPlayerHpBar();
    void DrawPlayerHpBar();

    // PLAYER
    void CreatePlayer();
    void DrawPlayerBullets();
    void DrawPlayer();
    void PlayerFire();
    void PlayerBulletsMove();
    void HealPlayer();
    void UpdateAttack();
    const bool CanAttack();

    // ENEMY
    void DrawEnemyBullets();
    void CreatingEnemy();
    void DrawEnemies();
    void EnemiesFire();
    void EnemiesBulletsMove();
    void FireEnemiesBullet();
    void HealEnemies();

    // GAME
    void update();
    void render();
};

#endif //SFML_GAME_H
